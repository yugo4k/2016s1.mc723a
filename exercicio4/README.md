### Exercício 4: Plataformas e Periféricos
#### 033324 - Yugo Kuno

---

Este exercício continua o estudo realizado no exercício 3 e no projeto 2, aumentando agora a complexidade da simulação do sistema ao adicionar um _router_ entre as componentes do sistema, periféricos e múltiplos núcleos de processamento à CPU.

Neste experimento foi usado um simulador do processador MIPS, criado com a linguagem ArchC, criado pelo time do IC de mesmo nome e baseado na linguagem de descrição de hardware SystemC. O ArchC permite, entre outras funcionalidades, a avalição do número de execuções de cada tipo de instrução pelo programa.

### Periférico Básico

Nesta etapa o sistema agora não consiste somente em um processador e uma memória diretamente conectados; agora um _router_ faz a interface entre todos os componentes do sistema, permitindo o uso de diversos periféricos concomitantentemente. A forma mais simples de implementar esta comunicação é expandir o conceito de endereçamento utilizado exclusivamente para a memória até agora: a partir do _router_ pode-se acessar a memória usando uma faixa dos endereços disponíveis, enquanto outras faixas de endereços são reservadas para acesso aos periféricos disponíveis. Dessa forma o uso do _router_ fica trasparente e pode-se usar somente um estratégia integrada de comunicação para acesso aos diferentes componentes.

O acesso destes componentes então se dá simplesmente criando _pointers_ para os endereços das _ports_ dos periféricos, de maneira que a comunicação se dá através leituras e escritas de valores através destes canais. Entretanto, como esta comunicação é uma extensão da maneira como se trata a memória, é necessário não permitir que o sistema faça caching de leitura ou escrita: isso pode ser feito simplesmente adicionando-se a `volatile` _keyword_ precedendo o tipo das _pointer variables_ para os periféricos.

Para demonstrar esta funcionalidade, foi criada uma aplicação _hello_ ([y4k/hello.c](y4k/hello.c))

### Contando instruções

### Avaliando o desempenho

#### CPI médio utilizado para estimativa de número de ciclos:  

#### Número de instruções e total estimado de ciclos:  
