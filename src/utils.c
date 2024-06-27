#include "headers.h"

void cknow(struct LinkedList* fileList) {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        printf("\033[1;31mError: Unable to get current working directory.\033[0m\n");
    }
    (void)fileList;
}

void lknow(struct LinkedList* fileList) {
    printf("Available commands: read, write, append, removes, renames, cdir, copy, cknow, lknow, ccount, gcd, lcm, tconv, exits, help, clear\n");
    (void)fileList;
}

void gcd() {
    int a, b, gcd, temp;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;
    printf("GCD: %d\n", gcd);
}

void lcm() {
    int a, b, gcd, lcm, temp, tempA, tempB;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    tempA = a;
    tempB = b;
    while (tempB != 0) {
        tempA %= tempB;
        temp = tempA;
        tempA = tempB;
        tempB = temp;
    }
    gcd = tempA;
    lcm = (a * b) / gcd;
    printf("LCM: %d\n", lcm);
}

void tconv() {
    float temp;
    char unit;
    printf("Enter temperature (e.g., 100C or 212F): ");
    scanf("%f%c", &temp, &unit);
    if (unit == 'C' || unit == 'c') {
        printf("Fahrenheit: %.2fF\n", (temp * 9/5) + 32);
    } else if (unit == 'F' || unit == 'f') {
        printf("Celsius: %.2fC\n", (temp - 32) * 5/9);
    } else {
        printf("\033[1;31mInvalid unit.\033[0m\n");
    }
}

void exits(struct LinkedList* fileList) {
    destroyList(fileList);
    printf("Exiting the shell...\n");
    displayCommandCount(commandHistory);
    exit(0);
}
