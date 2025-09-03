#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1e5 + 10;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

void dfs(int v)
{
    vis[v] = true;
    for (auto w : g[v])
    {
        if (!vis[w])
        {
            dfs(w);
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int times = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            times++;
        }
    }
    cout << times << endl;

    return 0;
}
