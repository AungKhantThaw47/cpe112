#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *startEnd = NULL;
struct ListNode *startStart = NULL;

struct ListNode *createNode(int val)
{
    struct ListNode *start = (struct ListNode *)malloc(sizeof(struct ListNode));
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

int main()
{
    int user_int;
    char user_char;
    int total_count = 0;
    while (scanf("%d", &user_int) == 1)
    {
        // printf("%d ",user_int);
        startEnd = insertEnd(startEnd, user_int);
        startStart = insertFront(startStart, user_int);
        total_count++;
        // if((int)user_char!=32){
        //     break;
        // }
    }
    // printf("\n");
    while (scanf("%c", &user_char) == 1)
    {
        // printf("%d ", (int)user_char);
        if (user_char == 10)
        {
            break;
        }
    }
    return 0;
}