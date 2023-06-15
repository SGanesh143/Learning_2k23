#include <stdio.h>

int greatest_of_three(int a, int b, int c) {
  if (a > b && a > c) {
    return a;
  } else if (b > a && b > c) {
    return b;
  } else {
    return c;
  }
}

int main() {
  int a, b, c;
  printf("Enter three numbers: ");
  scanf("%d %d %d", &a, &b, &c);
  int greatest = greatest_of_three(a, b, c);
  printf("The greatest number is %d\n", greatest);
  return 0;
}
