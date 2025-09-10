#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEMA: Ordenação topológica de tarefas com prioridade mínima
    Contexto: Determinar a sequência de execução de tarefas (vértices) respeitando dependências (arestas).
    Estratégia: Algoritmo de Kahn com fila de prioridade para garantir menor índice primeiro.
*/

// Constroi lista de adjacência a partir de arestas
vector<vector<int>> constructadj(int V, const vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]); // adiciona aresta direcionada
    }
    return adj;
}

// Ordenação topológica usando Kahn + fila de prioridade
vector<int> topologicalSort(int V, const vector<vector<int>>& edges) {
    vector<vector<int>> adj = constructadj(V, edges);
    vector<int> indegree(V, 0);

    // calcula grau de entrada de cada vértice
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    priority_queue<int, vector<int>, greater<int>> q; // prioridade mínima
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) // vértices sem dependências
            q.push(i);
    }

    vector<int> result;
    while (!q.empty()) {
        int node = q.top();
        q.pop();
        result.push_back(node);

        // atualiza grau de entrada dos vizinhos
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // se resultado não contém todos os vértices, há ciclo
    if (result.size() != V)
        return {};

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x - 1, y - 1}); // converte para 0-index
    }

    vector<int> result = topologicalSort(n, edges);

    if (result.empty()) {
        cout << "Sandro fails.\n"; // ciclo detectado
    } else {
        for (size_t i = 0; i < result.size(); ++i) {
            cout << result[i] + 1 << " "; // converte de volta para 1-index
        }
        cout << endl;
    }

    return 0;
}
