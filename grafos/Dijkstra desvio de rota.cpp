#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;

/*
   Problema (contexto):
   - Temos cidades numeradas de 0 a n-1, algumas fazem parte de uma rota especial (0 a c-1).
   - Existem estradas com custo entre as cidades (m estradas no total).
   - A ideia é calcular a distância mínima do ponto inicial k até a última cidade da rota c-1,
     levando em conta regras diferentes de conexão:
       * Entre cidades da rota: só conectam sequencialmente (u+1=v ou v+1=u)
       * Entre rota e fora da rota: conexão vai do externo para interno
       * Entre cidades fora da rota: conexão normal
   - Queremos usar Dijkstra para encontrar o caminho mínimo até a cidade c-1.

   Solução:
   - Construímos grafo considerando as regras acima.
   - Usamos vetor dist[] para armazenar menor distância até cada cidade.
   - Aplicamos Dijkstra com priority_queue.
*/

const int N = 260;            // máximo de cidades
vector<int> adj[N], adjw[N];  // adjacências e pesos das arestas
int dist[N];

int main() {

    while(true) {
        int n, m, c, k;
        cin >> n >> m >> c >> k;

        // condição de parada
        if(n == 0 && m == 0 && c == 0 && k == 0) return 0;

        // limpar grafo anterior
        for(int i = 0; i < N; i++) {
            adj[i].clear();
            adjw[i].clear();
        }

        // leitura das estradas
        for(int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;

            if(u < c && v < c) { // dentro da rota especial
                if(u+1 == v) {
                    adj[u].push_back(v);
                    adjw[u].push_back(p);
                }
                if(v+1 == u) {
                    adj[v].push_back(u);
                    adjw[v].push_back(p);
                }
            }
            else if (u < c && v >= c) {   // de fora -> rota
                adj[v].push_back(u);
                adjw[v].push_back(p);
            } 
            else if (v < c && u >= c) {   // de fora -> rota
                adj[u].push_back(v);
                adjw[u].push_back(p);
            } 
            else {                        // fora <-> fora
                adj[u].push_back(v);
                adjw[u].push_back(p);
                adj[v].push_back(u);
                adjw[v].push_back(p);
            }
        }

        // Dijkstra
        memset(dist, 63, sizeof(dist)); // inicializa com "infinito"
        priority_queue<pii> pq;
        dist[k] = 0;                   // distância inicial
        pq.push(make_pair(0, k));

        while(!pq.empty()) {
            int u = pq.top().second;
            int d = -pq.top().first;
            pq.pop();

            if(d > dist[u]) continue;

            for(int i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i];
                int w = adjw[u][i];
                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(-dist[v], v));
                }
            }
        }

        // imprime a distância mínima até a última cidade da rota
        cout << dist[c-1] << "\n";
    }
}
