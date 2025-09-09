#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 10;

int n = 8, m = 8;

vector<pair<int, int>> mov = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool val(pair<int, int> u)
{
    return u.first >= 0 && u.first < n && u.second >= 0 && u.second < m;
}
int bfs(pair<int, int> s, pair<int, int> end)
{
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));

    q.push(s);
    dist[s.first][s.second] = 0;

    while (!q.empty())
    {
        pair<int, int> v = q.front();
        q.pop();

        if (v.first == end.first && v.second == end.second)
        {
            return dist[v.first][v.second];
        }

        for (auto u_mov : mov)
        {
            pair<int, int> u = {v.first + u_mov.first, v.second + u_mov.second};

            if (val(u) && dist[u.first][u.second] == -1)
            {
                dist[u.first][u.second] = dist[v.first][v.second] + 1;
                q.push(u);
            }
        }
    }

    return -1;
}

int main()
{
    ll t;
    cin >> t;

    for (int k = 0; k < t; k++)
    {
        string a, b;
        cin >> a >> b;

        int x1 = a[0] - 'a';
        int x2 = b[0] - 'a';

        int y1 = a[1] - '1';
        int y2 = b[1] - '1';

        pair<int, int> s = {y1, x1};
        pair<int, int> r = {y2, x2};

        cout << bfs(s, r) << endl;
    }

    return 0;
}
