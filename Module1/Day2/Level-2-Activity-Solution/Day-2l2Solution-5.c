#include <stdio.h>
#include <string.h>

void encode(char *string) {
  for (int i = 0; string[i] != '\0'; i++) {
    string[i] = string[i] + 1;
  }
}

void decode(char *string) {
  for (int i = 0; string[i] != '\0'; i++) {
    string[i] = string[i] - 1;
  }
}

int main() {
  char string[100];
  printf("Enter a string: ");
  fgets(string, 100, stdin);

  encode(string);
  printf("Encoded string: %s\n", string);

  decode(string);
  printf("Decoded string: %s\n", string);

  return 0;
}
