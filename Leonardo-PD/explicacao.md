# Programação Dinâmica - Leonardo Machado

## Strange Bank

Plataforma: AtCoder

Dificuldade: Green (Fácil)

[Link para enunciado](https://atcoder.jp/contests/abc099/tasks/abc099_c)

### Solução

O problema é resolvido da mesma maneira que o problema dos selos. Nesse caso as trasnsações de potência 6 e 9, e a transação de 1 iene são os selos. Como o maior caso de teste é 100 000 ienes, precisamos das potências de 6 e 9 menores ou iguais a esse valor. Sendo assim, os selos seriam:

1, 

Potẽncias de 6:

6, 36, 216, 1 296, 7 776, 46 656, 

Potências de 9:

9, 81, 729, 6 561, 59 049

De forma que a maior tabela possível seria:
|Selos/Valores |0|1|2|...| 100 000|
|-             |-|-|-|-  |-|
|1             | | | |   | |
|6             | | | |   | |
|9             | | | |   | |
|36            | | | |   | |
|81            | | | |   | |
|216           | | | |   | |
|729           | | | |   | |
|1 296         | | | |   | |
|6 561         | | | |   | |
|7 776         | | | |   | |
|46 656        | | | |   | |
|59 049        | | | |   | |


De forma que, no pior caso seriam na ordem de $12 \cdot 10⁵ $ operações, em que $12$ é a quantidade de selos, e $10⁵$ o maior troco possível.

[Link para o código](./strange_bank.cpp)

[Link da Submissão](https://atcoder.jp/contests/abc099/submissions/67610262)

## Ilya and Queries

Plataforma: Codeforces

Dificuldade: Apprendice (Médio)

[Link para enunciado](https://codeforces.com/problemset/problem/313/B)

### Solução

Esse problema tem como base realizar somas de prefixo de forma similar ao algoritmo de Kadane, em que se usa um vetor para memorização, e tem complexidade $O(n)$ para calcular todos os prefixos. Nesse caso, o prefixo consiste em calcular quantos pares $s_i = s_{i+1}$ existem entre o início da string e a o caracter $i+1$. Tomemos como base o exemplo:

$s$:

|.|.|#|#|.|#|#|.|
|-|-|-|-|-|-|-|-|

As contagens de memorização seriam as seguintes para cada posição:

$memo$:

|0|1|1|2|2|2|3|3|
|-|-|-|-|-|-|-|-|

Dessa forma, conseguimos respoder as queries em $O(1)$, pois, para saber quantos pares $s_i = s_{i+1}$ existem para qualquer substring de s que esteja entre duas posições $x,y$, em que $x < y$ basta fazer:

```
memo[y] - memo[x]
```

[Link para o código](./ilya_and_queries.cpp)

[Link da Submissão](https://codeforces.com/problemset/submission/313/328973159)


## Glider

Plataforma: Codeforces

Dificuldade: Expert (Difícil)

[Link para enunciado](https://codeforces.com/problemset/problem/1041/D)

### Solução

Esse problema pode ser resolvido usando uma estratégia similar ao Weighted Interval Scheduling. Nele, é preciso saber quais colunas de ar são "compatíveis", de forma que, até qual coluna de ar adiante é possível ir, a partir de uma coluna $i$. 

Com essa informação, é possível usar uma estratégia de programação dinâmica e memorização, para saber se é melhor saltar da coluna $i$ atual, ou se é melhor usar o salto feito na coluna $i+1$. Resultando na seguinte relação de recorrência:

```
  opt(i, h) = max { opt(i+1, h),  opt(p(i), h - drop(i)) } 
```

Em que $i$ é a coluna de ar atual, $h$ é a altura do salto, $p(i)$ é a coluna mais adiante em que é possível chegar e $drop(i)$ é a queda de $i$ para $p(i)$.


[Link para o código](./glider.cpp)

[Link da Submissão](https://codeforces.com/problemset/submission/1041/328973577)
