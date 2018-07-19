#include<bits/stdc++.h>
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
typedef node Node;
/* This function is used to increment left subtree */
void increment(struct node* node, int diff);
 
/* Helper function that allocates a new node
 with the given data and NULL left and right
 pointers. */
struct node* newNode(int data);
 
/* This function changes a tree to to hold children sum
   property */
 
 
/* This function is used to increment subtree by diff */
void increment(struct node* node, int diff)
{
  /* IF left child is not NULL then increment it */
  if(node->left != NULL)
  {
    node->left->data = node->left->data + diff;
 
    // Recursively call to fix the descendants of node->left
    increment(node->left, diff);  
  }
  else if (node->right != NULL) // Else increment right child
  {
    node->right->data = node->right->data + diff;
 
    // Recursively call to fix the descendants of node->right
    increment(node->right, diff);
  }
}
 
/* Given a binary tree, printInorder() prints out its
   inorder traversal*/
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
 
  /* first recur on left child */
  printInorder(node->left);
 
  /* then print the data of node */
  printf("%d ", node->data);
 
  /* now recur on right child */
  printInorder(node->right);
}
 
/* Helper function that allocates a new node
 with the given data and NULL left and right
 pointers. */

Node* downFlow(Node* root, int increase){
  if(root == NULL || (root->left == NULL && root->right == NULL)){
    return root;
  }else{
    if(root->left != NULL){
      root->left->data += increase;
      root->left = downFlow(root->left, increase);
      return root;
    }else if(root->right != NULL){
      root->right->data += increase;
      root->right = downFlow(root->right, increase);
      return root;
    }else{
      return NULL;
    }
  }
}

Node* convertTree(node* root){
  if(root==NULL || (root->left == NULL && root->right == NULL)){
    return root;
  }else{
    root->left = convertTree(root->left);
    root->right = convertTree(root->right);
    int children_sum = 0;
    if(root->left != NULL){
      children_sum += root->left->data;
    }
    if(root->right != NULL){
      children_sum += root->right->data;
    }
    if(root->data > children_sum){
      return downFlow(root,  root->data - children_sum);
    }else{
      root->data = children_sum;
      return root;
    }
  }
}

struct node* newNode(int data)
{
  struct node* node =
      (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
 
/* Driver program to test above functions */
int main()
{
  struct node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);
 
  printf("\n Inorder traversal before conversion ");
  printInorder(root);
 
  convertTree(root);
 
  printf("\n Inorder traversal after conversion ");
  printInorder(root);
 
  getchar();
  return 0;
}