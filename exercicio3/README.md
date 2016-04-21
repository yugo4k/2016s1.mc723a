### Exercício 3: Contagem de ciclos
#### 033324 - Yugo Kuno

---

Uma etapa fundamental do projeto de arquitetura de um sistema é a simulação do seu desempenho. Obviamente não se pode, a cada modificação do projeto, fabricar e montar seus componentes para avaliação do resultado: assim é extremamente relevante o uso de simuladores para avaliação de performance.

Entretanto um simulador obviamente não processa instruções no mesmo tempo que o sistema real, tal que a medida de interesse é o número de ciclos necessários para completar cada teste. Uma vez que se saiba (ou estime) o _clock_ do sistema final, é possível comparar a arquitetura projetada com sistemas reais em funcionamento.

Neste experimento foi usado um simulador do processador MIPS, criado com a linguagem ArchC, criado pelo time do IC de mesmo nome e baseado na linguagem de descrição de hardware SystemC. O ArchC permite, entre outras funcionalidades, a avalição de ciclos consumidos pelo programa globalmente e por cada tipo de instrução.


### Contando instruções

Para avaliar o número de instruções do tipo _add_ que ocorrem em um programa simples, foram simuladas duas versões de um _hello_world_ em C; a primeira sem nenhuma operação de soma:  
```
  printf("hello.\n");
```

