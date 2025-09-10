#include <bits/stdc++.h>
using namespace std;

/*
    Problema (contexto):
    - Verificar se um grafo não-direcionado é uma árvore.
    - Condições para ser árvore:
        1. Ter exatamente n-1 arestas.
        2. Ser conexo.
        3. Não ter ciclos.
    - Solução: DFS para detectar ciclos e verificar conectividade.
*/

const int MAX = 1e4 + 10;
vector<vector<int>> adj(MAX);       // lista de adjacência do grafo
vector<bool> vis(MAX, false);       // marca nós visitados
bool temCiclo = false;              // flag para detectar ciclo

// DFS para percorrer o grafo e detectar ciclos
void dfs(int v, int pai) {
    vis[v] = true;
    for (int w : adj[v]) {
        if (!vis[w]) {
            dfs(w, v);
        } else if (w != pai) { // achou ciclo
            temCiclo = true;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // condição rápida: uma árvore deve ter exatamente n-1 arestas
    if (m != n - 1) {
        cout << "NO\n";
        return 0;
    }

    // lê as arestas do grafo (0-based)
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // DFS a partir do nó 0
    dfs(0, -1);

    // verifica se todos os nós foram visitados (grafo conexo)
    bool conexo = true;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            conexo = false;
            break;
        }
    }

    // se conexo e sem ciclos -> é árvore
    if (conexo && !temCiclo)
        cout << "YES\n";
    else
        cout << "NO\n";
}
