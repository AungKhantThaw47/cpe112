#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    char val;
    struct ListNode *next;
};

typedef struct ListNode list;

struct lifo{
    list *value;
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

void push(stack **top,list *element){
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

list *pop (stack **top){
    list *t;
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

list *createNode(char val){
    list *start = (list *)malloc(sizeof(list));
    start->val = val;
    start->next = NULL;
    return start;
}

list *insertFront(list *start, char val){
    list *pNew = createNode(val);
    pNew->next = start;
    start = pNew;
    return start;
}

list *insertEnd(list *start, char val)
{
    list *pNew = createNode(val);
    if (start == NULL)
    {
        return pNew;
    }
    // Store front of the linked list
    list *current = start;

    while (current->next != NULL)
    {
        // printf(" %d: ",current->val);
        current = current->next;
    }
    // Found the last node, link it to pNew
    current->next = pNew;
    return start;
}

int main(){
    stack *stack_forward;
    stack *stack_forward_clone;
    stack *stack_backward;
    list *user_in = NULL;
    int user_int;
    char user_char;
    create(&stack_forward);
    create(&stack_forward_clone);
    create(&stack_backward);
    while (scanf("%c",&user_char)==1)
    {
        // push(&stack_forward,user_int);
        // printf("%c",user_char);
        if((int)user_char==10){
            push(&stack_forward,user_in);
            push(&stack_forward_clone,user_in);
            user_in = NULL;
            break;
        }else if ((int)user_char==32)
        {
            push(&stack_forward,user_in);
            push(&stack_forward_clone,user_in);
            user_in = NULL;
        }else
        {
            user_in = insertEnd(user_in,user_char);
        }
    }
    stack *temp = stack_forward_clone;
    while (stack_forward_clone!=NULL){
        list *temp_list = pop(&stack_forward_clone);
        // while (temp_list!=NULL)
        // {
        //     printf("%c",temp_list->val);
        //     temp_list = temp_list->next;
        // }
        // printf(" ");
        push(&stack_backward, temp_list);
        // stack_forward_clone = stack_forward_clone->next;
    }
    temp = stack_backward;
    while (temp!=NULL)
    {
        list *temp_list = temp->value;
        while (temp_list!=NULL)
        {
            printf("%c",temp_list->val);
            temp_list = temp_list->next;
        }
        printf(" ");
        temp = temp->next;
    }
    printf("\n");
    temp = stack_forward;
    while (temp!=NULL)
    {
        list *temp_list = temp->value;
        while (temp_list!=NULL)
        {
            printf("%c",temp_list->val);
            temp_list = temp_list->next;
        }
        printf(" ");
        temp = temp->next;
    }
    return 0;
}