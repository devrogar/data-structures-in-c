#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
 int data;
 struct Node *parent;
 struct Node *left;
 struct Node *right;
}node;

node *root=NULL;
int val,c;

void tree_insert(node *ptr,int key)
{
 node *temp,*x,*y=NULL;
 x=ptr;
 temp=(node *)malloc(sizeof(node));
 temp->data=key;
 temp->left=NULL;
 temp->right=NULL;
 
   while(x)
    {
     y=x;
     if(key > x->data)
      {
       x=x->right;
      }
     else
      {
       x=x->left;
      }
    }
 temp->parent=y;
 if(y==NULL)
  {
   root=temp;
  }
 else
  {
   if(temp->data < y->data)
     {
      y->left=temp;
     }
   else
     {
      y->right=temp;
     }
  }
}

void search(node *ptr, int key)
 {
  node *x;
  x=ptr;
  if(root==NULL)
   {
    printf("NOT FOUND\n");
    return;
   }
  while(x)
   {
    if(x->data == key)
     {
      printf("FOUND\n");
      break;
     }
    if(key > x->data)
     {
      x=x->right;
     }
    else
     {
      x=x->left;
     }
   }
 if(x==NULL)
   { 
    printf("NOT FOUND\n");
   }
 return;
 }

node* find_min(node *ptr)
 {
  node *x=ptr,*y=NULL;
  while(x)
   {
    y=x;
    x=x->left;
   }
  if(y!=NULL)
   return y;
  else
   {
   printf("NIL\n");
   return NULL;
   }
 }

void find_max(node *ptr)
 {
  node *x=ptr,*y=NULL;
  while(x)
   {
    y=x;
    x=x->right;
   }
  if(y!=NULL)
   printf("%d\n",y->data);
  else
   printf("NIL\n");
 }

void predecessor(node *ptr, int elem)
{
 node *x=ptr,*y=NULL;
 if(root==NULL)
  {
   printf("NOT FOUND\n");
   return;
  }
 while(x)
  {
   if(x->data == elem)
     {
      break;
     }
   if(x->data > elem)
    {
     x=x->left;
    }
   else
    {
     x=x->right;
    }
  }
 if(x->left != NULL)
   {
    find_max(x->left);
   }
 else
  {
   y=x->parent;
   while(y!=NULL && x==y->left)
     {
      x=y;
      y=y->parent;
     }
   if(y==NULL)
    {
     printf("NIL\n");
     return;
    }
   else
    {
     printf("%d\n",y->data);
     return;
    }
  }
}

node* successor(node *ptr,int elem)
 {
  node *x=ptr,*y=NULL;
 if(root==NULL)
  {
   printf("NOT FOUND\n");
   return NULL;
  }
 while(x)
  {
   if(x->data == elem)
     {
      break;
     }
   if(x->data > elem)
    {
     x=x->left;
    }
   else
    {
     x=x->right;
    }
  }
 if(x->right != NULL)
   {
    node *k;
    k=find_min(x->right);
    return k;
   }
 else
  {
   y=x->parent;
   while(y!=NULL && x==y->right)
     {
      x=y;
      y=y->parent;
     }
   if(y==NULL)
    {
     printf("NIL\n");
     return NULL;
    }
   else
    {
     return y;
    }
  }
 }

