#include <stdio.h>
#include <string.h>

char* find_largest_number(char number[]) {
    char* largest_number = number;
    int length = strlen(number);

    for (int i = 0; i < length; i++) {
        char new_number[5];
        int index = 0;

        for (int j = 0; j < length; j++) {
            if (j != i) {
                new_number[index++] = number[j];
            }
        }
        new_number[index] = '\0';

        if (strcmp(new_number, largest_number) > 0) {
            strcpy(largest_number, new_number);
        }
    }

    return largest_number;
}

int main() {
    char number[5];
    printf("Enter a 4-digit number: ");
    scanf("%s", number);

    char* largest_number = find_largest_number(number);
    printf("The largest number is %s.\n", largest_number);

    return 0;
}
