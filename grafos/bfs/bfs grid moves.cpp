#include <bits/stdc++.h>

using namespace std;

/*
   Problema (contexto):
   - Temos uma matriz n x m representando um mapa.
   - Cada célula pode ser:
       * 'H' → célula de interesse (pode ser visitada)
       * 'o' → ponto de partida
       * outros caracteres → obstáculos ou irrelevantes
   - Queremos encontrar a célula de 'H' que é mais distante do ponto de partida 
     usando movimento ortogonal (cima, baixo, esquerda, direita).
   - Solução: BFS (Breadth-First Search) a partir do ponto 'o'.

   Solução:
   - Marcamos as células visitadas.
   - Usamos BFS para explorar todas as células 'H' conectadas.
   - O último elemento visitado pelo BFS será a célula mais distante.
*/

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef pair<int, int> ii;

const int MAX = 110;

int n, m;
char M[MAX][MAX];      // matriz do mapa
int vis[MAX][MAX];     // marca visitados

// movimentos possíveis (cima, baixo, esquerda, direita)
ii mov[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// função para verificar se podemos visitar a célula (dentro da matriz, não visitada, é 'H')
bool val(int i, int j){
    return i>=0 && j>=0 && i<n && j<m && !vis[i][j] && M[i][j]=='H';
}

// BFS que retorna a célula mais distante do ponto de partida
ii bfs(int i, int j){
    queue<ii> q;
    q.push({i, j});
    vis[i][j] = 1;

    ii ret;
    while(!q.empty()){
        ret = q.front(); q.pop();
        for(int k=0; k<4; k++){
            int new_i = ret.f + mov[k].f;
            int new_j = ret.s + mov[k].s;
            if(val(new_i, new_j)){
                q.push({new_i, new_j});
                vis[new_i][new_j] = 1;
            }
        }
    }
    return ret; // última célula visitada é a mais distante
}

int main(){ _
    memset(vis, 0, sizeof vis);

    // leitura da matriz
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> M[i][j];

    ii ans;
    // procura o ponto de partida 'o' e inicia BFS
    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++) 
            if(M[i][j]=='o')
                ans = bfs(i, j);
    
    // imprime coordenadas da célula mais distante (1-indexed)
    cout << ans.f + 1 << " " << ans.s + 1 << endl;

    return 0;
}
