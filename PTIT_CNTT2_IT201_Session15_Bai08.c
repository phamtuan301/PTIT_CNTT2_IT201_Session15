#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[30];
    int age;
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
void enQueue(Queue *q, customers item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1)%q->capacity;
    q->queue[q->rear] = item;
    q->size++;
}
customers deQueue(Queue *q) {
    customers item = {"", -1};
    if (isEmpty(q)) {
        return item;
    }
    item = q->queue[q->front];
    q->front = (q->front + 1)%q->capacity;
    q->size--;
    return item;
}
void printQueue(Queue *q, char *label) {
    if (isEmpty(q)) {
        printf("Trong\n");
        return;
    }
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        printf("   %s (%d tuoi)\n", q->queue[index].name, q->queue[index].age);
    }
}
int main () {
    Queue queueOld, queueNormal;
    initQueue(&queueOld, 100);
    initQueue(&queueNormal, 100);

    int choice;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Them khach hang\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi danh sach cho\n");
        printf("4. Thoat\n");
        printf("Chon thao tac: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            customers c;
            printf("Nhap ten khach hang: ");
            fgets(c.name, sizeof(c.name), stdin);
            c.name[strcspn(c.name, "\n")] = 0;

            printf("Nhap tuoi: ");
            scanf("%d", &c.age);
            getchar();

            if (c.age >= 60) {
                enQueue(&queueOld, c);
            } else {
                enQueue(&queueNormal, c);
            }

        } else if (choice == 2) {
            if (!isEmpty(&queueOld)) {
                customers served = deQueue(&queueOld);
                printf("Khach hang uu tien: %s (%d tuoi)\n", served.name, served.age);
            } else if (!isEmpty(&queueNormal)) {
                customers served = deQueue(&queueNormal);
                printf("Khach hang thuong: %s (%d tuoi)\n", served.name, served.age);
            } else {
                printf("Hang cho dang trong\n");
            }

        } else if (choice == 3) {
            printQueue(&queueOld, "Khach hang uu tien (>= 60 tuoi)");
            printQueue(&queueNormal, "Khach hang thuong (< 60 tuoi)");

        } else if (choice == 4) {
            printf("Thoat\n");
            break;
        } else {
            printf("Vui long chon lai\n");
        }
    }
    return 0;
}