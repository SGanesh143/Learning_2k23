#include <stdio.h>

unsigned int set_bit(unsigned int number, int bit_number) {
  unsigned int mask = 1 << bit_number;
  return number | mask;
}

unsigned int clear_bit(unsigned int number, int bit_number) {
  unsigned int mask = 1 << bit_number;
  return number & ~mask;
}

unsigned int toggle_bit(unsigned int number, int bit_number) {
  unsigned int mask = 1 << bit_number;
  return number ^ mask;
}

unsigned int set_10_second_bit(unsigned int seconds_register) {
  int bit_number = 6;
  unsigned int mask = 1 << bit_number;
  return set_bit(seconds_register, bit_number);
}

int main() {
  unsigned int seconds_register = 0b00000000;
  printf("Original seconds register: %u\n", seconds_register);
  seconds_register = set_10_second_bit(seconds_register);
  printf("Seconds register after setting 10-second bit: %u\n", seconds_register);

  return 0;
}
