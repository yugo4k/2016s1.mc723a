#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argn, char** argv) {
  unsigned long int i = 0, j = 0, t = 0, n = 0;
  short * array = NULL;

  unsigned long int calls = 0;

  unsigned short n_threads = 1;//omp_get_max_threads();
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

  array = (short*)calloc(n + 1, sizeof(short));
  if (!array) {
    printf("aborting, couldn't allocate the necessary memory.\n");
    return 0;
  }

  for (i = 2; i <= n; ++i)
    if (array[i] == 0) {
      t += 1;
#pragma omp parallel for
      for (j = 2 * i; j <= n; j += i) {
	printf("j: %lu\n", j);
	array[j] = 1;
#pragma omp critical
	++calls;
      }
    }

  printf("Existem %ld números primos entre 1 e %ld (inclusos).\n", t, n);
  printf("%lu calls.\n", calls);

  free(array);
  array = NULL;

  return 0;
}
