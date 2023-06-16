#include <stdio.h>

int findSmallestAndLargestDigits(int *n, int size, int *smallestDigit, int *largestDigit) {
    *smallestDigit = 9;
    *largestDigit = 0;

    for (int i = 0; i < size; i++) {
        int number = n[i];
        while (number > 0) {
            int digit = number % 10;
            number /= 10;

            if (digit < *smallestDigit) {
                *smallestDigit = digit;
            }
            if (digit > *largestDigit) {
                *largestDigit = digit;
            }
        }
    }

    if (*smallestDigit > *largestDigit) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int n;
    printf("Enter the number of numbers: ");
    scanf("%d", &n);

    int numbers[n];
    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    int smallestDigit, largestDigit;
    int isValid = findSmallestAndLargestDigits(numbers, n, &smallestDigit, &largestDigit);

    if (isValid) {
        printf("The smallest digit is %d and the largest digit is %d.\n", smallestDigit, largestDigit);
    } else {
        printf("The numbers are not valid.\n");
    }

    return 0;
}
