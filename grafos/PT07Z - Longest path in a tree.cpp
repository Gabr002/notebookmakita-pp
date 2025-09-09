#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEMA: Diâmetro de uma árvore
    Objetivo: Encontrar a maior distância entre dois vértices de uma árvore.
    Estratégia: Usar duas DFS:
        1ª DFS a partir de qualquer vértice para achar o vértice mais distante.
        2ª DFS a partir desse vértice para calcular a distância máxima.
*/

const int MAX = 1e4 + 10; // máximo de vértices
vector<vector<int>> adj(MAX); // lista de adjacência
int dist[MAX];                // distâncias durante DFS

// DFS para atualizar distâncias a partir do vértice v
void dfs(int v)
{
    for (auto w : adj[v])
    {
        if (dist[w] == -1) // se não visitado
        {
            dist[w] = dist[v] + 1; // atualiza distância
            dfs(w);                // visita recursivamente
        }
    }
}

int main()
{
    int n, u, v;
    cin >> n;

    // leitura das arestas (árvore com n vértices tem n-1 arestas)
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--, v--;               // converter para índice 0-based
        adj[u].push_back(v);    // adiciona aresta u->v
        adj[v].push_back(u);    // adiciona aresta v->u
    }

    memset(dist, -1, sizeof dist); // inicializa distâncias como -1
    dist[0] = 0;                   // começar DFS do vértice 0
    dfs(0);

    // encontrar o vértice mais distante da primeira DFS
    int pos = -1, max_dist = -1;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] > max_dist)
        {
            max_dist = dist[i];
            pos = i;
        }
    }

    // segunda DFS a partir do vértice mais distante encontrado
    memset(dist, -1, sizeof dist);
    dist[pos] = 0;
    dfs(pos);

    // calcular o diâmetro como a maior distância encontrada
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dist[i]);
    }

    cout << ans; // saída do diâmetro da árvore
}
