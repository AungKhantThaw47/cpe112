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

int main_ops(struct ListNode *startList,struct ListNode *endList,int len){
    int ops_done = 0;
    // struct ListNode *current = startList;
    // while (current != NULL)
    // {
    //     printf("%d ", current->val);
    //     current = current->next;
    // }
    // printf("\n");
    // current = endList;
    // while (current != NULL)
    // {
    //     printf("%d ", current->val);
    //     current = current->next;
    // }

    struct ListNode *currentStart = startList;
    struct ListNode *currentEnd = endList;
    int counter = 0;
    int limit = len / 2;
    int loc = -1;
    // printf("len %d : limit %d\n", len, limit);
    while ( (currentStart!=NULL) && (counter<limit) )
    {
        // printf("%d : %d\n", currentStart->val,currentEnd->val);
        if(currentStart->val!=currentEnd->val){
            struct ListNode *next = currentStart->next;
            // printf("Current: %d , Next: %d , Reverse: %d , Counter: %d\n", currentStart->val, next->val, currentEnd->val,counter);
            if(currentStart->val==next->val){
                if(counter==(limit-1) && counter%2==0)
                {
                    return counter;
                }
                loc = len-(counter+1);
            }else
            {
                return counter;
            }
            
        }
        counter++;
        currentStart = currentStart->next;
        currentEnd = currentEnd->next;
    }
    return loc;
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
    int result = main_ops(startEnd, startStart, total_count);
    if(result!= -1){
        printf("%d", result);
    }
    else
    {
        printf("None");
    }
    // printf("\nResult : %d\n", result);
    return 0;
}