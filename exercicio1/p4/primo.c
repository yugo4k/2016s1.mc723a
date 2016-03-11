#include <stdio.h>
#include <stdlib.h>

long int primo(unsigned long int n) {
  int i = 0;

  if (n == 2)
    return 1;
  if (n % 2 == 0)
    return 0;

  for (i = 3; i < n; i += 2)
    if (n % i == 0)
      return 0;

  return 1;
}

int main(int argn, char** argv) {
  unsigned long int i = 0, t = 0, n = 0;

  if (argn != 2) {
    printf("Please pass a value as argument to the program and no other arguments.\n");
    return 0;
  }

  n = strtol(argv[1], NULL, 0);
  if (n <= 1) {
    printf("Please pass a valid value (larger than 1, which is not prime) as argument to the program, the argument passed was '%s'.\n", argv[1]);
    return 0;
  } 

  for (i = 2; i <= n; ++i)
    t += primo(i);

  printf("Existem %ld números primos entre 1 e %ld (inclusos).\n", t, n);

  return 0;
}
