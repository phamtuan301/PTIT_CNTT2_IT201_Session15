#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *array;
    int front;
    int rear;
    int size;
} Queue;
Queue createQueue(int size) {
    Queue q;
    q.array = (int *)malloc(size * sizeof(int));
    q.front = 0;
    q.rear = -1;
    q.size = size;
    return q;
}
void enQueue(Queue *q, int value) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}
void printQueue(Queue q) {
    printf("queue = {\n");
    printf("   array = [");
    for (int i = 0; i <= q.rear; i++) {
        printf("%d", q.array[i]);
        if (i < q.rear) printf(", ");
    }
    printf("],\n");
    printf("   front = %d,\n", q.front);
    printf("   rear = %d,\n", q.rear);
    printf("   capacity = %d\n", q.size);
    printf("},\n\n");
}
int isEmpty(Queue q) {
    if (q.rear < q.front) {
        return 1;
    }else {
        return 0;
    }
}
void deQueue(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }else {
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d\n", q.array[i]);
        }
    }
}
int main () {
    Queue q = createQueue(5);
    for (int i = 1; i <= 5; i++) {
        int value;
        printf("Nhap phan tu hang doi");
        scanf("%d", &value);
        enQueue(&q, value);
    }

   deQueue(q);
    free(q.array);
    return 0;
}