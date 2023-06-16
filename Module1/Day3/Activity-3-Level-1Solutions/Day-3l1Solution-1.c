#include <stdio.h>

void printNumbersAscending(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
    }
}

void printNumbersDescending(int n) {
    for (int i = n; i >= 1; i--) {
        printf("%d", i);
    }
}

void printPattern(int n) {
    for (int i = n; i >= 1; i--) {
        printNumbersAscending(i);
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        printNumbersDescending(i);
        printf("\n");
    }
}

int main() {
    
    int a;
    printf("\n Enter a number:");
    scanf("%d",&a);
    printPattern(a);
    return 0;
}
