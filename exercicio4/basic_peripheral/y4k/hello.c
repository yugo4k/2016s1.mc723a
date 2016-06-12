#include <stdio.h>
#include <stdint.h>

int main() {
  /* The pointer must be declared volatile so that the programs */
  /* will always access the position in memory instead of using the cache. */
  /* If caching happened independently for each CPU, the lock would not work, */
  /* since the lock variable must be shared and instantly updated for it to work. */
  volatile uint32_t *global_lock = (uint32_t*)(100<<20);
  int i = 0;

  printf("hello.\n");
  printf("\n");

  printf("global_lock: |%8d|\n", *global_lock);
  printf("global_lock: |%8d|\n", *global_lock);
  printf("\n");
  for (i = 0; i < 19; ++i) {
    *global_lock = i;
    printf("\n");
    printf("global_lock: |%8d|\n", *global_lock);
    printf("global_lock: |%8d|\n", *global_lock);
    printf("\n");
  }

  return 0;
}
