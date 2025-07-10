#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[30];
} customers;
typedef struct {
    customers queue[100];
    int front, rear;
    int size;
    int capacity;
} Queue;
void initQueue(Queue *q, int capacity) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
}
int isFull(Queue *q) {
    return q->size==q->capacity;
}
int isEmpty(Queue *q) {
    return q->size==0;
}
void enQueue(Queue *q, char name[]) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1)%q->capacity;
    strncpy(q->queue[q->rear].name, name, 30);
    q->size++;
}
void service (Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Khach hang dang phuc vu: %d", q->queue[q->front].name);
    q->front = (q->front+1)%q->capacity;
    q->size--;
}
void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Danh sach khach hang\n");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front+i)%q->capacity;
        printf("%s ", q->queue[index].name);
    }
}
int main () {
    Queue q;
    int capacity = 100;
    initQueue(&q, capacity);
    int choice;
    char name[30];
    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Them khach hang\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi danh sach khach\n");
        printf("4. Thoat\n");
        printf("Chon thao tac: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Nhap ten khach hang");
                fgets(name, 30, stdin);
                name[strcspn(name, "\n")] = 0;
                enQueue(&q, name);
                break;
            case 2:
                service(&q);
                break;
            case 3:
                printQueue(&q);
                break;
            case 4:
                printf("Thoat");
                return 0;
            default:
                printf("Vui long chon lai");
        }
    }
    return 0;
}