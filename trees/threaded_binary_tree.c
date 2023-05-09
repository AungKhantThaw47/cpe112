#include <stdio.h>
#include<stdlib.h>

struct tree
{
    int val;
    struct tree *right;
    struct tree *left;
    int thread;
};

struct tree *insert_node(struct tree *root, struct tree *ptr, struct tree *rt)
{
    if (root == NULL)
    {
        root = ptr;
        if (rt != NULL)
        {
            root->right = rt;
            root->thread = 1;
        }
    }
    else if (ptr->val < root->val)
    {
        root->left = insert_node(root->left, ptr, root);
    }
    else
    {
        if (root->thread == 1)
        {
            root->right = insert_node(NULL, ptr, rt);
            root->thread = 0;
        }
        else
        {
            root->right = insert_node(root->right, ptr, rt);
        }
    }
    return root;
}

struct tree *create_threaded_tree(struct tree *root, int num)
{
    struct tree *ptr;
    ptr = (struct tree*)malloc(sizeof(struct tree));
    ptr->val = num;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->thread = 0;
    root = insert_node(root, ptr, NULL);
    return root;
}

void inorder(struct tree *root)
{
    struct tree *ptr = root, *prev;
    do
    {
        while (ptr != NULL)
        {
            prev = ptr;
            ptr = ptr->left;
        }
        if(prev!=NULL){
            printf(" %d",prev->val);
            ptr = prev->right;
            while (prev != NULL && prev->thread)
            {
                printf(" %d",ptr->val);
                prev = ptr;
                ptr = ptr->right;
            }
            
        }
    } while (ptr != NULL);
}

int main(){
    struct tree *root=NULL;
    root = create_threaded_tree(root,1);
    root = create_threaded_tree(root,2);
    root = create_threaded_tree(root,3);
    root = create_threaded_tree(root,4);
    root = create_threaded_tree(root,5);
    root = create_threaded_tree(root,6);
    root = create_threaded_tree(root,7);
    inorder(root);
    return 0;
}