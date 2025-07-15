# Alkane

Problema no Atcoder: [https://atcoder.jp/contests/abc394/tasks/abc394_f](https://atcoder.jp/contests/abc394/tasks/abc394_f)
Submissão: [https://atcoder.jp/contests/abc394/submissions/67612429](https://atcoder.jp/contests/abc394/submissions/67612429)

O código realiza o processamento de uma árvore não direcionada com o objetivo de encontrar, entre todos os vértices, aquele que pode formar a maior estrutura ramificada possível, considerando até quatro subárvores descendentes a partir de um único nó. O modelo segue uma lógica semelhante à de uma molécula do tipo alkane, onde só são permitidos nós de grau 1 (folhas) e nós de grau 4 (como o carbono central). 

Inicialmente, o programa lê um número inteiro n, que representa a quantidade de vértices da árvore. Em seguida, são lidas n−1 arestas, definindo a estrutura da árvore como um grafo conexo e acíclico. Essas conexões são armazenadas em uma lista de adjacência, representada por um vetor de vetores.

Após a construção da árvore, o algoritmo utiliza uma abordagem de programação dinâmica sobre grafos, com uma função recursiva que simula uma busca em profundidade (DFS). A cada nó visitado, são calculadas e armazenadas até quatro métricas distintas, representadas por um vetor memo[i][*] para cada nó i:

*  memo[i][0]: representa a presença isolada do nó i, com valor 1.

* memo[i][1]: representa o nó i junto com a subárvore de maior profundidade entre seus filhos.

* memo[i][2]: representa o nó i conectado às três maiores subárvores formadas por seus filhos.

* memo[i][3]: representa a estrutura mais extensa possível a partir do nó i, utilizando até quatro ramos descendentes, e considerando tanto estruturas profundas quanto largas.

Durante o processamento, para cada nó i, o algoritmo coleta os valores máximos entre os filhos de i (excluindo o pai, para evitar ciclos) e ordena essas métricas em ordem decrescente. A partir daí, são realizadas combinações das maiores subárvores possíveis, atribuindo os resultados às posições correspondentes em memo[i].

A etapa final consiste em percorrer todos os nós da árvore e selecionar aquele cujo memo[i][3] apresenta o maior valor. Esse valor é então impresso como resultado. Ele representa o maior número de vértices que podem ser cobertos por uma estrutura em forma de "estrela" (ou cruz) com até quatro ramificações originadas de um único nó central, aproveitando as maiores extensões possíveis em cada direção.

# Breakdown

Problema no Atcoder: [https://atcoder.jp/contests/abc341/tasks/abc341_f](https://atcoder.jp/contests/abc341/tasks/abc341_f)
Submissão: [https://atcoder.jp/contests/abc341/submissions/67612448](https://atcoder.jp/contests/abc341/submissions/67612448)

Este programa implementa um algoritmo baseado em programação dinâmica sobre grafos ponderados, com o objetivo de maximizar uma função de valor associada a cada vértice, considerando restrições de peso acumulado. A estrutura de entrada consiste em um grafo não direcionado e ponderado indiretamente, onde cada vértice possui dois atributos: um peso e um valor individual.

O programa inicia lendo dois inteiros n e m, que representam respectivamente o número de vértices e o número de arestas do grafo. Em seguida, são lidas as m arestas que compõem a estrutura do grafo, sendo estas armazenadas em uma lista de adjacência. Cada vértice possui ainda dois atributos adicionais:

* w[i]: o peso do vértice i, utilizado como restrição de acúmulo no processo de transição dinâmica;

* a[i]: o valor associado ao vértice i, utilizado no cálculo da resposta final.

Em seguida, os vértices são ordenados em ordem crescente de peso, por meio de um vetor ps que armazena os índices dos vértices e os organiza de acordo com os valores de w[i].

A principal estrutura do algoritmo é um vetor de programação dinâmica dp[x][j], onde x representa um vértice e j representa uma quantidade acumulada de peso. O valor armazenado em dp[x][j] indica a melhor soma de valor alcançada ao chegar no vértice x com peso acumulado j. Todos os valores da matriz são inicialmente definidos com um valor negativo muito alto (−∞), exceto dp[x][0] = 0 para cada vértice x, o que representa o caso base sem acúmulo de peso.

O algoritmo então percorre os vértices em ordem crescente de peso e, para cada vértice x, tenta propagar valor a partir de seus vizinhos. A lógica de transição considera apenas vizinhos y que possuem peso menor do que x (por conta da ordenação), evitando ciclos e garantindo a validade das etapas.

Para cada vizinho y de x, e para cada possível valor de peso j tal que j + w[y] < w[x], o algoritmo verifica se é possível obter uma configuração melhor atualizando dp[x][j + w[y]] com base em dp[x][j] + best[y].second + 1, onde best[y].second representa a melhor soma de valor já registrada para o vértice y em qualquer caminho anterior. Se a nova configuração for melhor, os vetores dp e pred são atualizados. O vetor pred armazena os predecessores de cada estado da DP para eventual reconstrução do caminho ótimo, embora não seja utilizado para isso neste código.

O vetor best[x] guarda o melhor estado de dp[x][*], isto é, o maior valor obtido para qualquer peso acumulado em x, permitindo acesso eficiente à melhor configuração por vértice.

Ao final, o algoritmo calcula a resposta total. Para cada vértice x, ele considera o melhor valor acumulado obtido (best[x].second) e o multiplica pelo valor associado a[x]. Esse produto é somado à resposta final ans, considerando também o próprio valor a[x] uma vez (por isso o +1 multiplicando o valor). O resultado final, portanto, é a soma ponderada das melhores sequências possíveis iniciando ou terminando em cada vértice, sob restrições de acúmulo de peso.
Objetivo do Algoritmo

# Negative Traveling Salesman

Problema: [https://atcoder.jp/contests/abc338/tasks/abc338_f](https://atcoder.jp/contests/abc338/tasks/abc338_f)
Submissão: [https://atcoder.jp/contests/abc338/submissions/67612423](https://atcoder.jp/contests/abc338/submissions/67612423)

Resolve-se uma versão do Problema do Caixeiro Viajante (TSP) em um grafo direcionado e ponderado, com o objetivo de encontrar o menor custo para visitar todos os vértices exatamente uma vez, iniciando e terminando em quaisquer vértices.

Primeiramente, o programa lê o número de vértices n e arestas m, e constrói uma matriz de adjacência dist[n][n], onde dist[u][v] representa o menor custo entre dois vértices diretamente conectados. Para garantir as menores distâncias possíveis entre todos os pares, aplica-se o Floyd–Warshall, que permite calcular caminhos mínimos entre todos os vértices.

Em seguida, utiliza-se programação dinâmica com bitmask, por meio da matriz dp[i][mask], onde:

* i representa o vértice atual,

* mask representa o conjunto de vértices já visitados (codificado em binário),

* dp[i][mask] guarda o menor custo para atingir o vértice i após visitar os vértices em mask.

A DP é iniciada considerando todos os vértices como possíveis pontos de partida, com custo zero. Depois, para cada estado válido, tenta incluir um novo vértice j ainda não visitado, atualizando os custos quando um caminho melhor é encontrado.

Ao final, verifica o menor custo necessário para visitar todos os vértices (mask == (1 << n) - 1). Se esse valor for infinito, significa que não existe um caminho válido cobrindo todos os vértices, e o programa imprime "No". Caso contrário, imprime o menor custo encontrado.