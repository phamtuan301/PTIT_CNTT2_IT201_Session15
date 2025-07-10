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
int isEmpty(Queue q) {
    if (q.rear < q.front) {
        return 1;
    }else {
        return 0;
    }
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
int deQueue(Queue *q) {
    if (isEmpty(*q)) {
        printf("Queue is empty\n");
        return -1;
    }else {
        int value = q->array[q->front];
        q->front++;
        return value;
    }

}
int main () {
    Queue q = createQueue(5);
    int result = deQueue(&q);
    if (result == -1) {
        printf("Queue is empty\n");
    }else {
        printf("%d\n", result);
    }
    Queue q2 = createQueue(5);
    q2.array[0] = 1;
    q2.array[1] = 2;
    q2.rear = 1;
    int result1 = deQueue(&q2);
    if (result1 == -1) {
        printf("Queue is empty\n");
    }else {
        printf("%d\n", result1);
    }
    free(q.array);
    return 0;
}