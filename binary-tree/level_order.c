#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void print_level(struct node *root,int level)
{
    if(root==NULL)
    return;
    if(level==1)
    printf("%d  ",root->data);
    else
    {
        print_level(root->left,level-1);
        print_level(root->right,level-1);
    }
}
int hight(struct node *root)
{
    if(root==NULL)
    return 0;
    else
    {
        int r,l=hight(root->left);
        r=hight(root->right);
        if(l>r)
        return ++l;
        else
        return ++r;
    }
}
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
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    int result=hight(root);
    for(int i=1;i<=result;i++)
    print_level(root,i);
    return 0;
}
