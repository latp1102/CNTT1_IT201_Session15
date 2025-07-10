#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Queue {
    int data[MAX];
    int front;
    int rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    return q;
}

void enQueue(Queue* q, int x) {
    if (q->rear < MAX - 1) {
        q->rear++;
        q->data[q->rear] = x;
    }
}

int deQueue(Queue* q) {
    if (q->front > q->rear) {
        printf("hàn doi trong\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front++;
    return value;
}

int searchQueue(Queue* q) {
    while (q->rear > q->front >= 1) {
        int a = deQueue(q);
        int b = q->data[q->front];
        if (b - a != 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    Queue* q = createQueue();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enQueue(q, x);
    }
    if (searchQueue(q)) {
        printf("true\n");
        return 0;
    } else {
        printf("false\n");
    }
    return 0;
}