#include <stdio.h>
#include <stdlib.h>
// #include<string.h>

struct lifo
{
    char value;
    struct lifo *next;
};

typedef struct lifo stack;

void create(stack **top)
{
    *top = NULL;
}

// void create(){
//     top = NULL;
// }

void push(stack **top, char element)
{
    stack *new;
    new = (stack *)malloc(sizeof(stack));
    if (new == NULL)
    {
        printf("stack full");
        exit(-1);
    }
    new->value = element;
    new->next = *top;
    *top = new;
}

char pop(stack **top)
{
    char t;
    stack *p;
    if (*top == NULL)
    {
        return (char)10;
    }
    else
    {
        t = (*top)->value;
        p = *top;
        *top = (*top)->next;
        free(p);
        return t;
    }
}

int strcmp(stack **str1, stack **str2)
{
    stack *temp1 = *str1;
    stack *temp2 = *str2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (pop(&temp1) != pop(&temp2))
        {
            return 1;
        }
    }
    if (temp1 == NULL && temp2 == NULL)
    {
        return 0;
    }else
    {
        return 1;
    }
    
}

// void stack_traverse(stack **top){
//     stack *temp = top;
//     while (temp!=NULL)
//     {
//         printf("%c",pop(&temp));
//     }
//     printf("\n");
// }

int main()
{
    stack *s1;
    stack *s2;
    create(&s1);
    create(&s2);
    char user_char;
    while (scanf("%c", &user_char) == 1)
    {
        // printf("%c\n",user_char);
        if ((int)user_char == 10)
        {
            break;
        }
        push(&s1, user_char);
    }
    // scanf()
    while (scanf("%c", &user_char) == 1)
    {
        // printf("%c\n",user_char);
        if ((int)user_char == 10)
        {
            break;
        }
        push(&s2, user_char);
    }
    // stack *temp = s1;
    // while (s1!=NULL)
    // {
    //     printf("%c",pop(&s1));
    // }
    // temp = s2;
    // while (s2!=NULL)
    // {
    //     printf("%c",pop(&s2));
    // }
    printf("%d", strcmp(&s1, &s2));
    return 0;
}