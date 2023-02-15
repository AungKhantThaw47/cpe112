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

void ListNode_MainOps(int start, int end, int total, struct ListNode *frontList, struct ListNode *endList)
{
    int count = (end - start) + 1;
    // printf("count: %d\n", count);
    int counter = 0;
    struct ListNode *current = frontList;
    int loop = 0;
    while ((current != NULL) && (loop < start - 1))
    {
        // printf("%d ", current->val);
        current = current->next;
        loop++;
    }
    struct ListNode *start_current = current;
    current = endList;
    loop = total;
    while ((current != NULL) && (loop > end))
    {
        // printf("%d ", current->val);
        current = current->next;
        loop--;
    }
    struct ListNode *end_current = current;
    loop = 0;
    while (loop < count)
    {
        start_current->val = end_current->val;
        start_current = start_current->next;
        end_current = end_current->next;
        loop++;
    }
    current = frontList;
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
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

    int start_index, end_index;
    scanf("%d %d", &start_index, &end_index);
    // printf("start index: %d , end index: %d\n", start_index, end_index);
    if (start_index != end_index)
    {
        ListNode_MainOps(start_index, end_index, total_count, startEnd, startStart);
    }
    else
    {
        struct ListNode *current = startEnd;
        while (current != NULL)
        {
            printf("%d ", current->val);
            current = current->next;
        }
    }

    return 0;
}