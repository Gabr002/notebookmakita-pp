#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int mat[250][250];
const int MAX = 1e5 + 10;
vector<vector<int>> g(MAX);
vector<int> vis;
int c = 0;
void dfs(int cor, int i, int j, int h, int l)
{
    if (i < 0 || i >= h || j < 0 || j >= l || mat[i][j] != cor )
    {
        return;
    }

    mat[i][j] = -1;
    c++;

    dfs(cor, i - 1, j, h, l);

    dfs(cor, i + 1, j, h, l);

    dfs(cor, i, j - 1, h, l);
    dfs(cor, i, j + 1, h, l);
}

int main()
{
    int h, l;
    cin >> h >> l;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < l; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (mat[i][j] != -1)
            {
                c = 0;
                dfs(mat[i][j], i, j, h, l);
                vis.push_back(c);
            }
        }
    }
    sort(vis.begin(), vis.end());

    cout << *vis.begin() << endl;

    return 0;
}
