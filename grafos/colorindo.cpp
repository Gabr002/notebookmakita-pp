#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int mat[250][250];

int q = 0;
void dfs(int x, int y, int n, int m)
{
    if (x < 0 || x >= n || y < 0 || y >= m || mat[x][y] != 0)
    {
        return;
    }

    mat[x][y] = 2;
    q++;

    dfs(x - 1, y - 1, n, m);

    dfs(x - 1, y, n, m);

    dfs(x - 1, y + 1, n, m);

    dfs(x + 1, y - 1, n, m);

    dfs(x + 1, y, n, m);

    dfs(x + 1, y + 1, n, m);

    dfs(x, y - 1, n, m);

    dfs(x, y + 1, n, m);
}

int main()
{
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mat[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mat[a][b] = 1;
    }

    dfs(x - 1, y - 1, n, m);
    cout << q << endl;

    return 0;
}
