#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    char val;
    struct ListNode *next;
};

typedef struct ListNode list;

struct qnode
{
    list *val;
    int priority;
    struct qnode *next;
};
struct queue
{
    struct qnode *qfront, *qrear;
};

typedef struct queue QUEUE;

void create_queue(QUEUE *q)
{
    q->qfront = NULL;
    q->qrear = NULL;
}

void enqueue(QUEUE *q, list *element,int priority)
{
    struct qnode *q1;
    q1 = (struct qnode *)malloc(sizeof(struct qnode));
    // printf("working enqueue\n");
    q1->val = element;
    q1->priority = priority;
    // printf("working enqueue 0\n");
    struct qnode *tempq = q->qfront;
    // printf("working enqueue 1\n");
    struct qnode *prev=NULL;
    // printf("working enqueue 2\n");
    if(tempq==NULL){
        q1->next = q->qfront;
        q->qfront = q1;
        return;
    }
    while(tempq!=NULL){
        // printf("pri: %d\n",tempq->priority);
        
        // printf("working enqueue 4\n");
        if(tempq->priority<=priority){
            break;
        }
        // printf("working enqueue 3\n");
        prev = tempq;
        tempq = tempq->next;
        // printf("working enqueue 5\n");
    }
    // printf("working enqueue 6\n");
    if(prev!=NULL){
        // printf("working enqueue 7\n");
        q1->next = tempq;
        // printf("working enqueue 8\n");
        prev->next = q1;
        // printf("working enqueue 9\n");
    }else
    {
        // printf("working enqueue 10\n");
        q1->next = q->qfront;
        // printf("working enqueue 11\n");
        q->qfront = q1;
        // printf("working enqueue 12\n");
    }
    // printf("working enqueue 13\n");
    // q1->next = q->qfront;
    // printf("working enqueue 2\n");
    // q->qfront = q1;
    // printf("working enqueue 3\n");
}

list *dequeue(QUEUE *q)
{
    list *val;
    struct qnode *q1, *prev = NULL;
    q1 = q->qfront;
    while (q1->next != NULL)
    {
        prev = q1;
        q1 = q1->next;
    }
    val = q1->val;
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    else
    {
        q->qfront = NULL;
    }

    free(q1);
    return (val);
}

int size(QUEUE *q)
{
    struct qnode *q1;
    int count = 0;
    q1 = q->qfront;
    while (q1 != NULL)
    {
        q1 = q1->next;
        count++;
    }
    return count;
}

list *peek(QUEUE *q)
{
    struct qnode *q1;
    q1 = q->qfront;
    while (q1->next != NULL)
        q1 = q1->next;
    return (q1->val);
}

list *createNode(char val)
{
    list *start = (list *)malloc(sizeof(list));
    start->val = val;
    start->next = NULL;
    return start;
}

list *insertFront(list *start, char val)
{
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

void traverse_list(list *start)
{

    list *current = start;
    while (current != NULL)
    {
        printf("%c", current->val);
        current = current->next;
    }
}

int main()
{
    QUEUE myq;
    int counter =0;
    create_queue(&myq);
    int myint;
    char testchar;
    while (1)
    {
        list *mylist = NULL;
        char user_char;
        while (scanf("%c", &user_char))
        {
            if ((int)user_char == 32)
            {
                break;
            }
            mylist = insertEnd(mylist, user_char);
        }
        // traverse_list(mylist);
        scanf("%d%c", &myint, &testchar);
        enqueue(&myq, mylist,myint);
        counter++;
        if ((int)testchar == 10)
        {
            break;
        }
    }
    int limit;
    scanf("%d",&limit);
    int trav = limit;
    for (int i = 0; i < limit && i < counter; i++)
    {
        traverse_list(dequeue(&myq));
        printf(" ");
        trav--;
    }
    // printf("\n tra: %d\n",trav);
    if(trav>0){
        printf("None");
    }
}