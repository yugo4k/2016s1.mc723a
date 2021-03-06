#### MC723a - 2016s1
#### ra033324 - Yugo Kuno
## Exercício 1: Compilação e Otimização

#### Parte 1: _Compile o programa sem nenhuma opção de compilação extra._

- [x] _Compile o programa sem nenhuma opção de compilação extra. Quanto tempo ele gasta?_

[~1.35s](p1/hist_a.png).

- [x] _Veja se o valor muda utilizando, separadamente, cada uma das otimizações -O0, -O1, -O2 -O3 (letra O maiúscula seguida de um número). Qual delas deu o melhor tempo?_

[Apesar de `-O3` ter tido um melhor tempo de ~1.34s, a diferença devido a essas otimizações é minima](p1) porque o algoritmo em questão é excessivamente primitivo e o otimizador não consegue melhorar o desempenho.

- [x] _Existem outras otimizações que você pode aplicar no processador atual, consulte o manual do gcc por otimizações da categoria -mtune e veja quais se aplicam ao seu processador. Para que elas servem? O tempo melhorou?_

Pode-se usar as flags "_-march=[value]_" e "_-mtune=[value]_" para que o compilador use otimizações específicas do processador alvo. Novamente devido à primitividade do algoritmo usado essas otimizações não reduzem o tempo abaixo de [~1.34s](p1/hist_c.png), que não deve ser causado por mais do que oscilações no _load_ do sistema.

---

#### Parte 2: _Quebre o programa em dois arquivos separados: main.c com a função main e calc_primo.c com a função primo. Faça as alterações necessárias nos dois arquivos para que eles compilem._

- [x] _Como compilá-los? Você consegue montar um script que compile estes dois programas? E um Makefile?_

Quebrando o algoritmo entre os _bodys_ [main.c](p2/main.c), [calc_primo.c](p2/calc_primo.c) e o _header_ [calc_primo.h](p2/calc_primo.h), pode-se utilizar compiladores como o gcc diretamente da linha de comando (e.g.  `gcc -Wall -pedantic -O3 -march=core2 -mtune=core2 calc_primo.c main.c -o main`) ou a partir de um [script](p2/script.sh) ou usando um [Makefile](p2/Makefile).

- [x] _Rode novamente o programa e veja se ele gasta o mesmo tempo com a melhor otimização utilizada anteriormente. O resultado foi o esperado? Comente._

A diferença entre o [resultado](p2/hist.png) desta versão e aquela mais rápida da parte 1 é inferior a .01s, o que parece indicar apenas flutuações de _load_ do sistema. Além disso, não foi encontrada qualquer referência sobre quebrar um programa com muitos _includes_ ter efeito sobre a performance de _runtime_, apenas deixando o tempo de _linking_ mais longo. Entretanto essa presunção foi questionada pelos resultados da parte 3.

---

#### Parte 3: _Modifique seu programa para calcular quantos números primos existem entre 1 e n, seguindo o mesmo algoritmo utilizado, modificando apenas a função main e fazendo com que n seja um parâmetro passado por linha de comando._

- [x] _Meça o tempo com um arquivo fonte e com dois. O resultado foi o esperado? Comente._

As versões compiladas foram testadas com um n = 40000. Com as otimizações anteriores, o melhor tempo da versão de um arquivo fonte foi de [~2.00s](p3/hist_single_opt.png) e de dois arquivos fontes foi de [~2.10s](p3/hist_double_opt.png), uma diferença de ~5%. Com a suspeita de que essa divergência foi devido às otimizações, os testes foram refeitos sem as mesmas, com resultados de [~2.40s](p3/hist_single_noopt.png) e [~2.42s](p3/hist_double_noopt.png) para um e dois arquivos fonte respectivamente.

A diferença do tempo de execução entre as versões compiladas indica claramente que, entre as versões otimizadas, o programa de um arquivo fonte tem performance melhor que o de dois. Isso parece indicar que quando uma função é compilada separadamente do main, as otimizações realizadas pelo `gcc` são limitadas, já que o _linking_ ocorre em etapa posterior.  
Uma suspeita é que as otimizações fazem com que a versão de um arquivo fonte torne a função de checagem de primo seja compilada _inline_, evitando a cópia desnecessária da variável do número a ser checado, por exemplo.

