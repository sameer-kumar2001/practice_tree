#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node* insert(struct node* ptr,int d)
{
    if(ptr==NULL)
    {
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=d;
        ptr->left=NULL;
        ptr->right=NULL;
    }
    else if(d<ptr->data)
    ptr->left=insert(ptr->left,d);
    else if(d>ptr->data)
    ptr->right=insert(ptr->right,d);
    else
    printf("Duplicate Element!\n");
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
    struct node *root=NULL;
    int d,n;
    printf("Enter the no of nodes you want to create:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter the data:\n");
        scanf("%d",&d);
        root=insert(root,d);
    }
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    return 0;
}