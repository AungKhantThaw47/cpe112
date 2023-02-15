#include<stdio.h>

int main(){
    int len;
    int addition = 0;
    scanf("%d",&len);
    for (int i = 0; i < len*len; i++)
    {
        int temp;
        scanf("%d",&temp);
        if(i%(len+1)==0){
            addition += temp;
        }
    }
    printf("%d",addition);
    return 0;
}