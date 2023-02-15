#include<stdio.h>
#include<math.h>

int main(){
    int num_of_stu = 20;
    int num_of_subj = 5;
    int arr[num_of_stu][num_of_subj];
    float avg[num_of_stu];
    int count = 0;
    for (int i = 0; i < num_of_stu; i++)
    {
        avg[i] = 0.0;
        for (int j = 0; j < num_of_subj; j++)
        {
            scanf("%d",&arr[i][j]);
            avg[i]+= arr[i][j];
        }
    }
    for (int i = 0; i < num_of_stu; i++)
    {
        avg[i] = avg[i]/num_of_subj;
        if(avg[i]<50){
            count++;
        }
    }
    printf("%d",count);    
    return 0;
}