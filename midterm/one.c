#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *start = NULL;

int search(struct ListNode *start, int val)
{
    struct ListNode *current = start;
    while (current != NULL)
    {
        if (current->val == val)
        {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

struct ListNode *createNode(int val)
{
    start = (struct ListNode *)malloc(sizeof(struct ListNode));
    start->val = val;
    start->next = NULL;
    return start;
}

struct ListNode *insertFront(struct ListNode *start, int val)
{
    struct ListNode *pNew = createNode(val);
    pNew->next = start;
    start = pNew;
    return start;
}

struct ListNode *insertEnd(struct ListNode *start, int val)
{
    struct ListNode *pNew = createNode(val);
    if (start == NULL)
    {
        return pNew;
    }
    // Store front of the linked list
    struct ListNode *current = start;

    while (current->next != NULL)
    {
        // printf(" %d: ",current->val);
        current = current->next;
    }
    // Found the last node, link it to pNew
    current->next = pNew;
    return start;
}

void ListNode_Traverse(struct ListNode *start)
{
    // printf("start: %d",start);
    struct ListNode *current = start;
    if (current == NULL)
    {
        // printf("None");
        return;
    }
    while (current != NULL)
    {
        printf("%d", current->val);
        current = current->next;
        if(current!=NULL){
            printf(" ");
        }
    }
    // printf("\n");
}

void ListNode_Ops(struct ListNode *start)
{
    struct ListNode *current = start;
    while (current != NULL)
    {
        // printf("current: %d\n",current->val);
        struct ListNode *the_next = current->next;
        struct ListNode *previous = current;
        while (the_next != NULL)
        {
            if (current->val == the_next->val)
            {
                previous->next = the_next->next;
                the_next = the_next->next;
            }
            else
            {
                previous = the_next;
                the_next = the_next->next;
            }
        }
        current = current->next;
    }
}

int main()
{
    int user_int;
    char user_char;
    while (scanf("%d%c", &user_int, &user_char) == 2)
    {
        if (search(start, user_int) != 1)
        {
            start = insertEnd(start, user_int);
        }
        if ((int)user_char == 10)
        {
            break;
        }
    }
    // ListNode_Traverse(start);
    // ListNode_Ops(start);
    ListNode_Traverse(start);
    return 0;
}