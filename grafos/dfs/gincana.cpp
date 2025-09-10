#include <bits/stdc++.h>
using namespace std;

/*
    Problema (contexto):
    - Contar o número de componentes conexas em um grafo não-direcionado.
    - Estratégia: DFS para marcar todos os nós de cada componente.
    - Cada vez que iniciamos um DFS em um nó não visitado, encontramos uma nova componente.
*/

typedef long long ll;
const int MAX = 1e5 + 10;

vector<vector<int>> g(MAX); // lista de adjacência do grafo
vector<bool> vis(MAX);       // marca nós visitados

// DFS para visitar todos os nós de uma componente
void dfs(int v) {
    vis[v] = true;
    for (auto w : g[v]) {
        if (!vis[w]) {
            dfs(w);
        }
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    // lê as arestas do grafo (0-based)
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int componentes = 0;

    // percorre todos os nós e conta componentes
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            componentes++;
        }
    }

    cout << componentes << endl;

    return 0;
}
