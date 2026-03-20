#include <stdio.h>

int power(int base, int exp) {
  if (exp < 1) {
    return 1;
  } else {
    return base * power(base, exp - 1);
  }
}

int main() {
  printf("%d\n", power(2, 3));
  printf("%d\n", power(5, 0));
  printf("%d\n", power(3, 4));

  return 0;
}
