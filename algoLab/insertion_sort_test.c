#include <time.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *left;
    struct node *right;
};

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

void test_v1();
void test_v2();
void insertion_sort_v1(int  *arr,int length);
void insertion_sort_v2(int  *arr,int length);

int main()
{
    test_v1();
    test_v2();
    return 0;
}

void test_v1(){
    printf("Test Case V1\n");
    int num;
    int input_arr[30000];
    clock_t start, end;
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    start = clock();
    for (int i = 1; i <= 30000; i++)
    {
        fscanf(fptr," %d ,", &num);
        input_arr[i-1] = num;
        // printf("%d , ",num);
    }
    fclose(fptr);
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (File Input) : %f\n", duration);
    start = clock();
    insertion_sort_v1(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Insertion Sort Average Case) : %f\n", duration);
    start = clock();
    insertion_sort_v1(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Insertion Sort Best Case) : %f\n", duration);
    int input_reverse_arr[30000];
    for (int i = 1; i <= 30000; i++)
    {
        input_reverse_arr[i-1] = input_arr[30000 - (i)];
    }
    start = clock();
    insertion_sort_v1(input_reverse_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Insertion Sort Worst Case) : %f\n", duration);
    start = clock();
    FILE *foutptr = fopen("insertion_sorted_data.txt","w");
    for (int i = 1; i <= 30000; i++)
    {
        fprintf(foutptr," %d ,", input_arr[i-1]);
    }
    fclose(foutptr);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (File Output) : %f\n", duration);
}

void test_v2(){
    printf("Test Case V2\n");
    int num;
    int input_arr[30000];
    clock_t start, end;
    FILE *fptr;
    fptr = fopen("data.txt", "r");
    start = clock();
    for (int i = 1; i <= 30000; i++)
    {
        fscanf(fptr," %d ,", &num);
        input_arr[i-1] = num;
        // printf("%d , ",num);
    }
    fclose(fptr);
    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (File Input) : %f\n", duration);
    start = clock();
    insertion_sort_v2(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Insertion Sort Average Case) : %f\n", duration);
    start = clock();
    insertion_sort_v2(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Insertion Sort Best Case) : %f\n", duration);
    int input_reverse_arr[30000];
    for (int i = 1; i <= 30000; i++)
    {
        input_reverse_arr[i-1] = input_arr[30000 - (i)];
    }
    start = clock();
    insertion_sort_v2(input_reverse_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Insertion Sort Worst Case) : %f\n", duration);
    start = clock();
    FILE *foutptr = fopen("insertion_sorted_data.txt","w");
    for (int i = 1; i <= 30000; i++)
    {
        fprintf(foutptr," %d ,", input_arr[i-1]);
    }
    fclose(foutptr);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (File Output) : %f\n", duration);
}

void insertion_sort_v1(int  *arr,int length){
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

void insertion_sort_v2(int  *arr,int length){
    int i , counter = 0;
    struct node *root = NULL;
    for (i = 0; i < length; i++)
    {
        root = insertElement(root, arr[i]);
    }
    inorderTraversal(root,arr,0);
}