---

#### Parte 4: _Edite o laço da função primo para varrer apenas os números ímpares, dividindo o conjunto de números a testar por dois._

- [x] _Em qual parte seu programa gasta mais tempo?_

Como é de se esperar, o tempo de execução (n = 40000) caiu quase pela metade com um melhor tempo de [~1.05s](p4/hist.png), visto que o número de ciclos do _loop_ da função primo foi praticamente cortado também pela metade.  
Curiosamente, o `gprof` usado com o código compilado com as flags `-O2` e `-O3` apresenta o [resultado](p4/gprof_output_O3.txt):  
```Each sample counts as 0.01 seconds.
 no time accumulated```  
Isso parece confirmar a suspeita de que o _loop_ é passado diretamente para o corpo do `main` nestas otimizações, tal que o `gprof` não tem tempos de chamada de função para medir já que estas não estariam ocorrendo.

Já compilando com a otimização `-O1`, é obtida a informação de que o programa gasta [100% do tempo na função _primo_](p4/gprof_output_O1.txt).

---

#### Parte 5: Paralelização pelo OpenMP

- [x] _Se você tiver que paralelizar alguma parte do código, qual parte você escolheria?_

Foi experimentado paralelizar o _loop_ da função `primo`, porém isso a tornava ineficiente (aumentando várias vezes o tempo de execução) já que não se pode executar um `return` de um bloco paralelizado, tal que o _loop_ nesta forma precisa ser executado inteiramente antes que a função possa retornar.  
Desta forma faz sentido paralelizar o _loop_ do `main`, uma vez que ele não retorna e cada ciclo é utilizado para checar independentemente se um número da sequência é primo ou não.

- [x] _Como paralelizar de forma escalável o código?_

Pode-se utilizar a função `omp_get_max_threads` para obter o número de _threads_ da máquina e utilizar o valor obtido como argumento da função `omp_set_num_threads`, tal que o programa sempre utilizará um número de _threads_ compatível com o número de núcleos da máquina.  
Outra forma seria definir um valor absurdamente alto para o número de _threads_ a serem executadas, mas isso causa um _overhead_ inaceitável para o desempenho e é totalmente contraindicado.

- [x] _Meça o tempo do programa paralelizado. O resultado foi o esperado? Comente._

O tempo paralelizado (n = 40000) caiu de [~1.04s](p5/hist_noomp.png) para [~0.77s](p5/hist_omp.png).  
Não é a redução de 50% do tempo de execução que poderia inocentemente se esperar da paralelização com dois _cores_, mas ~26% já é uma redução significativa considerando o overhead da paralelização, as limitações de paralelização do algoritmo na sua [forma atual](p5/primo_omp.c) e o próprio _load_ intrínseco da máquina em estar funcionando e possibilitando a execução do programa.

---

#### Parte 6: Outras formas de otimização

- [x] _Como melhorar ainda mais o desempenho deste programa?_

- A checagem de primos pode [ser interrompida assim que o divisor a ser checado é maior que metade do candidato](p6/primo_omp.c), o que reduz o tempo de execução (n = 40000) para [~0.552s](p6/hist_omp.png);

- [Usando](p6/primo_sieve.c) o método da _Sieve of Eratosthenes_ é possível obter um tempo de execução de [~0.01s](p6/hist_sieve.png) para n = 40000, uma redução de de mais de 98% comparado ao tempo acima.  
O tempo é de [~0.04s](p6/hist_sieve_1e6.png) para n = 10<sup>6</sup>, de [~1.11s](p6/hist_sieve_1e7.png) para n = 10<sup>7</sup> e de [~12.83](p6/hist_sieve_1e8.png) para n = 10<sup>8</sup>, o que mostra que o algoritmo tem uma complexidade próxima de `n·log(n)`.  
Entretanto ele usa uma quantidade significativa de memória, o que limita o aumento do valor de `n` para o hardware atualmente utilizado.
