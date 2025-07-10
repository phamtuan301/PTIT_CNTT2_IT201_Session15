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
int isIncreasing(Queue q) {
    for (int i = q.front; i < q.rear; i++) {
        if (q.array[i+1] - q.array[i] != 1) {
            return 0;
        }
    }
    return 1;
}
int main () {
    int n;
    printf("NHap so phan tu hang doi");
    scanf("%d", &n);
    Queue q = createQueue(n);
    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap phan tu hang doi");
        scanf("%d", &value);
        enQueue(&q, value);
    }
    if (isIncreasing(q)) {
        printf("True");
    }else {
        printf("False");
    }
    free(q.array);
    return 0;
}