#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    FILE *fptr;

    if ((fptr = fopen("data.txt", "r")) == NULL)
    {
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    for (int i = 1; i <= 30000; i++)
    {
        fscanf(fptr," %d ,", &num);
        printf("%d , ",num);
    }
    return 0;
}