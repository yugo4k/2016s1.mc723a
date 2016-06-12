### Exercício 4: Plataformas e Periféricos
#### 033324 - Yugo Kuno

---

Este exercício continua o estudo realizado no exercício 3 e no projeto 2, aumentando agora a complexidade da simulação do sistema ao adicionar um _router_ entre as componentes do sistema, periféricos e múltiplos núcleos de processamento à CPU.

Neste experimento foi usado um simulador do processador MIPS, criado com a linguagem ArchC, criado pelo time do IC de mesmo nome e baseado na linguagem de descrição de hardware SystemC. O ArchC permite, entre outras funcionalidades, a avalição do número de execuções de cada tipo de instrução pelo programa.

### Periférico Básico

Nesta etapa o sistema agora não consiste somente em um processador e uma memória diretamente conectados; agora um _router_ faz a interface entre todos os componentes do sistema, permitindo o uso de diversos periféricos concomitantentemente. A forma mais simples de implementar esta comunicação é expandir o conceito de endereçamento utilizado exclusivamente para a memória até agora: a partir do _router_ pode-se acessar a memória usando uma faixa dos endereços disponíveis, enquanto outras faixas de endereços são reservadas para acesso aos periféricos disponíveis. Dessa forma o uso do _router_ fica trasparente e pode-se usar somente um estratégia integrada de comunicação para acesso aos diferentes componentes.

O acesso destes componentes então se dá simplesmente criando _pointers_ para os endereços das _ports_ dos periféricos, de maneira que a comunicação se dá através leituras e escritas de valores através destes canais. Entretanto, como esta comunicação é uma extensão da maneira como se trata a memória, é necessário não permitir que o sistema faça caching de leitura ou escrita: isso pode ser feito simplesmente adicionando-se a `volatile` _keyword_ precedendo o tipo das _pointer variables_ para os periféricos.

Uma demonstração extremamente simples do uso de periféricos é o uso de uma abstração de _hardware_ que implementa a funcionalidade de _lock variable_, em que a leitura e escrita de valores é realizada de maneira atômica, como é necessário para a implementação da lógica de _mutex_ no uso de sistemas com concorrência.

Para demonstrar esta funcionalidade, foi criada uma aplicação _hello_ ([basic_peripheral/y4k/hello.c](basic_peripheral/y4k/hello.c)) que após fazer o display da string "hello." realiza diversos ciclos de 2 leituras no periférico de _lock_ e escrita do mesmo. O trecho abaixo foi retirado do _output_ inicial do mesmo:  
```
hello.

readm,  addr:0x06400000, data:0000000000
global_lock: |       0|
readm,  addr:0x06400000, data:0000000000
global_lock: |       1|

writem, addr:0x06400000, data:0000000000

readm,  addr:0x06400000, data:0000000000
global_lock: |       0|
readm,  addr:0x06400000, data:0000000000
global_lock: |       1|

writem, addr:0x06400000, data:0x00000001

readm,  addr:0x06400000, data:0000000000
global_lock: |       1|
readm,  addr:0x06400000, data:0000000000
global_lock: |       1|

writem, addr:0x06400000, data:0x00000002

readm,  addr:0x06400000, data:0000000000
global_lock: |       2|
readm,  addr:0x06400000, data:0000000000
global_lock: |       1|
```

Como percebe-se acima, a leitura (_readm_) do valor armazenado no periférico (addr:0x06400000) atômicamente retorna o para o _caller_ e então altera o valor armazenado para 1; a escrita meramente o altera para o valor desejado.  
Isto serve como a funcionalidade de _mutex_ desejada:
- uma leitura do valor 1 significa que o _lock_ já foi adquirido por outro processo,
- uma leitura de 0 significa que este processo conseguiu o lock e outros programas não conseguirão o mesmo _lock_ independentemente do fluxo de processamento (visto que o valor foi atômicamente alterado para 1)...
- enquanto a escrita do valor 0 no periférico não for realizada (quando o processo que conseguiu o _lock_ sair região crítica).



### Plataforma multicore

