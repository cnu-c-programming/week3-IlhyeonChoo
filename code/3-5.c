#include <stdarg.h>
#include <stdio.h>

int main() {
  void my_sum(char type, int count, ...);

  my_sum('S', 2, "Hello", "World");
  my_sum('C', 3, 'C', 'N', 'U');
  my_sum('D', 4, 10, 20, 30, 40);

  return 0;
}

void my_sum(char type, int count, ...) {
  va_list ap;
  va_start(ap, count);

  switch (type) {
    case 'S': {
      for (int i = 0; i < count; i++) {
        printf("%s", va_arg(ap, char*));
        if (i < count - 1) {
          printf(" ");
        }
      }
      printf("\n");
      break;
    }
    case 'C': {
      for (int i = 0; i < count; i++) {
        printf("%c", va_arg(ap, int));
      }
      printf("\n");
      break;
    }
    case 'D': {
      int total = 0;
      for (int i = 0; i < count; i++) {
        total += va_arg(ap, int);
      }
      printf("%d\n", total);
      break;
    }
  }

  va_end(ap);
}
