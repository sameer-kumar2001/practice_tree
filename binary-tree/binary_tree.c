#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create()
{
    struct node *ptr;
    int d;
    printf("Enter the data(Enter -1 for no data):\n");
    scanf("%d",&d);
    if(d==-1)
    return NULL;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=d;
    printf("Enter the left child of %d\n",d);
    ptr->left=create();
    printf("Enter the right child of %d\n",d);
    ptr->right=create();
    return ptr;
}
void preorder(struct node*ptr)
{
    if(ptr==NULL)
    return;
    printf("%d\t",ptr->data);
    preorder(ptr->left);
    preorder(ptr->right);
}
void inorder(struct node*ptr)
{
    if(ptr==NULL)
    return;
    inorder(ptr->left);
    printf("%d\t",ptr->data);
    inorder(ptr->right);
}
void postorder(struct node*ptr)
{
    if(ptr==NULL)
    return;
    postorder(ptr->left);
    postorder(ptr->right);
    printf("%d\t",ptr->data);
}
int main()
{
    struct node *root;
    root=create();
    printf("Preorder: ");
    preorder(root);
    printf("Inorder: ");
    inorder(root);
    printf("Postorder: ");
    postorder(root);
    return 0;
}

