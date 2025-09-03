#include <bits/stdc++.h>
using namespace std;

#define MAXN 100100

int n;
int m;
vector<int> grafo[MAXN];
int grau[MAXN];

vector<int> lista_final;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        grau[y]++;
        grafo[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        if (grau[i] == 0)
        {
            pq.push(i);
        }
    }

    while (!pq.empty())
    {
        int atual = pq.top();
        pq.pop();

        lista_final.push_back(atual);

        for (int i = 0; i < (int)grafo[atual].size(); i++)
        {
            int v = grafo[atual][i];
            grau[v]--;
            if (grau[v] == 0)
            {
                pq.push(v);
            }
        }
    }

    if ((int)lista_final.size() < n)
    {
        cout << "Sandro fails." << endl;
    }
    else
    {
        for (int i = 0; i < (int)lista_final.size(); i++)
        {
            cout << lista_final[i] << " ";
        }
        cout << endl;
    }

    return 0;
}