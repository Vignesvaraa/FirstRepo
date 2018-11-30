
#include <iostream>
using namespace std;

struct Node
{
    Node *lptr;
    int data;
    Node *rptr;
    Node(int data)
    {
        this->data = data;
        lptr = rptr = NULL;
    }
};

int getHeight(Node* root) 
{
    if (root == NULL) 
       return 0;
    // Compute height of each tree
    int heightLeft = getHeight(root->lptr);
    int heightRight = getHeight(root->rptr);
    /* use the larger one */
    if (heightLeft > heightRight) 
        return(heightLeft + 1);
    else 
        return(heightRight + 1);
}

// Returns maximum value in a given Binary Tree
int findMax(Node* root)
{
    // Base case
    if (root == NULL)
      return INT_MIN;
 
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->data;
    int lres = findMax(root->lptr);
    int rres = findMax(root->rptr);
    if (lres > res)
      res = lres;
    if (rres > res)
      res = rres;
    return res;
}

/* Function to find sum of all the elements*/
int addBT(Node* root)
{
    if (root == NULL)
        return 0;
    return (root->data + addBT(root->lptr) + addBT(root->rptr));
}

/* Function to get the count of leaf nodes in a binary tree*/
unsigned int getLeafCount(Node* node)
{
  if(node == NULL)       
    return 0;
  if(node->lptr == NULL && node->rptr==NULL)      
    return 1;            
  else
    return getLeafCount(node->lptr)+
           getLeafCount(node->rptr);      
}

int main()
{
    struct Node *root = new Node(1);
    root->lptr            = new Node(2);
    root->rptr         = new Node(3);
    root->lptr->lptr     = new Node(4);
    root->lptr->rptr = new Node(5); 
    root->rptr->lptr     = new Node(6);
    root->rptr->rptr = new Node(7);
    
    cout<<"No. of leaf Node: "<<getLeafCount(root)<<endl;
    cout<<"Max Element: "<<findMax(root)<<endl;
    cout<<"Height of Tree: "<<getHeight(root)<<endl;
    cout<<"Sum of all elements: "<<addBT(root)<<endl;
 
    return 0;
}
