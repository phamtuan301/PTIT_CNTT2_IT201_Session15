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
void printQueue(Queue q) {
    printf("front=%d, rear=%d\n", q.front, q.rear);
    printf("size=%d\n", q.size);
}
int main () {
    int n;
    printf("NHap so phan tu cua hang doi");
    scanf("%d", &n);
    Queue q = createQueue(n);
    printQueue(q);
    free(q.array);
    return 0;
}