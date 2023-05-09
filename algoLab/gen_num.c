#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, num;
    FILE *fptr;
    fptr = fopen("data.txt","w");
    for (i = 1; i <= 30000; i++)
    {
        num = rand() % 30000 + 1; // use rand() function to get the random number
        printf(" %d ,", num);
        fprintf(fptr," %d ,", num);
    }
    return 0;
}