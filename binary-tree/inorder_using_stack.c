#include<stdio.h>
#define MAX_SIZE 30
int top=-1;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *stack[MAX_SIZE];
int is_full(int top)
{
    if(top==MAX_SIZE-1)
    return 1;
    else
    return 0;
}
int is_empty(int top)
{
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(struct node *data)
{
    if(is_full(top))
    printf("Warning:Stack is Full\n");
    else
    {
        top++;
        stack[top]=data;
    }
}
struct node *pop()
{
    if(is_empty(top))
    printf("Warningg:Stack is Empty\n");
    else
    {
        struct node *temp=stack[top];
        top--;
        return temp;
    }
}
void inorder_using_stack(struct node *root)
{
    struct node *current=root;
    while((current!=NULL)||(!is_empty(top)))
    {
        if(current==NULL)
        {
            struct node *ptr=pop();
            printf("%d\t",ptr->data);
            current=ptr->right;
        }
        else
        {
            push(current);
            current=current->left;
        }
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
    // printf("Preorder: ");
    // preorder(root);
    printf("Inorder: ");
    inorder(root);
    // printf("Postorder: ");
    // postorder(root);
    printf("Inorder using stack: ");
    inorder_using_stack(root);
    return 0;
}

