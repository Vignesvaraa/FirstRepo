
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

/** Function to compute the height of the tree.
 *  root is a pointer to the root of the tree
 */
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
/** 
 * Count the total number of nodes in a Binary tree.
 */
int countNodes(Node* r)
{
    if(r == NULL)
        return 0;
    return 1 + countNodes(r->rptr) + countNodes(r->lptr); 
}

// Helper function. to compute x^n. Assumes n to be positive.
int exponent(int x, int n)
{
    int pow = 1;
    int i=0;
    for(i=0; i<n; i++)
         pow *= x;
    return pow;
}
/** 
 * returns true if a binary tree is complete binary tree, false otherwise
 */
int checkCompleteTree(Node* r)
{
    if(r == NULL)
        return true;
    int h = getHeight(r);
    int n = countNodes(r);
    if(n == exponent(2,h)-1)
        return 1;
    else
        return 0;
}

int IsStrictBst(Node* root)
{
    if (root->lptr&&root->rptr)
    {return (IsStrictBst(root->lptr)*IsStrictBst(root->rptr));}
    
else if(!root->lptr&&!root->rptr)
return 1;
else return 0;
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

    int val=checkCompleteTree(root);
    
    if(val==1)
    cout<<"Complete";
    else
    cout<<"Not Complete";
    
    cout<<endl;
    
    int val2=IsStrictBst(root);
    if(val2==1)
    cout<<"Strict";
    else
    cout<<"Not Strict";

 
    return 0;
}
