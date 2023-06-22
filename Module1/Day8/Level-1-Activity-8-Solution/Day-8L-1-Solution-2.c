#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void copyFile(const char *sourcePath, const char *targetPath, char option) {
    FILE *sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Error opening source file.\n");
        exit(1);
    }

    FILE *targetFile = fopen(targetPath, "w");
    if (targetFile == NULL) {
        printf("Error creating target file.\n");
        exit(1);
    }

    int ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        if (option == 'u') {
            fputc(toupper(ch), targetFile);
        } else if (option == 'l') {
            fputc(tolower(ch), targetFile);
        } else if (option == 's') {
            if (ch == ' ' || ch == '\n') {
                fputc(ch, targetFile);
            } else {
                fputc(tolower(ch), targetFile);
            }
        } else {
            fputc(ch, targetFile);
        }
    }

    fclose(sourceFile);
    fclose(targetFile);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source file> <target file> [option]\n", argv[0]);
        printf("Options:\n");
        printf("  -u: Convert to uppercase\n");
        printf("  -l: Convert to lowercase\n");
        printf("  -s: Convert to sentence case\n");
        return 1;
    }

    const char *sourcePath = argv[1];
    const char *targetPath = argv[2];
    char option = 'n'; // Default option is normal copy

    if (argc >= 4) {
        if (strlen(argv[3]) != 2 || argv[3][0] != '-') {
            printf("Invalid option: %s\n", argv[3]);
            return 1;
        }
        option = argv[3][1];
    }

    copyFile(sourcePath, targetPath, option);

    printf("File copied successfully.\n");

    return 0;
}
