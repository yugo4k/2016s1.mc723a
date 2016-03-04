#include <stdio.h>
#include "calc_primo.h"

int main() {
  int n = 104395301;

  if (calc_primo(n))
    printf("%d é primo.\n", n);
  else
    printf("%d não é primo.\n", n);

  return 0;
}
