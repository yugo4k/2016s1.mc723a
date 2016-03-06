#include <stdio.h>
#include <stdlib.h>
#include "calc_primo.h"

int main(int argn, char** argv) {
  long int i = 0, t = 0;

  if (argn != 2) {
    printf("Please pass a value as argument to the program and no other arguments.\n");
    return 0;
  }

  long int n = strtol(argv[1], NULL, 0);
  if (n <= 1) {
    printf("Please pass a valid value (larger than 1, which is not prime) as argument to the program, the argument passed was '%s'.\n", argv[1]);
    return 0;
  } 

  for (i = 2; i <= n; ++i)
    t += calc_primo(i);

  printf("Existem %ld números primos entre 1 e %ld (inclusos).\n", t, n);

  return 0;
}
