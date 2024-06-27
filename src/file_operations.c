#include "headers.h"

void readFile(struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory) {
    char fileName[MAX_FILE_NAME_LENGTH];
    char c;
    FILE* file;
    printf("Use .txt or any other extension to read\nEx: hello.txt\n\n");
    printf("Enter File Name To Read: ");
    scanf("%s", fileName);
    if ((file = fopen(fileName, "r")) == NULL) {
        printf("\033[1;31mError\033[0m\n");
        return;
    }
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }
    fclose(file);
    printf("\n\n \033[1;32mSuccessfully Read\033[0m\n");
    (void)fileList;
    (void)undoStack;
    (void)commandHistory;
}

void writeFile(struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory) {
    char fileName[MAX_FILE_NAME_LENGTH], ch;
    printf("Use .txt or any other extension to write\nEx: hello.txt\n\n");
    printf("Enter File Name To Write: ");
    scanf("%s", fileName);
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        printf("\033[1;31mError: Unable to open or create the file\033[0m\n");
        return;
    }
    printf("Enter ~ on a new line to exit from writing\nStart writing: \n");
    getchar();
    while (1) {
        ch = getchar();
        if (ch == '~' && getchar() == '\n') {
            break;
        }
        fputc(ch, file);
    }
    fclose(file);
    printf("\n\n \033[1;32mSuccessfully Written\033[0m\n");
    enqueue(commandHistory, "write");
    pushOperation(undoStack, fileName);
    commandHistory->count--;
    (void)fileList;
}

void appendFile(struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory) {
    char fileName[MAX_FILE_NAME_LENGTH], ch;
    printf("Use .txt or any other extension to append\nEx: hello.txt\n\n");
    printf("Enter File Name To Append: ");
    scanf("%s", fileName);
    FILE* file = fopen(fileName, "a");
    if (file == NULL) {
        printf("\033[1;31mError: Unable to open the file\033[0m\n");
        return;
    }
    printf("Enter ~ on a new line to exit from appending\nStart writing: \n");
    getchar(); 
    while (1) {
        ch = getchar();
        if (ch == '~' && getchar() == '\n') {
            break;
        }
        fputc(ch, file);
    }
    fclose(file);
    printf("\n\n \033[1;32mSuccessfully Appended\033[0m\n");
    enqueue(commandHistory, "append");
    pushOperation(undoStack, fileName);
    commandHistory->count--;
    (void)fileList;
}

void removes(struct LinkedList* fileList) {
    char fileName[MAX_FILE_NAME_LENGTH];
    printf("Enter the file name to remove: ");
    scanf("%s", fileName);
    if (remove(fileName) == 0) {
        printf("\033[1;32mFile removed successfully.\033[0m\n");
    } else {
        printf("\033[1;31mError: Unable to remove file.\033[0m\n");
    }
    (void)fileList;
}

void renames(struct LinkedList* fileList) {
    char oldName[MAX_FILE_NAME_LENGTH], newName[MAX_FILE_NAME_LENGTH];
    printf("Enter the current file name: ");
    scanf("%s", oldName);
    printf("Enter the new file name: ");
    scanf("%s", newName);
    if (rename(oldName, newName) == 0) {
        printf("\033[1;32mFile renamed successfully.\033[0m\n");
    } else {
        printf("\033[1;31mError: Unable to rename file.\033[0m\n");
    }
    (void)fileList;
}

void cdir(struct LinkedList* fileList) {
    system("ls -l");
    (void)fileList;
}

void copy(struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory) {
    char source[MAX_FILE_NAME_LENGTH], destination[MAX_FILE_NAME_LENGTH], ch;
    printf("Enter the source file name: ");
    scanf("%s", source);
    printf("Enter the destination file name: ");
    scanf("%s", destination);
    FILE* src = fopen(source, "r");
    FILE* dest = fopen(destination, "w");
    if (src == NULL || dest == NULL) {
        printf("\033[1;31mError: Unable to open file.\033[0m\n");
        return;
    }
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
    fclose(src);
    fclose(dest);
    printf("\033[1;32mFile copied successfully.\033[0m\n");
    (void)fileList;
    (void)undoStack;
    (void)commandHistory;
}

void pushOperation(struct Stack* undoStack, char* fileName) {
    if (undoStack->top < MAX_HISTORY_SIZE - 1) {
        undoStack->top++;
        strcpy(undoStack->history[undoStack->top], fileName);
    }
}
