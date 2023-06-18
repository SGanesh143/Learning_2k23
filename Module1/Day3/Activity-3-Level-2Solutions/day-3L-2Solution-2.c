#include <stdio.h>

unsigned int decimal_to_bcd(unsigned int decimal_number) {
  unsigned int bcd_number = 0;
  for (int i = 0; i < 4; i++) {
    unsigned int digit = decimal_number % 10;
    bcd_number |= (digit << (4 - i) * 4);
    decimal_number /= 10;
  }
  return bcd_number;
}

unsigned int bcd_to_decimal(unsigned int bcd_number) {
  unsigned int decimal_number = 0;
  for (int i = 0; i < 4; i++) {
    unsigned int digit = (bcd_number >> ((3 - i) * 4)) & 0x0F;
    decimal_number += digit * pow(10, i);
  }
  return decimal_number;
}

int main() {
  unsigned int decimal_number = 1234;
  unsigned int bcd_number = decimal_to_bcd(decimal_number);
  printf("Decimal number: %u\n", decimal_number);
  printf("BCD number: %u\n", bcd_number);

  unsigned int converted_decimal = bcd_to_decimal(bcd_number);
  printf("Converted Decimal number: %u\n", converted_decimal);

  return 0;
}
