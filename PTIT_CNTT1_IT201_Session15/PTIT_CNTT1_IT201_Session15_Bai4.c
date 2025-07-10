#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Queue {
    int data[MAX];
    int front;
    int rear;
    int cap;
} Queue;

Queue* createQueue(int cap) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->cap = cap;
    return q;
}

int isEmpty(Queue* q) {
    return q->front > q->rear;
}

int isFull(Queue* q) {
    return q->rear == q->cap - 1;
}

void enQueue(Queue* q, int x) {
    if (q->rear == q->cap - 1) {
        printf("hang doi day\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = x;
}

void viewQueue(Queue* q) {
    if (q->front > q->rear) {
        printf("hang doi trong\n");
        return;
    }
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

void printQueue(Queue* q) {
    printf("queue = \n");
    printf("arr = ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
    printf("front = %d\n", q->front);
    printf("rear = %d\n", q->rear);
    printf("cap = %d\n", q->cap);
}

int main() {
    Queue* q = createQueue(5);
    printQueue(q);
    viewQueue(q);
    return 0;
}