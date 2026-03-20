#include <stdarg.h>
#include <stdio.h>

int main() {
  int average(int count, ...);

  printf("%d\n", average(3, 10, 20, 30));
  printf("%d\n", average(5, 10, 20, 30, 40, 50));
  return 0;
}

int average(int count, ...) {
  va_list ap;
  va_start(ap, count);
  int total = 0;
  for (int i = 0; i < count; i++) {
    total += va_arg(ap, int);
  }
  va_end(ap);
  return total / count;
}
