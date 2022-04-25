/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node * insert(struct node *root, int key){
    if(root==NULL) return newNode(key);
    
    if(root->key<key) root->left = insert(root->left, key);
    else  root->right = insert(root->right, key);
    
    return root;
}

struct node * minValueNode(struct node * root){
   struct node * temp= root;
   while(temp->left!=NULL) temp = temp->left;
   return temp;
}

struct node * deleteNode(struct node * root, int key){
    if (root==NULL) return root;
    
    if(root->key<key) root->left = deleteNode(root->left, key);
    else if (root->key>key) root->right = deleteNode(root->right, key);
    else{
        if(root->left==NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else{
           struct node *temp = minValueNode(temp->right) ;
           root->key = temp->key;
           root->right = deleteNode(temp, temp->key);
        }
    }
    return root;
}

int main() {
  struct node *root = NULL;
  root = insert(root, 8);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 6);
  root = insert(root, 7);
  root = insert(root, 10);
  root = insert(root, 14);
  root = insert(root, 4);

  printf("Inorder traversal: ");
  inorder(root);

  printf("\nAfter deleting 10\n");
  root = deleteNode(root, 10);
  printf("Inorder traversal: ");
  inorder(root);
}