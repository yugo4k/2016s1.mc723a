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

  array = (short*)calloc(40 * n, sizeof(short));
  if (!array) {
    printf("aborting, couldn't allocate the necessary memory.\n");
    return 0;
  }

  for (i = 2; i < 40 * n; ++i)
    if (array[i] == 0) {
      t += 1;
      for (j = 2 * i; j <= 40 * n; j += i)
	array[j] = 1;
      if (t == n) {
	printf("%lu\n", i);
	free(array);
	array = NULL;
	return 0;
      }
    }

  free(array);
  array = NULL;

  return 0;
}
