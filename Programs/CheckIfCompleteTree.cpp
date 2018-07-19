// A program to check
#include<bits/stdc++.h>
#include<queue>
#define MAX_Q_SIZE 500
using namespace std; 

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

/* Driver program to test above functions*/
bool isCompleteBT(node* root){
  queue<node*> q;
  q.push(root);
  bool leaf_meet = false;
  while(!q.empty()){
    int size = q.size();
    while(size--){
      node* cur = q.front();q.pop();
      if(cur->left){
        if(leaf_meet)
          return false;
        q.push(cur->left);
      }else{
        leaf_meet = true;
      }
      if(cur->right){
        if(leaf_meet)
          return false;
        q.push(cur->right);
      }else{
        leaf_meet = true;
      }
    }
  }
  return true;
}
int main()
{
   /* Let us construct the following Binary Tree which
      is not a complete Binary Tree
            1
          /   \
         2     3
        / \     \
       4   5     6
    */
 
  struct node *root  = newNode(1);
  root->left         = newNode(2);
  root->right        = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  root->right->left = newNode(6);
 
  if ( isCompleteBT(root) == true )
      printf ("Complete Binary Tree");
  else
      printf ("NOT Complete Binary Tree");
 
  return 0;
}