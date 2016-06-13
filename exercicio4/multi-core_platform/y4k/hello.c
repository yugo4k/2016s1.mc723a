#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 65500

volatile uint32_t *global_lock = (uint32_t*)(100<<20);
volatile uint32_t cpu_counter = 0;
volatile uint32_t lock_arrayinit = 1;
volatile uint32_t lock_sum2unfinished = 1;

uint32_t i1 = 0, i2 = 0;
volatile uint32_t sum1 = 0, sum2 = 0;
volatile uint32_t array[SIZE] = {0};
volatile uint32_t result = 0;

void submain1() {
  *global_lock = 0;

  while (*global_lock);
  printf("submain1 started\n");
  *global_lock = 0;

  for (i1 = 0; i1 < SIZE; ++i1) {
    array[i1] = i1;
  }

  lock_arrayinit = 0;

  sum1 = 0;
  for (i1 = 0; i1 < SIZE; i1 += 2) {
    sum1 += array[i1];
    /* while (*global_lock); */
    /* printf("1: %d\n", i1); */
    /* *global_lock = 0; */
  }

  /* while (*global_lock); */
  /* printf("sum1: %d\n", sum1); */
  /* *global_lock = 0; */

  while (lock_sum2unfinished);

  result = sum1 + sum2;

  while (*global_lock);
  printf("\n\n The sum of the first %d numbers (including 0) squared is %d.\n\n\n", SIZE, result);
  *global_lock = 0;

  while (*global_lock);
  printf("submain1 finished\n");
  *global_lock = 0;

  return;
}

void submain2() {
  *global_lock = 0;

  while (*global_lock);
  printf("submain2 started\n");
  *global_lock = 0;

  while (lock_arrayinit);

  sum2 = 0;
  for (i2 = 1; i2 < SIZE; i2 += 2) {
    sum2 += array[i2];
    /* while (*global_lock); */
    /* printf("2: %d\n", i2); */
    /* *global_lock = 0; */
  }

  /* while (*global_lock); */
  /* printf("sum2: %d\n", sum2); */
  /* *global_lock = 0; */

  lock_sum2unfinished = 0;

  while (*global_lock);
  printf("submain2 finished\n");
  *global_lock = 0;

  return;
}

int main() {
  while (*global_lock);
  if (cpu_counter == 0) {
    ++cpu_counter;
    submain1();
  } else if (cpu_counter == 1) {
    ++cpu_counter;
    submain2();
  } else {
    ++cpu_counter;
    printf("\t cpu_counter ERROR");
  }

  return 0;
}
