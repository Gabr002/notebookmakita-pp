#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Problema (contexto):
    - Dada uma árvore com n nós, queremos determinar o "diâmetro" da árvore
      e calcular para cada nó a distância máxima até uma das extremidades do diâmetro.
    - Solução: usar DFS duas vezes para encontrar as extremidades do diâmetro.
    - Para cada nó, se ele estiver em uma extremidade do diâmetro, adicionamos 1 ao resultado.
*/

const int MAX = 3e5 + 10;
vector<vector<int>> g(MAX); // lista de adjacência da árvore
int dist[MAX];               // distâncias usadas na primeira DFS
int distB[MAX];              // distâncias usadas na segunda DFS

// DFS simples para calcular distâncias a partir do nó v
void dfs(int v) {
    for (auto w : g[v]) {
        if (dist[w] == -1) {
            dist[w] = dist[v] + 1;
            dfs(w);
        }
    }
}

// Segunda DFS para calcular distâncias a partir da outra extremidade
void dfs2(int v) {
    for (auto w : g[v]) {
        if (distB[w] == -1) {
            distB[w] = distB[v] + 1;
            dfs2(w);
        }
    }
}

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl; // caso trivial: uma árvore com 1 nó
        return 0;
    }

    // lê as arestas da árvore (0-based)
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // primeira DFS a partir do nó 0
    memset(dist, -1, sizeof dist);
    dist[0] = 0;
    dfs(0);

    // encontra o nó mais distante a partir do 0 (primeira extremidade do diâmetro)
    int pos = -1, distmax = -1;
    for (int i = 0; i < n; i++) {
        if (dist[i] > distmax) {
            distmax = dist[i];
            pos = i;
        }
    }

    // segunda DFS a partir da primeira extremidade
    memset(dist, -1, sizeof dist);
    dist[pos] = 0;
    dfs(pos);

    // encontra a outra extremidade do diâmetro e calcula o comprimento
    int diametro = 0, posB = -1;
    for (int i = 0; i < n; i++) {
        if (dist[i] > diametro) {
            diametro = dist[i];
            posB = i;
        }
    }

    // DFS a partir da segunda extremidade do diâmetro
    memset(distB, -1, sizeof distB);
    distB[posB] = 0;
    dfs2(posB);

    // imprime para cada nó a distância máxima até uma extremidade do diâmetro
    for (int i = 0; i < n; i++) {
        if (dist[i] == diametro || distB[i] == diametro)
            cout << diametro + 1 << endl;
        else
            cout << diametro << endl;
    }

    return 0;
}
