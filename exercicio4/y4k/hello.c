#include <stdio.h>
#include <stdint.h>

uint32_t *global_lock = (uint32_t*)(100 * 1024 * 1024);
uint32_t *lock_1 = (uint32_t*)(100 * 1024 * 1024 + 1);

int main() {
  printf("hello.\n");
  printf("\n");

  printf("global_lock: |%8d|\n", *global_lock);
  printf("global_lock: |%8d|\n", *global_lock);
  *global_lock = 16;
  printf("global_lock: |%8d|\n", *global_lock);
  printf("global_lock: |%8d|\n", *global_lock);
  printf("\n");

  printf("lock_1: |%8d|\n", *lock_1);
  printf("lock_1: |%8d|\n", *lock_1);
  *lock_1 = 17;
  printf("lock_1: |%8d|\n", *lock_1);
  printf("lock_1: |%8d|\n", *lock_1);
  printf("\n");

  return 0;
}
