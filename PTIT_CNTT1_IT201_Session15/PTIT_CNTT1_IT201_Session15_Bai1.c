#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct Queue {
    int *data;
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

void enQueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("hang doi day\n");
        return;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int deQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("hang doi rong\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

void freeQueue(Queue* q) {
    free(q);
}

int main() {
    Queue* q = createQueue(5);

    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);

    printQueue(q);
    freeQueue(q);
    return 0;
}