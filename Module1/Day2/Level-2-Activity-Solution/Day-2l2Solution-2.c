#include <stdio.h>

int compare_boxes(int *box1, int *box2, int size) {
  int is_equal = 1;

  for (int i = 0; i < size; i++) {
    if (box1[i] != box2[i]) {
      is_equal = 0;
      break;
    }
  }

  return is_equal;
}

int main() {
  int box1[3] = {200, 10, -90};
  int box2[3] = {-90, 200, 10};
  int size = sizeof(box1) / sizeof(box1[0]);

  int is_equal = compare_boxes(box1, box2, size);

  if (is_equal) 
  {
    printf("The boxes are equal.\n");
  } 
  else 
  {
    printf("The boxes are not equal.\n");
  }

  return 0;
}
