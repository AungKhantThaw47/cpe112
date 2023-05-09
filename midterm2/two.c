#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *left;
    struct node *right;
    int position;
};

struct node *largest(struct node * B){
    if((B->left==NULL)&&(B->right==NULL)){
        printf("\nNode: %d\n",B->item);
        return B;
    }
    if((B->left==NULL)&&(B->right!=NULL)){
        if(B->item<largest(B->right)->item)
            return largest(B->right);
        return B;
    }
    if((B->left!=NULL)&&(B->right==NULL)){
        if(B->item<largest(B->left)->item)
            return largest(B->left);
        return B;
    }
    if(largest(B->left)->item > largest(B->right)->item){
        if(B->item<largest(B->left)->item)
            return largest(B->left);
        return B;
    }else
    {
        if(B->item<largest(B->right)->item)
            return largest(B->right);
        return B;
    }
}

// Inorder traversal
void PrintIn(struct node *root)
{
    if (root == NULL)
        return;
    PrintIn(root->left);
    printf("%d ", root->item);
    PrintIn(root->right);
}
// Preorder traversal
void PrintPre(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->item);
    PrintPre(root->left);
    PrintPre(root->right);
}
// Postorder traversal
void PrintPost(struct node *root)
{
    if (root == NULL)
        return;
    PrintPost(root->left);
    PrintPost(root->right);
    printf("%d ", root->item);
}


struct node *SearchPos(struct node *tree,int position){
    if(tree->position==position){
        return tree;
    }
    struct node *SecPosRes;
    if(tree->left!=NULL){
        SecPosRes = SearchPos(tree->left,position);
        if(SecPosRes!=NULL){
            return SecPosRes;
        }
    }
    if(tree->right!=NULL){
        SecPosRes = SearchPos(tree->right,position);
        if(SecPosRes!=NULL){
            return SecPosRes;
        }
    }
    return NULL;
}

void percolateUp(struct node *tree,int index){
    if(index>1){
        if(SearchPos(tree,index/2)->item > SearchPos(tree,index)->item){
            struct node *by2 = SearchPos(tree,index/2);
            struct node *atindex = SearchPos(tree,index);
            int temp = by2->item;
            by2->item = atindex->item;
            atindex->item = temp;
            percolateUp(tree,index/2);
        }
    }
}

// Binary Search Tree Insert
struct node *Insert(struct node *tree, int val,int position)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->item = val;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->position = position;
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
        tree->position = 1;
    }
    else
    {
        struct node *SecPosRes;
        if(position%2==1){
            SecPosRes = SearchPos(tree,((position-1)/2));
            SecPosRes->right = ptr;
        }else
        {
            SecPosRes = SearchPos(tree,(position/2));
            SecPosRes->left = ptr;
        }
        percolateUp(tree,position);
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

int Search(struct node *tree,int val){
    if(tree==NULL){
        return -1;
    }
    if(tree->item==val){
        return 1;
    }
    if(Search(tree->left,val)==1){
        return 1;
    }
    if(Search(tree->right,val)==1){
        return 1;
    }
    return -1;
}

int SearchDup(int arr[],int length,int val){
    for (int i = 0; i < length; i++)
    {
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}

int main()
{
    struct node *root = NULL;
    int num;
    scanf("%d",&num);
    int counter = 0;
    for (int i = 0; i < num; i++)
    {
        int temp;
        scanf("%d",&temp);
        root = Insert(root,temp,(counter+1));
        counter++;
    }
    PrintPre(root);
    return 0;
}