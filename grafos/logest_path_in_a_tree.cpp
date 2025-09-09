#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
vector<vector<int>> g(MAX);
int dist[MAX];

void dfs(int v)
{
    for (auto w : g[v])
    {
        if (dist[w] == -1)
        {
            dist[w] = dist[v] + 1;
            dfs(w);
        }
    }
}

int main()
{
    int n;
    cin >> n; 

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v; 
        u--; v--; 
        g[u].push_back(v); 
        g[v].push_back(u); 
    }

    memset(dist, -1, sizeof dist); 
    dist[0] = 0;
    dfs(0);

    // Encontra o nó mais distante do nó 0
    int pos = -1, distmax = -1;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] > distmax)
        {
            distmax = dist[i]; 
            pos = i; 
        }
    }

   
    memset(dist, -1, sizeof dist); 
    dist[pos] = 0; // Começa a partir do nó 'pos' encontrado
    dfs(pos); // Roda a DFS a partir de 'pos'

    // Encontra o diâmetro
    int diametro = 0;
    for (int i = 0; i < n; i++)
    {
        // A maior distância encontrada a partir de 'pos' é o diâmetro
        diametro = max(diametro, dist[i]);
    }

    cout << diametro << endl;

    return 0;
}
