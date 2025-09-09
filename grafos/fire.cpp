#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;

const int MAX = 1e3 + 10;
const int INF = 0x3f3f3f3f;

char M[MAX][MAX];
int dist[MAX][MAX], vis[MAX][MAX];
int n, m;
pair<int, int> mov[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool val(pair<int, int> u)
{
    return u.f >= 0 and u.f < n and u.s >= 0 and u.s < m and !vis[u.f][u.s] and M[u.f][u.s] == '.';
}

void bfs_ms(vector<pair<int, int>> mult_s)
{
    queue<pair<int, int>> q;
    for (auto s : mult_s)
        q.push(s), vis[s.f][s.s] = 1, dist[s.f][s.s] = 0;

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            pair<int, int> u;
            u.f = v.f + mov[k].f, u.s = v.s + mov[k].s;
            if (val(u))
            {
                q.push(u);
                vis[u.f][u.s] = 1, dist[u.f][u.s] = dist[v.f][v.s] + 1;
            }
        }
    }
}

int bfs(pair<int, int> s)
{
    queue<pair<int, int>> q;
    q.push({s.f, s.s}), vis[s.f][s.s] = 1, dist[s.f][s.s] = 0;

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();

        if (v.f == 0 or v.f == n - 1 or v.s == 0 or v.s == m - 1)
            return dist[v.f][v.s] + 1;

        for (int k = 0; k < 4; k++)
        {
            pair<int, int> u;
            u.f = v.f + mov[k].f, u.s = v.s + mov[k].s;
            if (val(u) and dist[u.f][u.s] > dist[v.f][v.s] + 1)
            {
                q.push(u), vis[u.f][u.s] = 1;
                dist[u.f][u.s] = dist[v.f][v.s] + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> M[i][j];

        vector<pair<int, int>> mult_s;
        pair<int, int> s;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == '*')
                    mult_s.pb({i, j});
                if (M[i][j] == '@')
                    s.f = i, s.s = j;
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vis[i][j] = 0, dist[i][j] = INF;
        bfs_ms(mult_s);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vis[i][j] = 0;
        int ans = bfs(s);

        if (ans == -1)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ans << endl;
    }
    exit(0);
}