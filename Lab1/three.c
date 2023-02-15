#include<stdio.h>

int main(){
    int len;
    scanf("%d",&len);
    int arr[len];
    int biggest = -10001;
    int biggest_loc = -1;
    int biggest2 = -10001;
    int biggest2_loc = -1;
    int smallest = 10001;
    int smallest_loc = -1;
    int smallest2 = 10001;
    int smallest2_loc = -1;
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]>biggest){
            biggest2 = biggest;
            biggest2_loc = biggest_loc;
            biggest = arr[i];
            biggest_loc = i;
        }else if (arr[i]>biggest2)
        {
            biggest2 =arr[i];
            biggest2_loc = i;
        }
        if(arr[i]<smallest){
            smallest2 = smallest;
            smallest2_loc = smallest_loc;
            smallest = arr[i];
            smallest_loc = i;
        }else if (arr[i]<smallest2)
        {
            smallest2 = arr[i];
            smallest2_loc = i;
        }
    }
    // printf("%d %d",biggest2_loc,smallest2_loc);
    int temp = smallest2;
    arr[smallest2_loc] = biggest2;
    arr[biggest2_loc] = temp;
    for (int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}