## Questão 13, página 194

13. A small business—say, a photocopying service with a single large machine—faces the following scheduling problem. Each morning they get a set of jobs from customers. They want to do the jobs on their single machine in an order that keeps their customers happiest. Customer i’s job will take t i time to complete. Given a schedule (i.e., an ordering of the jobs), let C i denote the finishing time of job i. For example, if job j is the first to be done, we would have C j = t j ; and if job j is done right after job i, we would have C j = C i + t j . Each customer i also has a given weight w i that represents his or her importance to the business. The happiness of customer i is expected to be dependent on the finishing time of i’s job. So the company decides that they want to order the jobs to minimize the weighted sum of the completion times, ni=1 w i C i .
Design an efficient algorithm to solve this problem. That is, you are given a set of n jobs with a processing time t i and a weight w i for each job. You want to order the jobs so as to minimize the weighted sum of the completion times, ni=1 w i C i . 
Example. Suppose there are two jobs: the first takes time t 1 = 1 and has weight w 1 = 10, while the second job takes time t 2 = 3 and has weight w 2 = 2. Then doing job 1 first would yield a weighted completion time of 10 · 1 + 2 · 4 = 18, while doing the second job first would yield the larger weighted completion time of 10 · 4 + 2 · 3 = 46.

#### Contextualização
O problema remete a ideia de que um algoritmo baseado no "Interval Scheduling", porém com modificações necessária para se adequar ao peso de cada tarefa.
Seguindo a mesma ideia utilizada em sala para comprovar a eficiência do algoritmo, três possibilidades foram levantadas para melhor adequação:
* Ordenar  de forma crescente de acordo com o tempo;
* Ordenar  de forma decrescente de acordo com o peso;
* Ordenar  de forma decrescente de acordo com o peso divido pelo tempo;

Afim de definir a melhor possibilidade diversos casos de teste foram gerados e foi possível verficar que duas delas são facilmente quebradas.

* Ordenar  de forma crescente de acordo com o tempo:
Digamos que sejam colocados para análise os seguintes tempos e pesos:
```
t1 = 2, p1 = 3; t2 = 1, p2 = 1;
```
Colocando-os em ordem crescente de tempo, teríamos
```
(t2,p2); (t1,p1);
```
E o resultado final seria:
```
t2*p2 + (t2+t1)*p1 = 1*1 + (1+2)*3 = 10
```
Sendo que se invertermos a execução teríamos:
```
t1*p1 + (t1+t2)*p2 = 2*3 + (2+1)*1 = 9
```

* Ordenar  de forma decrescente de acordo com o peso;
Digamos que sejam colocados para análise os seguintes tempos e pesos:
```
t1 = 100, p1 = 10; t2 = 1, p2 = 9;
```
Colocando-os em ordem crescente de tempo, teríamos
```
(t1,p1); (t2,p2);
```
E o resultado final seria:
```
t1*p1 + (t1+t2)*p2 = 100*10 + (100+1)*9 = 1909
```
Sendo que se invertermos a execução teríamos:
```
t2*p2 + (t2+t1)*p1 = 1*9 + (1+100)*10 = 1019
```

Desse modo, foi decidido que usar o peso/tempo em ordem decrescente seria a melhor opção, visto que quanto maior esse valor, mais ele altera a multiplicação realizada no cálculo de tempo final.

#### Algoritmo
O algoritmo desenvolvido pode ser encontrado no arquivo ```exercicio13.cpp```, ele foi feito especificamente para esse problema e foi testado a partir dos casos de teste guardados na pasta ```input```, o resultado dos mesmos podem ser vistos na pasta ```output```.
Para compilar o código foram usadas as seguintes tags:
```-std=c++11 -O2 -Wall```
O código também foi desenvolvido para que um usuário pudesse testá-lo sem muitas dificuldades, porém não foi feita nenhuma validação de entrada.
Por fim, para utilizá-lo basta seguir os passos:
```$g++ -std=c++11 -O2 -Wall exercicio13.cpp```
```$./a.out```
Caso queira utilizar um dos casos de testes já prontos basta utilizar o comando:
```$./a.out < input/in*```, onde * deve ser substituído pelo valor 1, 2 ou 3.
Lembrando que o terminal deve estar no diretório onde se encontra o arquivo .cpp.

> Os teste das outras possibilidades de ordenação podem ser encontrados ao final do algoritmo em forma de comentário.