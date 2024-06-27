#include "headers.h"

void push(struct Stack* stack, char* data) {
    if (stack->top < MAX_HISTORY_SIZE - 1) {
        strcpy(stack->history[++stack->top], data);
    }
}

char* pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->history[stack->top--];
    }
    return NULL;
}

void enqueue(struct Queue* queue, char* data) {
    if (queue->count < MAX_HISTORY_SIZE) {
        queue->rear = (queue->rear + 1) % MAX_HISTORY_SIZE;
        strcpy(queue->history[queue->rear], data);
        queue->count++;
    }
}

char* dequeue(struct Queue* queue) {
    if (queue->count > 0) {
        char* data = queue->history[queue->front];
        queue->front = (queue->front + 1) % MAX_HISTORY_SIZE;
        queue->count--;
        return data;
    }
    return NULL;
}

void destroyList(struct LinkedList* fileList) {
    struct Node* current = fileList->head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    fileList->head = NULL;
    fileList->size = 0;
}
