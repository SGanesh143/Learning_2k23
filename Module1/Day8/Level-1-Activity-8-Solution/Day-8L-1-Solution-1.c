#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *source, *target;
  char ch;

  source = fopen("source.txt", "r");
  if (source == NULL) {
    printf("Error opening source file.\n");
    exit(1);
  }

  target = fopen("target.txt", "w");
  if (target == NULL) {
    printf("Error opening target file.\n");
    exit(1);
  }

  while ((ch = fgetc(source)) != EOF) {
    fputc(ch, target);
  }


  fclose(source);
  fclose(target);

  printf("File copied successfully.\n");

  return 0;
}
