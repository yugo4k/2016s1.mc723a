### MC723a - 2016s1
### ra033324 - Yugo Kuno
# Exercício 1: Compilação e Otimização

## Parte 1: _Compile o programa sem nenhuma opção de compilação extra._

- [x] _Compile o programa sem nenhuma opção de compilação extra. Quanto tempo ele gasta?_

[~1.35s](p1/hist_a.png)

- [x] _Veja se o valor muda utilizando, separadamente, cada uma das otimizações -O0, -O1, -O2 -O3 (letra O maiúscula seguida de um número). Qual delas deu o melhor tempo?_

[Apesar de `-O3` ter tido um melhor tempo de ~1.34s, a diferença devido a essas otimizações é minima](p1) porque o algoritmo em questão é excessivamente primitivo e o otimizador não consegue melhorar o desempenho.

- [x] _Existem outras otimizações que você pode aplicar no processador atual, consulte o manual do gcc por otimizações da categoria -mtune e veja quais se aplicam ao seu processador. Para que elas servem? O tempo melhorou?_

Pode-se usar as flags "_-march=[value]_" e "_-mtune=[value]_" para que o compilador use otimizações específicas do processador alvo. Novamente devido à primitividade do algoritmo usado essas otimizações não reduzem o tempo abaixo de [~1.34s](p1/hist_c.png), que não deve ser causado por mais do que oscilações no _load_ do sistema.

---

## Parte 2: _Quebre o programa em dois arquivos separados: main.c com a função main e calc_primo.c com a função primo. Faça as alterações necessárias nos dois arquivos para que eles compilem._

- [x] _Como compilá-los? Você consegue montar um script que compile estes dois programas? E um Makefile?_

Quebrando o algoritmo entre os _bodys_ [main.c](p2/main.c), [calc_primo.c](p2/calc_primo.c) e o _header_ [calc_primo.h](p2/calc_primo.h), pode-se utilizar compiladores como o gcc diretamente da linha de comando (e.g.  `gcc -Wall -pedantic -O3 -march=core2 -mtune=core2 calc_primo.c main.c -o main`) ou a partir de um [script](p2/script.sh) ou usando um [Makefile](p2/Makefile).

- [x] _Rode novamente o programa e veja se ele gasta o mesmo tempo com a melhor otimização utilizada anteriormente. O resultado foi o esperado? Comente._

A diferença entre o [resultado](p2/hist.png) desta versão e aquela mais rápida da parte 1 é inferior a .01s, o que parece indicar apenas flutuações de _load_ do sistema. Além disso, não foi encontrada qualquer referência sobre quebrar um programa com muitos _includes_ ter efeito sobre a performance de _runtime_, apenas deixando o tempo de _linking_ mais longo. Entretanto essa presunção foi questionada pelos resultados da parte 3.

---

## Parte 3: _Modifique seu programa para calcular quantos números primos existem entre 1 e n, seguindo o mesmo algoritmo utilizado, modificando apenas a função main e fazendo com que n seja um parâmetro passado por linha de comando._

- [x] _Meça o tempo com um arquivo fonte e com dois. O resultado foi o esperado? Comente._

As versões compiladas foram testadas com um n = 40000. Com as otimizações anteriores, o melhor tempo da versão de um arquivo fonte foi de [~2.00s](p3/hist_single_opt.png) e de dois arquivos fontes foi de [~2.10s](p3/hist_double_opt.png), uma diferença de ~5%. Com a suspeita de que essa divergência foi devido às otimizações, os testes foram refeitos sem as mesmas, com resultados de [~2.40s](p3/hist_single_noopt.png) e [~2.42s](p3/hist_double_noopt.png) para um e dois arquivos fonte respectivamente.

A diferença do tempo de execução entre as versões compiladas indica claramente que, entre as versões otimizadas, o programa de um arquivo fonte tem performance melhor que o de dois. Isso parece indicar que quando uma função é compilada separadamente do main, as otimizações realizadas pelo `gcc` são limitadas, já que o _linking_ ocorre em etapa posterior.
Uma suspeita é que as otimizações fazem com que a versão de um arquivo fonte torne a função de checagem de primo seja compilada _inline_, evitando a cópia desnecessária da variável do número a ser checado, por exemplo.

---

## Parte 4: _Edite o laço da função primo para varrer apenas os números ímpares, dividindo o conjunto de números a testar por dois._

- [x] _Em qual parte seu programa gasta mais tempo?_

Como é de se esperar, o tempo de execução caiu quase pela metade com um melhor tempo de [~1.05s](p4/hist.png), visto que o número de ciclos do _loop_ da função primo foi praticamente cortado também pela metade.
Curiosamente, o `gprof` usado com o código compilado com as flags `-O2` e `-O3` apresenta o resultado

```Each sample counts as 0.01 seconds.
 no time accumulated```

---

## Parte 5: Paralelização pelo OpenMP

- [ ] _Se você tiver que paralelizar alguma parte do código, qual parte você escolheria?_

- [ ] _Como paralelizar de forma escalável o código?_

- [ ] _Meça o tempo do programa paralelizado. O resultado foi o esperado? Comente._

---

## Parte 6: Outras formas de otimização

- [ ] _Como melhorar ainda mais o desempenho deste programa?_
