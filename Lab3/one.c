#include<stdio.h>
#include<stdlib.h>

struct lifo{
    char value;
    struct lifo *next;
};

typedef struct lifo stack;

stack *top;

void create(stack **top){
    *top = NULL;
}

// void create(){
//     top = NULL;
// }

void push(stack **top,char element){
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

char pop (stack **top){
    char t;
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
    create(&top);
    char user_char;
    while (scanf("%c",&user_char)==1)
    {
        // printf("%c\n",user_char);
        if((int)user_char==10){
            break;
        }
        push(&top,user_char);
    }
    printf("output");
    return 0;
}