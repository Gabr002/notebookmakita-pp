#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEMA: Ordenação topológica de um grafo direcionado
    Objetivo: Ordenar os vértices de modo que para cada aresta u->v, u apareça antes de v.
    Estratégia: Usar Kahn's algorithm com fila de prioridade para obter ordem lexicográfica mínima.
*/

// Constrói lista de adjacência a partir da lista de arestas
vector<vector<int>> constructadj(int V, const vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (const auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]); // adiciona aresta u->v
    }
    return adj;
}

// Função principal de ordenação topológica
vector<int> topologicalSort(int V, const vector<vector<int>> &edges)
{
    vector<vector<int>> adj = constructadj(V, edges);

    // calcula grau de entrada de cada vértice
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int neighbor : adj[i])
        {
            indegree[neighbor]++;
        }
    }

    // fila de prioridade para garantir menor índice primeiro
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> result;
    while (!q.empty())
    {
        int node = q.top();
        q.pop();
        result.push_back(node);

        // reduz grau de entrada dos vizinhos
        for (int neighbor : adj[node])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor); // adiciona na fila quando pronto
        }
    }

    // se não foi possível processar todos os vértices, há ciclo
    if (result.size() != V)
        return {};

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        // leitura das arestas (grafo 1-based convertido para 0-based)
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            edges.push_back({x - 1, y - 1});
        }

        vector<int> result = topologicalSort(n, edges);

        // imprime resultado na forma original (1-based)
        for (size_t i = 0; i < result.size(); ++i)
        {
            cout << result[i] + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
