#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);
vector<int> pai(MAX);
int dist[MAX];
int cat[MAX];

void dfs(int v, int m)
{
    for (auto w : g[v])
    {
        if (dist[w] == -1)
        {
            if (cat[w] == 0 && dist[v] <= m)
            {
                dist[w] = 0;
            }
            else
            {
                dist[w] = dist[v] + cat[w];
            }
            dfs(w, m);
        }
    }
}

int main()
{
    int n, m, r = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        cat[i] = a;
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
    dist[0] = cat[0];
    dfs(0, m);

    for (int i = 0; i < n; i++)
    {
        bool eh_folha = (i != 0 && g[i].size() == 1) || (n == 1 && i == 0);

        if (eh_folha)
        {
            // cout<<"no folha "<<i+1<<" "<<dist[i]<<endl;

            if (dist[i] <= m)
            {
                r++;
            }
        }
    }
    cout << r << endl;

    return 0;
}
