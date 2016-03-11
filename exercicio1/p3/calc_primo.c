unsigned long int calc_primo(unsigned long int n) {
  int i = 0;

  for (i = 2; i < n; ++i)
    if (n % i == 0)
      return 0;

  return 1;
}
