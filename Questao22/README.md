22. Consider the Minimum Spanning Tree Problem on an undirected graph G = (V , E), with a cost c e ≥ 0 on each edge, where the costs may not all be different. If the costs are not all distinct, there can in general be many distinct minimum-cost solutions. Suppose we are given a spanning tree T ⊆ E with the guarantee that for every e ∈ T, e belongs to some minimum-cost spanning tree in G. Can we conclude that T itself must be a minimum-cost spanning tree in G? Give a proof or a counterexample with explanation.

#### Contextualização
Analisando primeiro a possibilidade de que T não deve ser uma árvore geradora mínima, era necessário criar um contra-exemplo. Para isso, foi gerado um grafo com 5 nós e 5 arestas, tal que sua lista de adjacências pode ser definida da seguinte forma:
```
A: (B, 1), (E, 2)
B: (A, 1), (C, 2)
C: (B, 2), (D, 3)
D: (C, 3), (E, 3)
E: (A, 2), (D, 3)

# (vértice, peso da aresta)
```
A partir dos algoritmos vistos em sala podemos afirmar que ```E->A->B->C->D``` é uma árvore geradora mínima, assim como ```D->E->A->B->C``` também, ambas com peso total 8.
Tendo em vista as arestas das árvores geradoras mínimas explicitadas, pode-se gerar uma árvore geradora T, tal que as conexões são dadas da seguinte maneira: ```B->A->E->D->C```, que possui peso total 9 e, desse modo, servindo de contra-exemplo para a afirmação dada.

#### Resolução
![contra_exemplo](https://user-images.githubusercontent.com/42645264/57483915-2729b000-727e-11e9-9e48-549163e41e1f.jpg)
