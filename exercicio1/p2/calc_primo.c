int calc_primo(int n) {
  int i = 0;

  for(i = 2; i < n; ++i)
    if (n % i == 0)
      return 0;

  return 1;
}
