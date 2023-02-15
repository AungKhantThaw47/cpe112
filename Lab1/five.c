#include <stdio.h>

int main()
{
    int y, x;
    scanf("%d %d", &y, &x);
    int max = y * x;
    int count = 0;
    int arr[y][x];
    int upbound = -1;
    int downbound = y;
    int leftbound = -1;
    int rightbound = x;
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int row_column = 1;
    int left_to_right = 1;
    int down_to_button = 1;
    int check = 1;
    while (check == 1 && count < max)
    {
        if (row_column == 1 && left_to_right == 1 && down_to_button == 1)
        {
            for (int i = leftbound + 1; i < rightbound; i++)
            {
                if (count < max)
                {
                    printf("%d ", arr[upbound + 1][i]);
                }
                else
                {
                    break;
                }
                count++;
            }
            upbound++;
            row_column = 0;
            left_to_right = 0;
            if (upbound + 1 >= downbound)
            {
                check = 0;
            }
        }
        if (row_column == 0 && left_to_right == 0 && down_to_button == 1)
        {
            for (int i = upbound + 1; i < downbound; i++)
            {
                if (count < max)
                {
                    printf("%d ", arr[i][rightbound - 1]);
                }
                else
                {
                    break;
                }
                count++;
            }
            rightbound--;
            row_column = 1;
            down_to_button = 0;
            if (rightbound - 1 <= leftbound)
            {
                check = 0;
            }
        }
        if (row_column == 1 && left_to_right == 0 && down_to_button == 0)
        {
            for (int i = rightbound - 1; i > leftbound; i--)
            {
                if (count < max)
                {
                    printf("%d ", arr[downbound - 1][i]);
                }
                else
                {
                    break;
                }
                count++;
            }
            downbound--;
            row_column = 0;
            left_to_right = 1;
            if (downbound - 1 <= upbound)
            {
                check = 0;
            }
        }
        if (row_column == 0 && left_to_right == 1 && down_to_button == 0)
        {
            for (int i = downbound - 1; i > upbound; i--)
            {
                if (count < max)
                {
                    printf("%d ", arr[i][leftbound + 1]);
                }
                else
                {
                    break;
                }
                count++;
            }
            leftbound++;
            row_column = 1;
            down_to_button = 1;
            if (leftbound + 1 >= rightbound)
            {
                check = 0;
            }
        }
    }

    return 0;
}