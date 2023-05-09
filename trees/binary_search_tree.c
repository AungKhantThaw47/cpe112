#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *left;
    struct node *right;
};

// Inorder traversal
void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ->", root->item);
    inorderTraversal(root->right);
}
// Preorder traversal
void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ->", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
// Postorder traversal
void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->item);
}
// Binary Search Tree Insert
struct node *insertElement(struct node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->item = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->item)
            {
                nodeptr = nodeptr->left;
            }
            else
            {
                nodeptr = nodeptr->right;
            }
        }
        if (val < parentptr->item)
        {
            parentptr->left = ptr;
        }
        else
        {
            parentptr->right = ptr;
        }
    }
    return tree;
}

// struct node* delRec(struct node* root,int delval){
//     if(root==NULL){
//         return NULL;
//     }
//     if(root->item==delval){
//         if()
//     }
// }

int Height(struct node *tree)
{
    int leftheight, rightheight;
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        leftheight = Height(tree->left);
        rightheight = Height(tree->right);
        if (leftheight > rightheight)
        {
            return (leftheight + 1);
        }
        else
        {
            return (rightheight + 1);
        }
    }
}

int totalNodes(struct node *tree){
    if(tree==NULL){
        return 0;
    }else
    {
        return (totalNodes(tree->left)+totalNodes(tree->right)+1);
    }
}

int totalExternalNodes(struct node *tree){
    if(tree==NULL){
        return 0;
    }else if ((tree->left==NULL)&&(tree->right==NULL))
    {
        return 1;
    }else
    {
        return (totalExternalNodes(tree->left)+totalExternalNodes(tree->right));
    }
}

int totalInternalNodes(struct node *tree){
    if( (tree==NULL) || ( (tree->left==NULL) && (tree->right==NULL) ) ){
        return 0;
    }else
    {
        return (totalInternalNodes(tree->left)+totalInternalNodes(tree->right)+1);
    }
    
}

int main()
{
    struct node *root = NULL;
    root = insertElement(root, 45);
    root = insertElement(root, 39);
    root = insertElement(root, 56);
    root = insertElement(root, 12);
    root = insertElement(root, 34);
    root = insertElement(root, 78);
    root = insertElement(root, 32);
    root = insertElement(root, 10);
    root = insertElement(root, 89);
    root = insertElement(root, 54);
    root = insertElement(root, 67);
    root = insertElement(root, 81);
    printf("Inorder traversal \n");
    inorderTraversal(root);
    printf("\nPreorder traversal \n");
    preorderTraversal(root);
    printf("\nPostorder traversal \n");
    postorderTraversal(root);
}