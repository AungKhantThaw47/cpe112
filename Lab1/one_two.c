#include<stdio.h>
#include<math.h>

int main(){
    int num_of_stu = 20;
    int num_of_subj = 5;
    int arr[num_of_stu][num_of_subj];
    float avg[num_of_stu];
    // for (int i = 0; i < num_of_stu; i++)
    // {
    //     avg[i] = 0.0;
    // }
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
        int temp = avg[i];
        avg[i] = round((avg[i]/num_of_subj)*100);
        avg[i] = avg[i]/100;
        int onePlace = avg[i]*10 - ((int)avg[i]*10);
        int twoPlace = (avg[i]*100 - ((int)avg[i]*100)) - (onePlace*10);
        if(onePlace==0&&twoPlace==0)
        {
            printf("%d\n",(int)avg[i]);
        }else if (onePlace!=0&&twoPlace==0)
        {
            printf("%d.%d\n",(int)avg[i],onePlace);
        }else
        {
            printf("%.2f\n",avg[i]);
        }
    }    
    return 0;
}