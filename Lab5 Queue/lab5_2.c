//66070503413 Channathat Ueanapaphon
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct 
{
    int front;
    int rear;
    int size;
    int queue[MAX_SIZE];
} Queue;

int isFull(Queue *q) 
{
    if ((q->front == 0 && q->rear == q->size - 1) || (q->front == q->rear + 1)) 
 {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q) 
{
    if (q->front == -1) 
 {
        return 1;
    }
    return 0;
}

void insertQ(Queue *q, int value) 
{
    if (isFull(q))
 {
        printf("Queue is full!!\n");
        return;
    }
    if (q->front == -1) 
 {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size;
    q->queue[q->rear] = value;
}

int deleteQ(Queue *q) 
{
    int value;
    if (isEmpty(q)) 
 {
        printf("Queue is empty!!\n");
        return -1;
    }
    value = q->queue[q->front];
    if (q->front == q->rear) 
 {
        q->front = -1;
        q->rear = -1;
    }
    else {
        q->front = (q->front + 1) % q->size;
    }
    return value;
}

void showQ(Queue *q) 
{
    int i, count;
    if (isEmpty(q)) 
 {
        printf("Queue is empty!!\n");
        return;
    }
    
    printf("Front: %d\n", q->front);
    printf("Items: ");
    count = (q->rear + q->size - q->front) % q->size + 1;
    
    for (i = 0; i < count; i++) 
 {
        printf("%d ", q->queue[(q->front + i) % q->size]);
    }
    printf("\nRear: %d\n", q->rear);
}

int main() 
{
    Queue q;
    int value;
    char cmd;

    scanf("%d", &q.size);
    q.front = -1;
    q.rear = -1;

    while (1) 
 {
        scanf(" %c", &cmd);
        
        if (cmd == 'E') 
  {
            break;
        }
        else if (cmd == 'I')
  {
            scanf("%d", &value);
            insertQ(&q, value);
        }
        else if (cmd == 'D')
  {
            if (isEmpty(&q)) {
                printf("Queue is empty!!\n");
            } else {
                printf("%d\n", deleteQ(&q));
            }
        }
        else if (cmd == 'S') 
  {
            showQ(&q);
        }
    }

    return 0;
}