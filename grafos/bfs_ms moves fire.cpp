#include <bits/stdc++.h>

using namespace std;

/*
   Problema (contexto):
   - Temos um mapa n x m com:
       * '#' → parede
       * '.' → espaço livre
       * '*' → fogo (pode se espalhar)
       * '@' → posição do jogador
   - O fogo se espalha para células adjacentes a cada passo.
   - O jogador pode se mover para células livres.
   - Objetivo: sair do mapa (atingir qualquer borda) antes do fogo chegar.
   - Solução: BFS multi-fonte para fogo + BFS para jogador.

   Solução:
   1. Usamos uma BFS multi-fonte para calcular a distância mínima do fogo a cada célula.
   2. Usamos BFS para o jogador, garantindo que ele só entra em células onde não será atingido pelo fogo antes dele.
   3. Retornamos o número mínimo de passos para sair ou "IMPOSSIBLE" se não houver saída.
*/

const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;

int dist[N][N];      // distância mínima de cada célula
char adj[N][N];       // mapa
bool vis[N][N];       // células visitadas
int n, m;

// movimentos ortogonais possíveis (cima, baixo, direita, esquerda)
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

// verifica se a célula é válida para mover/visitar
bool val(pair<int, int> u) {
    return u.first >= 0 && u.second >= 0 && u.first < n && u.second < m &&
           adj[u.first][u.second] != '#' && !vis[u.first][u.second];
}

// BFS multi-fonte: propaga o fogo para calcular a distância mínima a cada célula
void bfs_ms(vector<pair<int, int>> ms) {
    memset(vis, 0, sizeof vis);
    memset(dist, INF, sizeof dist);
    queue<pair<int, int>> q;

    for (auto s : ms) {
        q.push(s);
        vis[s.first][s.second] = 1;
        dist[s.first][s.second] = 0;
    }

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        for (auto u : moves) {
            u.first += v.first;
            u.second += v.second;
            if (val(u)) {
                q.push(u);
                vis[u.first][u.second] = 1;
                dist[u.first][u.second] = dist[v.first][v.second] + 1;
            }
        }
    }
}

// BFS para o jogador: retorna passos mínimos para escapar ou -1 se impossível
int bfs(pair<int, int> s) {
    memset(vis, 0, sizeof vis);
    queue<pair<int, int>> q;
    q.push(s);
    vis[s.first][s.second] = 1;
    dist[s.first][s.second] = 0;

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        // se chegou em borda, escapou
        if (v.first == 0 || v.first == n-1 || v.second == 0 || v.second == m-1)
            return dist[v.first][v.second] + 1;

        for (auto u : moves) {
            u.first += v.first;
            u.second += v.second;
            // só entra se não visitado e jogador chega antes do fogo
            if (val(u) && dist[v.first][v.second] + 1 < dist[u.first][u.second]) {
                q.push(u);
                vis[u.first][u.second] = 1;
                dist[u.first][u.second] = dist[v.first][v.second] + 1;
            }
        }
    }

    return -1; // impossível escapar
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        vector<pair<int, int>> ms; // posições do fogo
        pair<int, int> s;          // posição do jogador

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> adj[i][j];
                if (adj[i][j] == '*') ms.push_back({i, j});
                if (adj[i][j] == '@') s = {i, j};
            }
        }

        bfs_ms(ms);          // propaga fogo
        int ans = bfs(s);    // calcula escape do jogador

        if (ans == -1) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }
}
