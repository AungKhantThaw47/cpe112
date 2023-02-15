#include<stdio.h>
#include<stdlib.h>

struct lifo{
    int value;
    struct lifo *next;
};

typedef struct lifo stack;

// stack *top;

void create(stack **top){
    *top = NULL;
}

// void create(){
//     top = NULL;
// }

void push(stack **top,int element){
    stack *new;
    new = (stack *)malloc(sizeof(stack));
    if(new == NULL){
        printf("stack full");
        exit(-1);
    }
    new->value = element;
    new->next = *top;
    *top = new;
}

int pop (stack **top){
    int t;
    stack *p;
    if(*top==NULL){
        printf("stack empty");
        exit(-1);
    }else
    {
        t = (*top)->value;
        p = *top;
        *top = (*top)->next;
        free(p);
        return t;
    }
    
}

int main(){
    stack *stack_forward;
    stack *stack_backward;
    int user_int;
    char user_char;
    create(&stack_forward);
    create(&stack_backward);
    while (scanf("%d%c",&user_int,&user_char)==2)
    {
        push(&stack_forward,user_int);
        printf("%d ",user_int);
        if((int)user_char!=32){
            break;
        }
    }
    printf("\n");
    // printf("output\n");
    while (stack_forward!=NULL)
    {
        int temp = pop(&stack_forward);
        printf("%d ",temp);
        // push(&stack_backward,temp);
    }
    
    // while (stack_backward!=NULL){
    //     int temp = pop(&stack_backward);
    //     // printf("%d ",temp);
    // }
    return 0;
}