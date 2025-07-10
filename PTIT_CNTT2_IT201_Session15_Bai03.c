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
int main () {
    Queue q = createQueue(5);

    if (isEmpty(q)) {
        printf("True");
    }else {
        printf("False");
    }
    Queue q1 = createQueue(5);
    q1.array[0] = 1;
    q1.rear = 0;
    if (isEmpty(q1)) {
        printf("True");
    }else {
        printf("False");
    }
    free(q.array);
    free(q1.array);
    return 0;
}