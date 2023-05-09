#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void test_v1();
void selection_sort(int  *arr,int length);

int main()
{
    test_v1();
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
    selection_sort(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Insertion Sort Average Case) : %f\n", duration);
    start = clock();
    selection_sort(input_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Insertion Sort Best Case) : %f\n", duration);
    int input_reverse_arr[30000];
    for (int i = 1; i <= 30000; i++)
    {
        input_reverse_arr[i-1] = input_arr[30000 - (i)];
    }
    start = clock();
    selection_sort(input_reverse_arr,30000);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (Insertion Sort Worst Case) : %f\n", duration);
    start = clock();
    FILE *foutptr = fopen("selection_sorted_data.txt","w");
    for (int i = 1; i <= 30000; i++)
    {
        fprintf(foutptr," %d ,", input_arr[i-1]);
    }
    fclose(foutptr);
    end = clock();
    duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds (File Output) : %f\n", duration);
}

void selection_sort(int *arr, int length)
{
    int k, pos, temp, smallest;
    for (k = 0; k < length; k++)
    {
        smallest = arr[k];
        for (int i = k; i < length; i++)
        {
            if (arr[i] < smallest)
            {
                smallest = arr[i];
                pos = i;
            }
        }
        temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;
    }
}