#include <stdlib.h>
#include <stdio.h>

struct qnode
{
    int val;
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

void enqueue(QUEUE *q, int element)
{
    struct qnode *q1;
    q1 = (struct qnode *)malloc(sizeof(struct qnode));
    printf("working enqueue\n");
    q1->val = element;
    printf("working enqueue 1\n");
    q1->next = q->qfront;
    printf("working enqueue 2\n");
    q->qfront = q1;
    printf("working enqueue 3\n");
}

int dequeue(QUEUE *q)
{
    int val;
    struct qnode *q1, *prev = NULL;
    printf("working dequeue\n");
    q1 = q->qfront;
    // prev = q1;
    printf("working dequeue 1\n");
    while (q1->next != NULL)
    {
        printf("working dequeue 2\n");
        prev = q1;
        printf("working dequeue 3\n");
        q1 = q1->next;
        printf("working dequeue 4\n");
    }
    printf("working dequeue 5\n");
    val = q1->val;
    printf("working dequeue 6\n");
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    printf("working dequeue 7\n");
    free(q1);
    printf("working dequeue 8\n");
    return val;
}

int main()
{
    QUEUE q;
    create_queue(&q);
    enqueue(&q, 1);
    dequeue(&q);
    return 0;
}