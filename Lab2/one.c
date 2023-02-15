#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *start = NULL;

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
        printf("None");
        return;
    }
    while (current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }
    // printf("\n");
}

// void ListNode_MainOps(struct ListNode *start)
// {
//     printf("\nMain Ops Start\n");
//     struct ListNode *current = start;
//     struct ListNode *previous = start;
//     while (current != NULL)
//     {
//         printf("\n Current Start \n");
//         int ops_done = 0;
//         // printf("%d , ",current->val);
//         struct ListNode *nextNode = current->next;
//         while (nextNode != NULL)
//         {
//             printf("\n Next Node Start\n");
//             // printf(" next: %d ",nextNode->val);
//             if (current->val == nextNode->val)
//             {
//                 current->next = nextNode->next;
//                 ops_done = 1;
//             }
//             nextNode = nextNode->next;
//         }
//         if (ops_done)
//         {
//             printf("\n Ops Done Start \n");
//             if (previous == start)
//             {
//                 start = current->next;
//                 current = start;
//                 previous = start;
//             }
//             else
//             {
//                 previous->next = current->next;
//             }
//             printf("\n Ops Done End \n");
//         }
//         else
//         {
//             previous = current;
//         }
//         if (current != NULL)
//         {
//             current = current->next;
//         }
//         printf("\n Current End \n");
//     }
//     printf("\nMain Ops End\n");
// }

void ListNode_MainOps()
{
    struct ListNode *previous = start;
    struct ListNode *current = start;
    struct ListNode *nextNode = current->next;
    while (current != NULL)
    {
        // printf("Previous: %d\n", previous->val);
        // printf("Current: %d\n", current->val);
        nextNode = current->next;
        int ops_done = 0;
        while ((nextNode != NULL) && (current->val == nextNode->val))
        {
            // printf("Next Node: %d\n", nextNode->val);
            ops_done = 1;
            nextNode = nextNode->next;
        }
        if (ops_done)
        {
            if (current->val == start->val)
            {
                // printf("Start case\n");
                start = nextNode;
            }else
            {
                previous->next = nextNode;
            }
        }
        else
        {
            previous = current;
        }
        
        current = nextNode;
        
        // if (nextNode == NULL)
        // {
        //     break;
        // }
        // if (ops_done)
        // {
        //     current = nextNode;
        //     previous->next = nextNode;
        //     if (current != NULL)
        //     {
        //         previous = current;
        //         current = current->next;
        //         // if(current!=NULL)
        //         //     nextNode = current->next;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        // else
        // {
        //     previous = current;
        //     current = current->next;
        //     // nextNode = current->next;
        // }
        // nextNode = current->next;

        // printf("\n");
    }
}

int char_to_int(char in_char)
{
    return (int)in_char - 48;
}

int main()
{
    char temp[5];
    int char_count = 0;
    int user_int;
    char user_char;
    int total_count = 0;
    while (scanf("%d%c",&user_int,&user_char)==2)
    {
        // printf("%d\n",user_int);
        start = insertEnd(start, user_int);
        total_count++;
        if((int)user_char!=32){
            break;
        }
    }
    // printf("after while\n");
    if(total_count!=0)
    {
        ListNode_MainOps();
        ListNode_Traverse(start);
    }else
    {
        printf("None");
    }
    
    // while (1)
    // {
    //     char temp_char;
    //     scanf("%c", &temp_char);
    //     if ((int)temp_char == 32)
    //     {
    //         int temp_int = 0;
    //         for (int i = char_count - 1; i >= 0; i--)
    //         {
    //             temp_int += char_to_int(temp[i]) * pow((double)10, (double)((char_count - 1) - i));
    //         }
    //         // printf("%d\n", temp_int);
    //         start = insertEnd(start, temp_int);
    //         char_count = 0;
    //     }
    //     else if ((int)temp_char == 69)
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         temp[char_count] = temp_char;
    //         char_count++;
    //     }
    // }
    // printf("\nBefore Main Ops\n");
    // ListNode_Traverse(start);
    return 0;
}