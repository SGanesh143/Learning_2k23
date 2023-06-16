#include <stdio.h>

void printBits(unsigned int n) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (n >> i) & 1);
  }
}

int main() {
  unsigned int n;
  printf("Enter a 32-bit integer: ");
  scanf("%u", &n);

  printBits(n);
  printf("\n");

  return 0;
}
