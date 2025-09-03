#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 3e5 + 10;
vector<vector<int>> g(MAX);
int dist[MAX];
int distB[MAX];

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
void dfs2(int v)
{
    for (auto w : g[v])
    {
        if (distB[w] == -1)
        {
            distB[w] = distB[v] + 1;
            dfs2(w);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(dist, -1, sizeof dist);
    dist[0] = 0;
    dfs(0);

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
    dist[pos] = 0;
    dfs(pos);

    int diametro = 0;
    int posB = -1;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] > diametro)
        {
            diametro = dist[i];
            posB = i;
        }
    }

    memset(distB, -1, sizeof dist);
    distB[posB] = 0;
    dfs2(posB);

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == diametro || distB[i] == diametro)
        {

            cout << diametro + 1 << endl;
        }
        else
        {
            cout << diametro << endl;
        }
    }

    return 0;
}