void tree_delete(node *ptr, int elem)
 {
  node *x=ptr,*y=NULL,*z=NULL;
  if(root==NULL)
   {
    printf("TREE EMPTY\n");
    return;
   }

  while(x)
   {
    if(x->data == elem)
      {
       break;
      }
    if(elem > x->data)
      {
       x=x->right;
      }
    if(elem < x->data)
      {
       x=x->left;
      }
   }

  if(x->left != NULL || x->right !=NULL)
    {
     if(x->right!=NULL && x->left!=NULL)
       {
        y=successor(root,x->data);
        z=y->parent;
        if(x==z)
          {    
           if(y->right!=NULL)
             {
              x->data=y->data;
              z->right=y->right;
              y->right->parent=z;
              free(y);
             }
           else
             {
              x->data=y->data;
              z->right=NULL;
              free(y);
             }
          }
         else
          {
           if(y->right!=NULL)
             {
              x->data=y->data;
              z->left=y->right;
              y->right->parent=z;
              free(y);
             }
            else
             {
              x->data=y->data;
              z->left=NULL;
              free(y);
             }
          }
          return;
        }

      y=x->parent;
      if(y==NULL)
       {
        if(x->left==NULL)
         {
          root=x->right;
          x->right->parent=NULL;
         }
        else
         {
          root=x->left;
          x->left->parent=NULL;
         }
        free(x);
        return;
      }

     if(x->left==NULL && y!=NULL)
       {
        if(y->left==x)
         {
          y->left=x->right;
          x->right->parent=y;
          free(x);
         }
        else
         {
          y->right=x->right;
          x->right->parent=y;
          free(x);
         }
         return;
       }

     if(x->right==NULL && y!=NULL)
       {
        if(y->left==x)
          {
           y->left=x->left;
           x->left->parent=y;
           free(x);
          }
        else
          {
           y->right=x->left;
           x->left->parent=y;
           free(x);
          }
          return;
       } 
     }
  else
    {
     y=x->parent;
     if(y==NULL)
       {
        root=NULL;
        free(x);
        return;
       }
     if(x==y->left && y!=NULL)
       {
        y->left=NULL;
        free(x);
        return;
       }
     else
       {
        y->right=NULL;
        free(x);
        return;
       }
       return;
    }
 }

void inorder(node *ptr)
 {
  node *x=ptr;
  if(root==NULL)
   {
    printf("TREE EMPTY");
    return;
   }
 
 if(x!=NULL)
   {
    inorder(x->left);
    printf("%d ",x->data);
    inorder(x->right);
   }
 return;
 }

void preorder(node *ptr)
 {
  node *x=ptr;
  if(root==NULL)
   {
    printf("TREE EMPTY");
    return;
   }

  if(x!=NULL)
    {
     printf("%d ",x->data);
     preorder(x->left);
     preorder(x->right);
    }
  return;
 }
void postorder(node *ptr)
 {
  node *x=ptr;
  if(root==NULL)
   {
    printf("TREE EMPTY");
    return;
   }
  if(x!=NULL)
   {
    postorder(x->left);
    postorder(x->right);
    printf("%d ",x->data);
   }
  return;
 }

int main()
{
 FILE *fp;
 fp=fopen("input.txt","r");
 if(fp==NULL)
   printf("cannot open file\n");
 else
  
 while(fscanf(fp,"%d",&c)!=EOF)
  {
   if(c==1)
     {
      fscanf(fp,"%d",&val);
      tree_insert(root,val);
     }
   if(c==2)
    {
     fscanf(fp,"%d",&val);
     search(root,val);
    }
   if(c==3)
    {
     node *l;
     l=find_min(root);
     if(l!=NULL)
      {
       printf("%d\n",l->data);
      }
    }
   if(c==4)
    {
     find_max(root);
    }
   if(c==5)
    {
     fscanf(fp,"%d",&val);
     predecessor(root,val);
    }
   if(c==6)
    {
     node *k;
     fscanf(fp,"%d",&val);
     k=successor(root,val);
     if(k!=NULL)
      {
       printf("%d\n",k->data);
      }
    }
   if(c==7)
    {
     fscanf(fp,"%d",&val);
     tree_delete(root,val);
    }
   if(c==8)
    {
     inorder(root);
     printf("\n");
    }
   if(c==9)
    {
     preorder(root);
     printf("\n");
    }
   if(c==10)
    {
     postorder(root);
     printf("\n");
    }
   if(c==0)
    {
     exit(0);
    }
  }
}
