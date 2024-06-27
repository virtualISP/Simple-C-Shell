#include "headers.h"

void executeCommand(char* command, struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory) {
    if (strcmp(command, "read") == 0) {
        readFile(fileList, undoStack, commandHistory);
    } else if (strcmp(command, "write") == 0) {
        writeFile(fileList, undoStack, commandHistory);
    } else if (strcmp(command, "append") == 0) {
        appendFile(fileList, undoStack, commandHistory);
    } else if (strcmp(command, "removes") == 0) {
        removes(fileList);
    } else if (strcmp(command, "renames") == 0) {
        renames(fileList);
    } else if (strcmp(command, "cdir") == 0) {
        cdir(fileList);
    } else if (strcmp(command, "copy") == 0) {
        copy(fileList, undoStack, commandHistory);
    } else if (strcmp(command, "cknow") == 0) {
        cknow(fileList);
    } else if (strcmp(command, "lknow") == 0) {
        lknow(fileList);
    } else if (strcmp(command, "ccount") == 0) {
        displayCommandCount(commandHistory);
    } else if (strcmp(command, "gcd") == 0) {
        gcd();
    } else if (strcmp(command, "lcm") == 0) {
        lcm();
    } else if (strcmp(command, "tconv") == 0) {
        tconv();
    } else if (strcmp(command, "exits") == 0) {
        exits(fileList);
    } else if (strcmp(command, "help") == 0) {
        help();
    } else if (strcmp(command, "clear") == 0) {
        clear();
    } else {
        printf("\033[1;31mInvalid command. Type 'help' for the list of commands.\033[0m\n");
    }
    commandHistory->count++;
}

void writeFile(struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory);
void appendFile(struct LinkedList* fileList, struct Stack* undoStack, struct Queue* commandHistory);

void startscreen() {
    printf("\nMade by virtualISP.\nFollow me on GitHub https://github.com/virtualISP\n");
    printf("\nCommands:\n");
    printf("1. read\t\t\t\t\t\t\t2. write\n3. append\t\t\t\t\t\t4. removes\n5. renames\t\t\t\t\t\t");
    printf("6. cdir\n7. copy\t\t\t\t\t\t\t8. cknow\n9. lknow\t\t\t\t\t\t10. ccount\n11. gcd\t\t\t\t\t\t\t12. lcm\n");
    printf("13. tconv\t\t\t\t\t\t14. exits\n15. help\t\t\t\t\t\t16. clear\n\n");
    printf("Total number of commands executed: 0\n\n");
}

void displayCommandCount(struct Queue* commandHistory) {
    printf("Total number of commands executed: %d\n", commandHistory->count);
}

void clear() {
    printf("\033[H\033[J");
}

void help() {
    printf("\nHelp - List of Commands:");
    printf("\n1. read\n Usage: read");
    printf("\n Description: Read the contents of a file.");
    printf("\n\n2. write\n Usage: write");
    printf("\n Description: Write content to a new file or overwrite an existing file.");
    printf("\n\n3. append\n Usage: append");
    printf("\n Description: Append content to an existing file.");
    printf("\n\n4. removes\n Usage: removes");
    printf("\n Description: Remove a file from the directory.");
    printf("\n\n5. renames\n Usage: renames");
    printf("\n Description: Rename a file.");
    printf("\n\n6. cdir\n Usage: cdir");
    printf("\n Description: List files in the current directory.");
    printf("\n\n7. copy\n Usage: copy");
    printf("\n Description: Copy the contents of one file to another.");
    printf("\n\n8. cknow\n Usage: cknow");
    printf("\n Description: Display the current working directory.");
    printf("\n\n9. lknow\n Usage: lknow");
    printf("\n Description: List all known commands.");
    printf("\n\n10. ccount\n Usage: ccount");
    printf("\n Description: Display the total number of commands executed.");
    printf("\n\n11. gcd\n Usage: gcd");
    printf("\n Description: Find the Greatest Common Divisor of two numbers.");
    printf("\n\n12. lcm\n Usage: lcm");
    printf("\n Description: Find the Least Common Multiple of two numbers.");
    printf("\n\n13. tconv\n Usage: tconv");
    printf("\n Description: Convert temperature between Celsius and Fahrenheit.");
    printf("\n\n14. exits\n Usage: exits");
    printf("\n Description: Exit the interpreter.");
    printf("\n\n15. help\n Usage: help");
    printf("\n Description: Display this help message.");
    printf("\n\n16. clear\n Usage: clear");
    printf("\n Description: Clear the screen.");
    printf("\n");
}




