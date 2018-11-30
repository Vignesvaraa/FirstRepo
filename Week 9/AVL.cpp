#include<bits/stdc++.h>
#include<stdio.h> 
#include<stdlib.h> 
  using namespace std;
 
struct Node 
{ 
	char month[20];
    int key; 
    struct Node *left; 
    struct Node *right; 
    int height; 

}; 
int monthgen(char month[])
{
	
	
		if(month=="january" )
			 return 1;
			  
		if(month=="february"	)
			 return 2;
			  
		if(month=="march" )
			 return 3;
			  
		if(month=="april" )
			 return 4;
			  
		if(month=="may"	)
			 return 5;
			  
		if(month=="june" )
			 return 6;
			  
		if(month=="july" )
			 return 7;
			  
		if(month=="august" )
			 return 8;
			  
		if(month=="september" )
			 return 9;
			  
		if(month=="october" )
			 return 10;
			  
		if(month=="november" )
			 return 11;
			  
		if(month=="december"	)
			 return 12;
			  											                 
}

  
int max(int a, int b); 
  
int height(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return N->height; 
} 
  
// A utility function to get maximum of two integers 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  
/* Helper function that allocates a new node with the given key and 
    NULL left and right pointers. */
struct Node* newNode(char month[20]) 
{ 
    struct Node* node = (struct Node*) 
                        malloc(sizeof(struct Node)); 
    strcpy(node->month,month);                    
    node->key=monthgen(month);
    node->left   = NULL; 
    node->right  = NULL; 
    node->height = 1;  // new node is initially added at leaf 
    return(node); 
} 

  
// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 
struct Node *rightRotate(struct Node *y) 
{ 
    struct Node *x = y->left; 
    struct Node *T2 = x->right; 
  
    // Perform rotation 
    x->right = y; 
    y->left = T2; 
  
    // Update heights 
    y->height = max(height(y->left), height(y->right))+1; 
    x->height = max(height(x->left), height(x->right))+1; 
  
    // Return new root 
    return x; 
} 
  
// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
struct Node *leftRotate(struct Node *x) 
{ 
    struct Node *y = x->right; 
    struct Node *T2 = y->left; 
  
    // Perform rotation 
    y->left = x; 
    x->right = T2; 
  
    //  Update heights 
    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 
  
    // Return new root 
    return y; 
} 
  
// Get Balance factor of node N 
int getBalance(struct Node *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 
  
// Recursive function to insert a key in the subtree rooted 
// with node and returns the new root of the subtree. 
struct Node* insert(struct Node* node,char month[]) 
{ 
	int key=monthgen(month);
    /* 1.  Perform the normal BST insertion */
    if (node == NULL) 
        return(newNode(month)); 
  
    if (key < node->key) 
        node->left  = insert(node->left, month); 
    else if (key > node->key) 
        node->right = insert(node->right, month); 
    else // Equal keys are not allowed in BST 
        return node; 
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), 
                           height(node->right)); 
  
    /* 3. Get the balance factor of this ancestor 
          node to check whether this node became 
          unbalanced */
    int balance = getBalance(node); 
  
    // If this node becomes unbalanced, then 
    // there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && key < node->left->key) 
        return rightRotate(node); 
  
    // Right Right Case 
    if (balance < -1 && key > node->right->key) 
        return leftRotate(node); 
  
    // Left Right Case 
    if (balance > 1 && key > node->left->key) 
    { 
        node->left =  leftRotate(node->left); 
        return rightRotate(node); 
    } 
  
    // Right Left Case 
    if (balance < -1 && key < node->right->key) 
    { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
  
    /* return the (unchanged) node pointer */
    return node; 
} 
  
// A utility function to print preorder traversal 
// of the tree. 
// The function also prints height of every node 
void preOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
        printf("%s ", root->month); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 
void inOrder(struct Node *root) 
{ 
    if(root != NULL) 
    { 
    	inOrder(root->left); 
        printf("%s ", root->month); 
        
        inOrder(root->right); 
    } 
} 
  
  
/* Drier program to test above function*/
int main() 
{ 
  struct Node *root = NULL; 
  
  /* Constructing tree given in the above figure */
  root = insert(root,"december"); 
  root = insert(root,"january");
  root = insert(root,"april");
  root = insert(root,"march");
  root = insert(root,"july");
  root = insert(root,"august");
  root = insert(root,"october");
  root = insert(root,"february");
  root = insert(root,"november");
  root = insert(root,"may");
  root = insert(root,"june");
  
  printf("Preorder traversal of the constructed AVL"
         " tree is \n"); 
  preOrder(root); 
  cout<<"\n";
  inOrder(root); 
  return 0; 
} 
