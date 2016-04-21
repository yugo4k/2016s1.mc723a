### Exercício 3: Contagem de ciclos
#### 033324 - Yugo Kuno

---

Uma etapa fundamental do projeto de arquitetura de um sistema é a simulação do seu desempenho. Obviamente não se pode, a cada modificação do projeto, fabricar e montar seus componentes para avaliação do resultado: assim é extremamente relevante o uso de simuladores para avaliação de performance.

Entretanto um simulador obviamente não processa instruções no mesmo tempo que o sistema real, tal que a medida de interesse é o número de ciclos necessários para completar cada teste. Uma vez que se saiba (ou estime) o _clock_ do sistema final, é possível comparar a arquitetura projetada com sistemas reais em funcionamento.

Neste experimento foi usado um simulador do processador MIPS, criado com a linguagem ArchC, criado pelo time do IC de mesmo nome e baseado na linguagem de descrição de hardware SystemC. O ArchC permite, entre outras funcionalidades, a avalição de ciclos consumidos pelo programa globalmente e por cada tipo de instrução.


### Contando instruções

Para avaliar o número de instruções do tipo _add_ que ocorrem em um programa simples, foram simuladas três versões de um _hello_world_ em C; a primeira sem nenhuma operação de soma:  
```  
  printf("hello.\n");
```  
a segunda contendo somente uma operação de soma (que nem seria compilada caso otimizações fossem utilizadas):  
```  
  int a = -5 + 3;
  printf("hello.\n");
```  
e a terceira também mostrando o resultado na _string_:  
```  
  int a = -5 + 3;
  printf("hello %d.\n", a);
```  
A primeira versão gerou o seguinte número de instruções do tipo _add_:  
```  
counter_add: 0
counter_addi: 1
counter_addu: 171
counter_addiu: 273
```  
a segunda:  
```  
counter_add: 0
counter_addi: 1
counter_addu: 171
counter_addiu: 274
```  
e a terceira:
```  
counter_add: 0
counter_addi: 1
counter_addu: 301
counter_addiu: 378
```  

Deste exemplo ficam claros os seguintes pontos:  
- Existe um extenso arcabouço para sustentar um programa simples como o _hello_world_, com mais de 400 instruções do tipo _add_ somente para mostrar uma _string_ no _display_, mesmo sem haver qualquer operação de soma **explícita** contida no _source_.
- Como foram somados dois imediatos e seu valor atribuído a uma variável na segunda versão, foi adicionada apenas uma instrução _addiu_. Percebe-se pela terceira versão que se o resultado for inserido na _string_, o número de instruções do tipo _add_ aumenta em quase 50%; é claro que converter o valor para caracteres e adicioná-los à _string_ não é uma tarefa tão simples quanto fazer esta modificação no _source_.  
- Apesar de um dos imediatos ter sinal negativo e a variável ser por _default_ do tipo _signed_, foi usada a instrução _addiu_ ao invés de _addi_; isso se deve ao fato que a representação binária de negativos ser a _complement of 2_, tal que o tratamento da soma será o mesmo. Até mesmo caso ocorra overflow, apesar de a documentação indicar um resultado de _undefined behavior_ para variáveis do tipo _signed_ e _modulo power of two_ (_wrap_) para _unsigned_, o resultado comum em C (sem _flags_ específicas de compilação) será o _wrap_, tal que as instruções _add_ do tipo _unsigned_ são perfeitamente adequadas para _signed integers_ e _unsigned integers_.  


### Avaliando o desempenho

Foram avaliados os números de ciclos necessários para executar os programas _susan edges (small)_, _rijndael decoder (small)_ e _gsm coder (large)_; os resultados seguem abaixo.  

#### Número de instruções:  
|Categoria             |susan edges (small)|rijndael decoder (small)|gsm coder (large)|
|----------------------|-------------------|------------------------|-----------------|
|Acesso à memória      |            2785538|                13745318|        480882985|
|Controle (branch/jump)|961478             |1600121                 |91942660         |
|Outras                |4346133            |31125176                |911651559        |

#### CPI médio:  
|Categoria             |CPI médio          |
|----------------------|-------------------|
|Acesso à memória      |                 10|
|Controle (branch/jump)|                  3|
|Outras                |                  1|

#### Número de ciclos estimado:  
|Categoria             |susan edges (small)|rijndael decoder (small)|gsm coder (large)|
|----------------------|-------------------|------------------------|-----------------|
|Acesso à memória      |2785538            |13745318                |480882985        |
|Controle (branch/jump)|961478             |1600121                 |91942660         |
|Outras                |4346133            |31125176                |911651559        |
