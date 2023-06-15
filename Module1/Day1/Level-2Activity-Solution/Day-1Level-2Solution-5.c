#include <stdio.h>
#include <ctype.h>

int char_type(char ch) {
  if (ch >= 'A' && ch <= 'Z') 
  {
    return 1;
  } 
  else if (ch >= 'a' && ch <= 'z') 
  {
    return 2;
  }
  else if (ch >= '0' && ch <= '9') 
  {
    return 3;
  } 
  else if (isprint(ch)) 
  {
    return 4;
  }
  else 
  {
    return 5;
  }
}
int main() {
  char ch;
  printf("\n Enter the character or number: ");
  scanf("%s",&ch);

  int char_type_result = char_type(ch);

  switch (char_type_result) {
    case 1:
      printf("Uppercase letter\n");
      break;
    case 2:
      printf("Lowercase letter\n");
      break;
    case 3:
      printf("Numeric digit\n");
      break;
    case 4:
      printf("Printable symbol\n");
      break;
    case 5:
      printf("Non-printable symbol\n");
      break;
  }

  return 0;
}
