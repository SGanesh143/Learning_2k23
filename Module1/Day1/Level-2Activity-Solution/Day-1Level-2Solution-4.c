#include <stdio.h>
int bit_operations(int num, int oper_type, int pos) {
  int result;

  switch (oper_type) {
    case 1:
      result = num | (1 << pos) | (1 << (pos + 1));
      break;
    case 2:
      result = num & ~(1 << pos) & ~(1 << (pos + 1)) & ~(1 << (pos + 2));
      break;
    case 3:
      result = num ^ (1 << 31);
      break;
    default:
      result = -1;
      break;
  }

  return result;
}
int main() {
  int num = 10;
  int oper_type = 1;
  int pos = 2;
  int result = bit_operations(num, oper_type, pos);

  printf("Result: %d\n", result);

  return 0;
}
