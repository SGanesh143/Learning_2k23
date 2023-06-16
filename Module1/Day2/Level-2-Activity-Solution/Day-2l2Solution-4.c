#include <stdio.h>

char *xstrchr(char *string, char ch) {
  for (; *string != '\0'; string++) {
    if (*string == ch) {
      return string;
    }
  }

  return NULL;
}

int main() {
  char *string = "Hello, world!";
  char *found_ch = xstrchr(string, 'l');

  if (found_ch != NULL) {
    printf("The character 'l' was found at position %ld.\n", found_ch - string);
  } else {
    printf("The character 'l' was not found.\n");
  }

  return 0;
}
