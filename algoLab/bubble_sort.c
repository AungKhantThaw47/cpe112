#include<stdio.h>
// 89 45 68 5 90 34 17 25
void bubble_sort(int  *arr,int length);

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
    bubble_sort(data,num);
    printf("Output: ");
    for (int i = 0; i < num; i++)
    {
        printf("%d , ",data[i]);
    }
    return 0;
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
        if(flag==0){
            return;
        }
        flag = 0;
    }
    
}