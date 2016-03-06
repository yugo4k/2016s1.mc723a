#include <stdio.h>

int primo(int n) {
  int i = 0;

  for (i = 2; i < n; ++i)
    if (n % i == 0)
      return 0;

  return 1;
}

int main() {
  int n = 104395301;

  if (primo(n))
    printf("%d é primo.\n", n);
  else
    printf("%d não é primo.\n", n);

  return 0;
}
