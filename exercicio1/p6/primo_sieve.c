#include <stdio.h>
#include <stdlib.h>

int main(int argn, char** argv) {
  unsigned long int i = 0, j = 0, t = 0, n = 0;
  short * array = NULL;

  if (argn != 2) {
    printf("Please pass a value as argument to the program and no other arguments.\n");
    return 0;
  }

  n = strtol(argv[1], NULL, 0);
  if (n <= 1) {
    printf("Please pass a valid value (larger than 1, which is not prime) as argument to the program, the argument passed was '%s'.\n", argv[1]);
    return 0;
  } 

  array = (short*)calloc(n, sizeof(short));
  if (!array) {
    printf("aborting, couldn't allocate the necessary memory.\n");
    return 0;
  }

  for (i = 2; i <= n; ++i) {
    if (array[i] == 0) {
      t += 1;
      j = 2 * i;
      while (j <= n) {
	array[j] = 1;
	j += i;
      }
    }
  }

  printf("Existem %ld números primos entre 1 e %ld (inclusos).\n", t, n);

  free(array);
  array = NULL;

  return 0;
}
