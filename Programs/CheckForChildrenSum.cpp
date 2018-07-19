/* Program to check children sum property */
#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
typedef node Node;
/* returns 1 if children sum property holds for the given
    node and both of its children*/
bool isSumProperty(Node* root){
  if(!root || (!root->left && !root->right)){
    return true;
  }else{
    int children_sum = 0;
    if(root->left != NULL){
      children_sum += root->left->data;
    }
    if(root->right!=NULL){
      children_sum += root->right->data;
    }
    if(children_sum == root->data){
      return isSumProperty(root->left) && isSumProperty(root->right);
    }
  }
}
 
/*
 Helper function that allocates a new node
 with the given data and NULL left and right
 pointers.
*/
struct node* newNode(int data)
{
  struct node* node =
      (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
 
/* Driver program to test above function */
int main()
{
  struct node *root  = newNode(10);
  root->left         = newNode(8);
  root->right        = newNode(2);
  root->left->left   = newNode(3);
  root->left->right  = newNode(5);
  root->right->right = newNode(2);
  if(isSumProperty(root))
    printf("The given tree satisfies the children sum property ");
  else
    printf("The given tree does not satisfy the children sum property ");
 
  getchar();
  return 0;
}