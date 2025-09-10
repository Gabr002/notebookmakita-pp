#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
   Problema (contexto):

   - Bob acabou de entrar em uma empresa de software com N funcionários.
   - Cada funcionário i (exceto o de ID 1) tem um gerente mi.
   - Funcionários que têm subordinados estão ocupados e delegam tarefas, como responder emails de clientes.
   - Quando um email de reclamação chega a um funcionário:
       * Se ele não tem subordinados, ele responde.
       * Caso contrário, ele encaminha para seu gerente ou algum subordinado, escolhendo quem minimiza o número total de pessoas que receberão o email.
   - O objetivo é calcular o número esperado de pessoas que receberão o email até que ele seja respondido,
     considerando que qualquer funcionário tem a mesma probabilidade de receber o email primeiro.
   - O resultado deve ser representado em módulo 998244353.

   Solução:
   1. Construímos a árvore de funcionários a partir dos gerentes.
   2. Identificamos todos os funcionários sem subordinados (folhas).
   3. Realizamos BFS a partir das folhas para calcular a distância mínima de cada funcionário a uma folha.
   4. Somamos todas as distâncias e aplicamos a fórmula do valor esperado: (sum das distâncias + n) / n.
   5. Usamos exponenciação modular para calcular a divisão módulo 998244353.
*/

const ll MOD = 998244353;
const int N = 2e5 + 10;

vector<int> adj[N]; // lista de adjacência da árvore
int dist[N];        // distância mínima até a folha
queue<int> q;

// BFS a partir de múltiplas fontes (folhas)
void bfs(vector<int> s)
{
    // inicializa todas as distâncias com um valor grande
    for (int i = 1; i <= N; i++)
        dist[i] = N;

    // coloca as folhas na fila com distância 0
    for (auto u : s)
    {
        dist[u] = 0;
        q.push(u);
    }

    // BFS padrão
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

// exponenciação modular rápida: calcula (b^e) % mod
ll fexp(ll b, ll e, ll mod)
{
    ll ans = 1;
    while (e)
    {
        if (e % 2) // se expoente é ímpar
            ans = (ans * b) % mod;
        b = (b * b) % mod; // b = b^2
        e /= 2;            // divide expoente por 2
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> sources; // folhas da árvore

    // leitura da árvore
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    // identifica folhas (grau 1)
    for (int i = 2; i <= n; i++)
    {
        if (adj[i].size() == 1)
            sources.push_back(i);
    }

    // BFS a partir das folhas
    bfs(sources);

    ll sum = 0;
    for (int i = 1; i <= n; i++)
        sum += dist[i];

    // calcula (sum + n) / n módulo MOD
    ll num = (sum + n) % MOD;
    ll den = n % MOD;
    ll den_inv = fexp(den, MOD - 2, MOD); // inverso modular
    ll ans = (num * den_inv) % MOD;

    cout << ans << "\n";
}