### Exercício 2: Configuração de Cache
#### 033324 - Yugo Kuno

---

Para avaliar a melhor configuração de cache para um programa, foram simuladas com o software [dinero](http://www.cs.wisc.edu/~markhill/DineroIV/) as operações de cache do `gcc` a partir dos traces 176.gcc.f2b e 176.gcc.m2b disponíveis na rede do IC sob o path _~lucas/mc723/traces_.  
O `gcc` foi escolhido por ser um programa particularmente relevante, especialmente para a área de desenvolvimento, em que os tempos de compilação podem ser críticos para grandes projetos.

Antes de mais nada foram avaliadas as políticas de _replacement_, _fetch_, _write allocate_ e _write back_.  
Com esse objetivo os parâmetros iniciais das _caches_ foram escolhidas a partir das configurações de L1 e L2 de um _core_ da CPU _AMD Phenom II X4 955 Black Edition_:

|Cache|Cache size|Block size|Associativity|
|---|---|---|---|
|L1 type instruction|64K|64|2|
|L1 type data|64K|64|2|
|L2 type unified|512K|64|2|


### Avaliação de _replacement policy_

|trname|parameter|miss rate l1i|miss rate l1d|miss rate l2u|
|---|---|---|---|---|
|gcc_f2b|repl=l|0.002400|0.007800|0.504500|
|gcc_f2b|repl=f|0.002600|0.008400|0.524900|
|gcc_f2b|repl=r|0.002500|0.008600|0.497700|
|gcc_m2b|repl=l|0.000100|0.037400|0.995700|
|gcc_m2b|repl=f|0.000100|0.037400|0.995300|
|gcc_m2b|repl=r|0.000100|0.037600|0.867900|

(l=LRU, f=FIFO, r=random)