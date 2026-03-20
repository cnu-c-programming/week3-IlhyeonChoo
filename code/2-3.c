#include <stdio.h>

void divide(int a, int b, int* q, int* r) {
  *q = a / b;
  *r = a % b;
}

int main() {
  int a = 27, b = 4, q = 0, r = 0;

  divide(a, b, &q, &r);

  printf("%d\n%d\n", q, r);

  return 0;
}
