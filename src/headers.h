#ifndef HEADERS_H
#define HEADERS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_FILE_NAME_LENGTH 50
#define MAX_STRING_LENGTH 100
#define MAX_HISTORY_SIZE 10

struct Node {
    char fileName[MAX_FILE_NAME_LENGTH];
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
    int size;
};

struct Stack {
    char history[MAX_HISTORY_SIZE][MAX_FILE_NAME_LENGTH];
    int top;
};

struct Queue {
    char history[MAX_HISTORY_SIZE][MAX_FILE_NAME_LENGTH];
    int front, rear, count;
};

extern struct Queue* commandHistory;

void pushOperation(struct Stack* undoStack, char* fileName);
void push(struct Stack* stack, char* data);
char* pop(struct Stack* stack);
void enqueue(struct Queue* queue, char* data);
char* dequeue(struct Queue* queue);
void destroyList(struct LinkedList* fileList);
void writeFile(struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory);
void appendFile(struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory);
void readFile(struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory);
void removes(struct LinkedList* fileList);
void renames(struct LinkedList* fileList);
void cdir(struct LinkedList* fileList);
void copy(struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory);
void cknow(struct LinkedList* fileList);
void lknow(struct LinkedList* fileList);
void displayCommandCount(struct Queue* commandHistory);
void gcd();
void lcm();
void tconv();
void executeCommand(char* command, struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory);
void exits(struct LinkedList* fileList);
void startscreen();
void clear();
void help();

#endif
