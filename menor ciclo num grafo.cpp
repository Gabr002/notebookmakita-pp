#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const long long INF = 4e18;
typedef long long ll;

int n, m, x, y;
long long w[MAXN][MAXN], d[MAXN][MAXN];
int prox[MAXN][MAXN];
bool self_loop[MAXN]; 

vector<int> get_path(int u, int v)
{
    if (prox[u][v] == -1)
        return {};
    vector<int> path;
    path.push_back(u);
    while (u != v)
    {
        u = prox[u][v];
        path.push_back(u);
    }
    return path;
}

void menor_ciclo()
{
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = w[i][j];

    // Floyd–Warshall
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (d[i][k] >= INF)
                continue;
            for (int j = 0; j < n; j++)
            {
                if (d[k][j] >= INF)
                    continue;
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    prox[i][j] = prox[i][k];
                }
            }
        }
    }

    ll length = INF;
    x = y = -1;


    for (int i = 0; i < n; i++)
    {
        if (self_loop[i] && 1 < length)
        { 
            length = 1;
            x = y = i;
        }
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (d[i][j] < INF && d[j][i] < INF)
            {
                ll ciclo = d[i][j] + d[j][i];
                if (ciclo < length)
                {
                    length = ciclo;
                    x = i;
                    y = j;
                }
            }
        }
    }

    if (length >= INF)
    {
        cout << "-1\n";
        return;
    }


    if (x == y)
    {
        cout << x << "\n";
    }
    else
    {
        vector<int> p1 = get_path(x, y);
        vector<int> p2 = get_path(y, x);
        for (int v : p1)
            cout << v << " ";
        for (int k = 1; k < (int)p2.size()-1; k++)
        {
            if (k + 1 == (int)p2.size())
                cout << p2[k];
            else
                cout << p2[k] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        self_loop[i] = false;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                w[i][j] = 0;
                prox[i][j] = i;
            }
            else
            {
                w[i][j] = INF;
                prox[i][j] = -1;
            }
        }
    }

    while (m--)
    {
        int u, v;
        long long peso = 1;
        cin >> u >> v;
        if (u == v)
            self_loop[u] = true;
        if (peso < w[u][v])
        {
            w[u][v] = peso;
            prox[u][v] = v;
        }
    }

    menor_ciclo();
    return 0;
}
