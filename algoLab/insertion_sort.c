#include<stdio.h>
#include<stdlib.h>
// 89 45 68 5 90 34 17 25

struct node
{
    int item;
    struct node *left;
    struct node *right;
};

void insertion_sort_test(int  *arr,int length);
int inorderTraversal(struct node *root,int *arr,int counter)
{
    if (root == NULL)
        return counter;
    counter = inorderTraversal(root->left,arr,counter);
    // printf("%d ->", root->item);
    arr[counter] = root->item;
    counter++;
    counter = inorderTraversal(root->right,arr,counter);
    return counter;
}
struct node *insertElement(struct node *tree, int val);

void insertion_sort(int  *arr,int length);

int main(){
    int num;
    printf("Please enter lenght of array: ");
    scanf("%d",&num);
    int data[num];
    printf("Now enter data: ");
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&data[i]);
    }
    printf("Output: ");
    for (int i = 0; i < num; i++)
    {
        printf("%d , ",data[i]);
    }
    // insertion_sort(data,num);
    insertion_sort_test(data,num);
    printf("Output: ");
    for (int i = 0; i < num; i++)
    {
        printf("%d , ",data[i]);
    }
    return 0;
}
void insertion_sort(int  *arr,int length){
    int i , j , temp;
    for (i = 0; i < length; i++)
    {
        temp = arr[i];
        j = i-1;
        while ((temp<arr[j])&&(j>=0))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void insertion_sort_test(int  *arr,int length){
    int i , counter = 0;
    struct node *root = NULL;
    for (i = 0; i < length; i++)
    {
        root = insertElement(root, arr[i]);
    }
    inorderTraversal(root,arr,0);
}

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

// int binarySearch(int arr[], int l, int r, int x)
// {
//     while (l <= r) {
//         int m = l + (r - l) / 2;
 
//         // Check if x is present at mid
//         if (arr[m] == x)
//             return m;
 
//         // If x greater, ignore left half
//         if (arr[m] < x)
//             l = m + 1;
 
//         // If x is smaller, ignore right half
//         else
//             r = m - 1;
//     }
 
//     // if we reach here, then element was
//     // not present
//     return -1;
// }
