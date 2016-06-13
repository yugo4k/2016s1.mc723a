### Exercício 4: Plataformas e Periféricos
#### 033324 - Yugo Kuno

---

Este exercício continua o estudo realizado no exercício 3 e no projeto 2, aumentando agora a complexidade da simulação do sistema ao adicionar um _router_ e um periférico entre os componentes do sistema, além de colocar um núcleo de processamento adicional à CPU.

Neste experimento foi usado um simulador do processador MIPS, criado com a linguagem ArchC, criado pelo time do IC de mesmo nome e baseado na linguagem de descrição de hardware SystemC. O ArchC permite, entre outras funcionalidades, a avalição do número de execuções de cada tipo de instrução pelo programa.

### Periférico Básico

Nesta etapa o sistema não consiste somente em um processador e uma memória diretamente conectados; agora um _router_ faz a interface entre todos os componentes do sistema, permitindo o uso de diversos periféricos concomitantentemente. A forma mais simples de implementar esta comunicação é expandir o conceito de endereçamento utilizado exclusivamente para a memória até agora: a partir do _router_ pode-se acessar a memória usando uma faixa dos endereços disponíveis, enquanto outras faixas de endereços são reservadas para acesso aos periféricos disponíveis. Dessa forma o uso do _router_ fica trasparente e pode-se usar somente um estratégia integrada de comunicação para acesso aos diferentes componentes.

O acesso destes componentes então se dá simplesmente criando _pointers_ para os endereços das _ports_ dos periféricos, de maneira que a comunicação se dá através leituras e escritas de valores através destes canais. Entretanto, como esta comunicação é uma extensão da maneira como se trata a memória, é necessário não permitir que o sistema faça caching de leitura ou escrita: isso pode ser feito simplesmente adicionando-se a `volatile` _keyword_ precedendo o tipo das _pointer variables_ para os periféricos.

Uma demonstração extremamente simples do uso de periféricos é o uso de uma abstração de _hardware_ que implementa a funcionalidade de _lock variable_, em que a leitura e escrita de valores é realizada de maneira atômica, como é necessário para a implementação da lógica de _mutex_ no uso de sistemas com concorrência.

Para demonstrar esta funcionalidade, foi criada uma ([aplicação](basic_peripheral/y4k/hello.c)) que após fazer o display da string "hello." realiza diversos ciclos de 2 leituras no periférico de _lock_ e escrita do mesmo. O trecho abaixo foi retirado do _output_ inicial do mesmo:  
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

Fazendo modificações no código da simulação com a adição de um processador adicional conforme instruções em [Multicore_Lock.pdf](./Multicore_Lock.pdf), foi possível criar uma aplicação que realiza a soma dos primeiros 92683 números naturais (incluindo o 0), com as operações de soma divididas entre os dois _cores_.

Entretanto as instruções acima, excerto do livro _Electronic System Level Design_, não parecem corresponder a versão do ArchC utilizada nesta atividade. O principal dos problemas foi a aparente impossibilidade de efetivamente separar os _stacks_ do _main_ executado por cada _core_, além de aparentemente as variáveis locais estarem fora da faixa de memória reservada ao _stack_.

A solução encontrada foi a separação do fluxo de execução através de funções com nomes diferentes, `submain1` e `submain2`; mesmo assim variáveis locais criadas em cada função acabavam ocupando o mesmo espaço de memória, tal que a execução de um função interferia com o funcionamento da outra, tal que como último _work-around_ todas as variáveis utilizadas foram globais. Obviamente esta não é uma solução ideal, entretanto não foi possível determinar a causa do funcionamento inesperado do simulador mesmo utilizando-se horas no estudo do funcionamento do mesmo.

A execução do aplicativo de soma ([_source_](multi-core_platform/y4k/hello.c)) que pode ser compilada e executada com este [_shell-script_](multi-core_platform/y4k/do_all.sh) mostra que o resultado é o esperado, uma soma de valor 4294930221, e os comandos _printf_ comentados, se ativados, mostram que o fluxo de execução é correto. Entretanto o número de instruções executadas também parece estar errado, somando todas as instruções executadas por ambos os _cores_ em apenas um contador. O resultado segue:  
```
        SystemC 2.3.1-Accellera --- Mar 31 2016 17:15:46
        Copyright (c) 1996-2014 by all Contributors,
        ALL RIGHTS RESERVED
ArchC: Reading ELF application file: /home/ec2014/ra033324/y4k/classes/mc723a/git_2016s1.mc723a/exercicio4/multi-core_platform/mips-tlm//../y4k/hello.mips
ArchC: -------------------- Starting Simulation --------------------
ArchC: Reading ELF application file: /home/ec2014/ra033324/y4k/classes/mc723a/git_2016s1.mc723a/exercicio4/multi-core_platform/mips-tlm//../y4k/hello.mips
ArchC: -------------------- Starting Simulation --------------------

submain1 started
submain2 started
submain2 finished
ArchC: -------------------- Simulation Finished --------------------


 The sum of the first 92682 numbers (including 0) squared is 4294930221.


submain1 finished
ArchC: -------------------- Simulation Finished --------------------

Info: /OSCI/SystemC: Simulation stopped by user.
ArchC: Simulation statistics
    Times: 0.30 user, 0.00 system, 0.31 real
    Number of instructions executed: 2516113
    Simulation speed: 8387.04 K instr/s
ArchC: Simulation statistics
    Times: 0.30 user, 0.00 system, 0.30 real
    Number of instructions executed: 2506206
    Simulation speed: 8354.02 K instr/s
```

A segunda contagem (do segundo _core_) tem cerca de 10000 instruções a menos que a primeira (do primeiro _core_); isso ocorre porque `submain1` termina depois de `submain2`, visto que o anterior faz a soma e mostra o resultado no _display_. Esta diferença permanece aproximadamente constante mesmo alterando-se o número de elementos na _array_ somada.

Assim, apesar de se ter atingido o objetivo de rodar a aplicação com comandos separados entre os dois _cores_ simulando o paralelismo, obviamente houveram problemas de implementação, o que se pretende sanar o mais rápido possível para a realização do projeto 3.
