#include "headers.h"

struct Queue* commandHistory;
extern int ccount;

int main() {
    char command[MAX_STRING_LENGTH];
    printf("\nWelcome to the \"Simple C Shell for File Operations\".\n");
    struct LinkedList fileList = {NULL, 0};
    struct Stack undoStack = {{}, -1};
    
    commandHistory = (struct Queue*)malloc(sizeof(struct Queue));
    commandHistory->front = 1;
    commandHistory->rear = -1;
    commandHistory->count = 1;
    
    startscreen();
    
    while (1) {
        printf("\033[1;32mSh3ll@An0n \033[0m>>> ");
        fflush(stdin);
        scanf("%s", command);
        executeCommand(command, &fileList, &undoStack, commandHistory);
        if (strcmp(command, "exit") == 0) {
            destroyList(&fileList);
            free(commandHistory);
            break;
        }
    }
    return 0;
}
