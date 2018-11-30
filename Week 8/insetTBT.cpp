#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct threadedbinarytree
{int info;
struct threadedbinarytree *left,*right;
int rlink;
}TBT;

TBT *create();
TBT *makenode(int);
TBT *insert(TBT *,TBT *);
/*inorder or symmetric order*/
void inorder(TBT *);
/*Depth first order*/
void preorder(TBT *);

TBT *create()
{
TBT *temp=(TBT *)malloc(sizeof(TBT));
if(temp==NULL)
{printf("Memory allocation error");
exit(1);
}
return temp;
}


TBT *makenode(int x)
{TBT *temp=create();
temp->info=x;
temp->left=NULL;
temp->right=NULL;
temp->rlink=1;/*1 for thread,0 for link*/
return temp;
}

TBT *insert(TBT *root,TBT *newnode)
{
TBT *p,*temp=root;
if(root==NULL)
{root=newnode;
return root;
}
while(temp!=NULL)
{
if(newnode->info<temp->info)
{if(temp->left)
temp=temp->left;
else
{temp->left=newnode;
newnode->left=NULL;
newnode->right=temp;
newnode->rlink=1; /*set during making node*/
break;
}
}
else
{if(temp->right)
{if(temp->rlink==1)
{
newnode->right=temp->right;
temp->right=newnode;
temp->rlink=0;
newnode->rlink=1;/*set during making node*/
break;
}
else
temp=temp->right;
}
else
{p=temp->right;
temp->right=newnode;
temp->rlink=0;
newnode->left=NULL;
newnode->right=p;
newnode->rlink=1;
break;
}
}
}
return root;
}

void preorder(TBT *root)
{TBT *p,*temp=root;
p=root;
while(temp!=NULL)
{while(p!=NULL)
{temp=p;
printf(" %d",p->info);
p=p->left;
}
if((temp->rlink==1)&&(temp->right==NULL))
return;
if(temp->rlink==1)
temp=temp->right->right;
else
temp=temp->right;
p=temp;
}
}

void inorder(TBT *root)
{TBT *p,*temp=root;
p=root;
while(temp!=NULL)
{while(p!=NULL)
{temp=p;
p=p->left;
}
printf(" %d",temp->info);
if((temp->rlink==1) && (temp->right==NULL))
return;
if(temp->rlink==1)
temp=temp->right;
else
p=temp->right;
}
}

int  main()
{
int x,ch;
TBT *node,*root=NULL;
while(1)
{

printf("Enter choice\n");
printf("\n 1. Insert");
printf("2. Traverse inorder");
printf("3. Traverse preorder");
printf("4. Exit");
printf("\nEnter your choice?");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter the  number to insert?");
scanf("%d",&x);
node=makenode(x);
root=insert(root,node);
break;
case 2:
inorder(root);
break;
case 3:
preorder(root);
break;
case 4:
exit(0);
default:
printf("/n Choice is invalid.");
}

}
}
