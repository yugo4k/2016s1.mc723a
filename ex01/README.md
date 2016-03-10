### MC723a - 2016s1
### ra033324 - Yugo Kuno
# Exercício 1: Compilação e Otimização

## Parte 1: _Compile o programa sem nenhuma opção de compilação extra._

- [x] _Compile o programa sem nenhuma opção de compilação extra. Quanto tempo ele gasta?_

[~1.35s](p1/hist_a.png)

- [x] _Veja se o valor muda utilizando, separadamente, cada uma das otimizações -O0, -O1, -O2 -O3 (letra O maiúscula seguida de um número). Qual delas deu o melhor tempo?_

[Apesar de "_-O3_" ter tido um melhor tempo de ~1.34s, a diferença devido a essas otimizações é minima](p1) porque o algoritmo em questão é excessivamente primitivo e o otimizador não consegue melhorar o desempenho.

- [x] _Existem outras otimizações que você pode aplicar no processador atual, consulte o manual do gcc por otimizações da categoria -mtune e veja quais se aplicam ao seu processador. Para que elas servem? O tempo melhorou?_

Pode-se usar as flags "_-march=[value]_" e "_-mtune=[value]_" para que o compilador use otimizações específicas do processador alvo. Novamente devido à primitividade do algoritmo usado essas otimizações não reduzem o tempo abaixo de [~1.34s](p1/hist_c.png), que não deve ser causado por mais do que oscilações no _load_ do sistema.

---

## Parte 2: _Quebre o programa em dois arquivos separados: main.c com a função main e calc_primo.c com a função primo. Faça as alterações necessárias nos dois arquivos para que eles compilem._

- [x] _Como compilá-los? Você consegue montar um script que compile estes dois programas? E um Makefile?_

Quebrando o algoritmo entre os _bodys_ [main.c](p2/main.c), [calc_primo.c](p2/calc_primo.c) e o _header_ [calc_primo.h](p2/calc_primo.h), pode-se utilizar compiladores como o gcc diretamente da linha de comando (e.g.  `gcc -Wall -pedantic -O3 -march=core2 -mtune=core2 calc_primo.c main.c -o main`) ou a partir de um [script](p2/script.sh) ou usando um [Makefile](p2/Makefile).

- [ ] _Rode novamente o programa e veja se ele gasta o mesmo tempo com a melhor otimização utilizada anteriormente. O resultado foi o esperado? Comente._

---

## Parte 3: _Modifique seu programa para calcular quantos números primos existem entre 1 e n, seguindo o mesmo algoritmo utilizado, modificando apenas a função main e fazendo com que n seja um parâmetro passado por linha de comando._

- [ ] _Meça o tempo com um arquivo fonte e com dois. O resultado foi o esperado? Comente._

---

## Parte 4: _Edite o laço da função primo para varrer apenas os números ímpares, dividindo o conjunto de números a testar por dois._

- [ ] _Em qual parte seu programa gasta mais tempo?_

---

## Parte 5: Paralelização pelo OpenMP

- [ ] _Se você tiver que paralelizar alguma parte do código, qual parte você escolheria?_

- [ ] _Como paralelizar de forma escalável o código?_

- [ ] _Meça o tempo do programa paralelizado. O resultado foi o esperado? Comente._

---

## Parte 6: Outras formas de otimização

- [ ] _Como melhorar ainda mais o desempenho deste programa?_
