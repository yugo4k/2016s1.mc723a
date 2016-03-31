### Projeto 1, parte 3
### Avaliação dos benchmarks realizados
#### 033324 - Yugo Kuno

Como diversos benchmarks diferentes foram realizados, existem múltiplos parâmetros avaliados que variam de benchmark para benchmark; além disso em média cada máquina passou por apenas 3 das 8 opções de benchmark possíveis.  
Assim torna-se necessário limitar o escopo de avaliação das máquinas, escolhendo-se alguns critérios de avaliação fundamentais. Obviamente o tempo de execução é um dos mais importantes a serem avaliados.  

Entretanto, mesmo essa medida aparentemente simples pode ter significados diferentes entre as opções de avaliação e com relação a qual parte da máquina está sendo avaliada.  
Por exemplo, muitos grupos não apresentaram o melhor tempo de execução, escolhendo apresentar apenas o tempo médio; outros entendem que o tempo médio pode ser fortemente afetado pelo load da máquina devido a outros processos em execução, tal que a melhor medida é o menor tempo.  
Outro exemplo é qual parte da máquina afeta mais significativamente o benchmark em questão (qual o _bottleneck_): a performance da CPU ou da GPU? Talvez o maior atraso seja devido ao barramento devido à comunicação de dados inerente ao benchmark?  

Apesar de todas essas preocupações serem válidas, este relatório tornaria-se excessivamente longo caso cada possibilidade fosse avaliada. Assim, para a mensuração de performance da máquina em relação ao tempo de execução, de cada benchmark foi escolhida uma medida de tempo (o menor tempo onde disponível).  
Como os tempos de cada benchmark variam significativamente, para que se pudesse compor um score comparável entre diferentes benchmarks, o tempo de execução pela máquina foi dividido pela média de tempo daquele benchmark, tal que as melhores máquinas tem o menor score. Para que se possa então utilizar esses scores de diferentes benchmarks, para cada máquina o score final de tempo foi calculado como a média dos scores em cada benchmark; além disso máquinas com menos de 3 medidas foram consideradas sub-avaliadas e não participaram do _ranking_ das máquinas mais rápidas.

