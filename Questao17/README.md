## Questão 17, página 197

17. Consider the following variation on the Interval Scheduling Problem. You have a processor that can operate 24 hours a day, every day. People submit requests to run daily jobs on the processor. Each such job comes with a start time and an end time; if the job is accepted to run on the processor, it must run continuously, every day, for the period between its start and end times. (Note that certain jobs can begin before midnight and end after midnight; this makes for a type of situation different from
what we saw in the Interval Scheduling Problem.)
Given a list of n such jobs, your goal is to accept as many jobs as possible (regardless of their length), subject to the constraint that the processor can run at most one job at any given point in time. Provide an algorithm to do this with a running time that is polynomial in n. You may assume for simplicity that no two jobs have the same start or end times.
**Example.** Consider the following four jobs, specified by (start-time, end-time) pairs. 
``` (6 P.M. , 6 A.M. ), (9 P.M. , 4 A.M. ), (3 A.M. , 2 P.M. ), (1 P.M. , 7 P.M. ). ```
The optimal solution would be to pick the two jobs ```(9 P.M. , 4 A.M)``` and ```(1 P.M. , 7 P.M. )```, which can be scheduled without overlapping.

#### Contextualização
Como o próprio exercício sugere, sua resolução é baseada numa variação do algorítmo "Interval Scheduling", adaptado para serviços que funcionam de modo constante durante os dias sequentes.
A ideia inicial para resolução desse problema foi, assim como no algorítmo original, pegar o serviço de menor horário de término e trabalhar a partir dele, porém os serviços que possuiam horário que abragiam dois dias distintos atrapalhavam muito a ordenação. Como solução para isso foi feita uma conversão de valores, deixando o serviço escolhido no inicio com valor de horário inicial igual a meia-noite e todos outros serviços alterados de forma proporcional a isso. Essa solução foi baseada nas resoluções de problemas da geometria computacional que envolvem pontos num plano cartesiano, onde um ponto principal é deslocado para origem, afim de facilitar o manuseio dos outros.
Após validar a conversão, poucos corner cases sobraram para serem avaliados. 
* O caso em que um serviço começava antes do escolhido inicialmente e terminava depois: 
Para solucioná-lo bastou desconsiderar todos serviços que possuiam horário inicial maior que o horário final, visto que, após a conversão, apenas os serviços que entravam nesse corner case satisfaziam essa condições.
* Um serviço que começava após o final do anterior, porém terminava apenas no dia seguinte:
Assim como no primeiro caso, a conversão foi de grande auxílio nesse corner case. Como o primeiro serviço escolhido passou a ter horário inicial a meia-noite, qualquer serviço que terminasse após esse horário deveria ser descartado.

#### Algoritmo
O algoritmo desenvolvido pode ser encontrado no arquivo ```exercicio17.cpp```, ele foi feito especificamente para esse problema e foi testado a partir dos casos de teste guardados na pasta ```input```, o resultado dos mesmos podem ser vistos na pasta ```output```.
Para compilar o código foram usadas as seguintes tags:
```-std=c++11 -O2 -Wall```
O código também foi desenvolvido para que um usuário pudesse testá-lo sem muitas dificuldades, porém não foi feita nenhuma validação de entrada.
Por fim, para utilizá-lo basta seguir os passos:
```$g++ -std=c++11 -O2 -Wall exercicio13.cpp```
```$./a.out```
Caso queira utilizar um dos casos de testes já prontos basta utilizar o comando:
```$./a.out < input/in*```, onde * deve ser substituído pelo valor 1, 2 ou 3.
Lembrando que o terminal deve estar no diretório onde se encontra o arquivo .cpp.