#include <stdio.h>

char get_grade(int marks) {
  char grade;

  switch (marks / 10) {
    case 10:
    case 9:
      grade = 'A';
      break;
    case 8:
      grade = 'B';
      break;
    case 7:
      grade = 'C';
      break;
    case 6:
      grade = 'D';
      break;
    case 5:
    case 4:
      grade = 'E';
      break;
    default:
      grade = 'F';
      break;
  }

  return grade;
}
int main() {
  int marks;
  printf("\n Enter the marks:");
  scanf("%d",&marks);
  char grade;

  grade = get_grade(marks);

  switch (grade) {
    case 'A':
      printf("Grade A\n");
      break;
    case 'B':
      printf("Grade B\n");
      break;
    case 'C':
      printf("Grade C\n");
      break;
    case 'D':
      printf("Grade D\n");
      break;
    case 'E':
      printf("Grade E\n");
      break;
    case 'F':
      printf("Grade F\n");
      break;
  }

  return 0;
}
