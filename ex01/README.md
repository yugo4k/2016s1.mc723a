### MC723a - 2016s1
### ra033324 - Yugo Kuno
# Exercício 1: Compilação e Otimização

## Parte 1: _Compile o programa sem nenhuma opção de compilação extra._

- [ ] _Compile o programa sem nenhuma opção de compilação extra. Quanto tempo ele gasta?_

- [ ] _Veja se o valor muda utilizando, separadamente, cada uma das otimizações -O0, -O1, -O2 -O3 (letra O maiúscula seguida de um número). Qual delas deu o melhor tempo?_

- [ ] _Existem outras otimizações que você pode aplicar no processador atual, consulte o manual do gcc por otimizações da categoria -mtune e veja quais se aplicam ao seu processador. Para que elas servem? O tempo melhorou?_

---

## Parte 2: _Quebre o programa em dois arquivos separados: main.c com a função main e calc_primo.c com a função primo. Faça as alterações necessárias nos dois arquivos para que eles compilem._

- [ ] _Como compilá-los? Você consegue montar um script que compile estes dois programas? E um Makefile?_

Pode-se utilizar compiladores como o gcc diretamente da linha de comando ou a partir de scripts ou usando um Makefile. Exemplos de um shell script e um Makefile que compilam o programa foram carregados em:
`https://github.com/yugo4k/2016s1.mc723a/tree/master/ex01/p2``

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
