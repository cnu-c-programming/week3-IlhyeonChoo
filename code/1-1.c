#include <stdio.h>

int main(void) {
  int add(int a, int b);
  int sub(int a, int b);
  int mul(int a, int b);
  int div(int a, int b);

  int a = 10, b = 5;

  printf("%d + %d = %d\n", a, b, add(a, b));
  printf("%d - %d = %d\n", a, b, sub(a, b));
  printf("%d * %d = %d\n", a, b, mul(a, b));
  printf("%d / %d = %d\n", a, b, div(a, b));

  return 0;
}

int add(int a, int b) { return a + b; }

int sub(int a, int b) { return a - b; }

int mul(int a, int b) { return a * b; }

int div(int a, int b) { return a / b; }
