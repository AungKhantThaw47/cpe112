#include <stdio.h>

int main()
{
    int y, x;
    scanf("%d %d", &y, &x);
    int even_count, odd_count;
    int even[y * x], odd[y * x];
    even_count = 0;
    odd_count = 0;
    for (int i = 0; i < y * x; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp % 2 == 0)
        {
            even[even_count] = temp;
            even_count++;
        }
        else
        {
            odd[odd_count] = temp;
            odd_count++;
        }
    }
    if (odd_count > 0)
    {
        for (int i = 0; i < odd_count; i++)
        {
            printf("%d ", odd[i]);
        }
    }
    else
    {
        printf("None");
    }
    printf("\n");
    if (even_count > 0)
    {
        for (int i = 0; i < even_count; i++)
        {
            printf("%d ", even[i]);
        }
    }
    else
    {
        printf("None");
    }
    return 0;
}