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

void push(stack **top,int element,int *counter){
    stack *new;
    new = (stack *)malloc(sizeof(stack));
    if(new == NULL){
        printf("stack full");
        exit(-1);
    }
    new->value = element;
    new->next = *top;
    *top = new;
    counter++;
}

int pop (stack **top,int *counter){
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
        counter--;
        return t;
    }
}

int main(){
    stack *top;
    int counter = 0;
    int user_int;
    char user_char;
    create(&top);
    while (scanf("%d%c",&user_int,&user_char)==2)
    {
        push(&top,user_int,&counter);
        if((int)user_char!=32){
            break;
        }
    }
    
    int limit;
    scanf("%d",&limit);
    while (top!=NULL&&limit>0)
    {
        printf("%d ",pop(&top,&counter));
        limit--;
    }
    if(limit>0){
        printf("None");
    }
    return 0;
}