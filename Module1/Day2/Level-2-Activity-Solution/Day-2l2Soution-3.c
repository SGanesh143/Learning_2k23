#include <stdio.h>
#include <string.h>

void sort_names(char **names, int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j < size; j++) {
      if (strcmp(names[i], names[j]) > 0) {
        char *temp = names[i];
        names[i] = names[j];
        names[j] = temp;
      }
    }
  }
}

int main() {
  char *names[] = {
    "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
  };

  int size = sizeof(names) / sizeof(names[0]);

  sort_names(names, size);

  for (int i = 0; i < size; i++) {
    printf("%s\n", names[i]);
  }

  return 0;
}
