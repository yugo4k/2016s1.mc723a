#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

long int primo(unsigned long int n) {
  unsigned long int i = 0;

  /* int flag = 1; */

  if (n == 2)
    return 1;
  if (n % 2 == 0)
    return 0;

/* #pragma omp parallel for */
  for (i = 3; i < n; i += 2)
    if (n % i == 0)
      /* flag = 0; */
      return 0;

  /* return flag; */
  return 1;
}

int main(int argn, char** argv) {
  unsigned long int i = 0, t = 0, n = 0;

  unsigned short n_threads = omp_get_max_threads();
  printf("using %u threads.\n", n_threads);
  omp_set_num_threads(n_threads);

  if (argn != 2) {
    printf("Please pass a value as argument to the program and no other arguments.\n");
    return 0;
  }

  n = strtol(argv[1], NULL, 0);
  if (n <= 1) {
    printf("Please pass a valid value (larger than 1, which is not prime) as argument to the program, the argument passed was '%s'.\n", argv[1]);
    return 0;
  } 

#pragma omp parallel for
  for (i = 2; i <= n; ++i)
#pragma omp critical
    t += primo(i);

  printf("Existem %ld números primos entre 1 e %ld (inclusos).\n", t, n);

  return 0;
}
