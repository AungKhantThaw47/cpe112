#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void test_v1();
void test_v2();
void test_v3();
void bubble_sort(int  *arr,int length);
void bubble_sort_v1(int  *arr,int length);
void bubble_sort_v2(int  *arr,int length);

int main()
{
    test_v1();
    test_v2();
    test_v3();
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
    bubble_sort(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Bubble Sort Average Case) : %f\n", duration);
    start = clock();
    bubble_sort(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Bubble Sort Best Case) : %f\n", duration);
    int input_reverse_arr[30000];
    for (int i = 1; i <= 30000; i++)
    {
        input_reverse_arr[i-1] = input_arr[30000 - (i)];
    }
    start = clock();
    bubble_sort(input_reverse_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Bubble Sort Worst Case) : %f\n", duration);
    start = clock();
    FILE *foutptr = fopen("bubble_sorted_data.txt","w");
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
    bubble_sort_v1(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Bubble Sort Average Case) : %f\n", duration);
    start = clock();
    bubble_sort_v1(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Bubble Sort Best Case) : %f\n", duration);
    int input_reverse_arr[30000];
    for (int i = 1; i <= 30000; i++)
    {
        input_reverse_arr[i-1] = input_arr[30000 - (i)];
    }
    start = clock();
    bubble_sort_v1(input_reverse_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Bubble Sort Worst Case) : %f\n", duration);
    start = clock();
    FILE *foutptr = fopen("bubble_sorted_data.txt","w");
    for (int i = 1; i <= 30000; i++)
    {
        fprintf(foutptr," %d ,", input_arr[i-1]);
    }
    fclose(foutptr);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (File Output) : %f\n", duration);
}

void test_v3(){
    printf("Test Case V3\n");
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
    bubble_sort_v2(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Bubble Sort Average Case) : %f\n", duration);
    start = clock();
    bubble_sort_v2(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Bubble Sort Best Case) : %f\n", duration);
    int input_reverse_arr[30000];
    for (int i = 1; i <= 30000; i++)
    {
        input_reverse_arr[i-1] = input_arr[30000 - (i)];
    }
    start = clock();
    bubble_sort_v2(input_reverse_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Bubble Sort Worst Case) : %f\n", duration);
    start = clock();
    FILE *foutptr = fopen("bubble_sorted_data.txt","w");
    for (int i = 1; i <= 30000; i++)
    {
        fprintf(foutptr," %d ,", input_arr[i-1]);
    }
    fclose(foutptr);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (File Output) : %f\n", duration);
}

void bubble_sort(int  *arr,int length){
    int i , j , temp , flag = 0;
    for (i = 0; i < (length); i++)
    {
        for (j = 0; j < (length-i-1); j++)
        {
            if(arr[j]>arr[j+1]){
                flag = 1;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        // if(flag==0){
        //     return;
        // }
        // flag = 0;
    }    
}

void bubble_sort_v1(int  *arr,int length){
    int i , j , temp , flag = 0;
    for (i = 0; i < (length); i++)
    {
        for (j = 0; j < (length-i-1); j++)
        {
            if(arr[j]>arr[j+1]){
                flag = 1;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        if(flag==0){
            return;
        }
        // flag = 0;
    }
}

void bubble_sort_v2(int  *arr,int length){
    int i , j , temp , flag = 0;
    for (i = 0; i < (length); i++)
    {
        for (j = 0; j < (length-i-1); j++)
        {
            if(arr[j]>arr[j+1]){
                flag = 1;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        if(flag==0){
            return;
        }
        flag = 0;
    }
}