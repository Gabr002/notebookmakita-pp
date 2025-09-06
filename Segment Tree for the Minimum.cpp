#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

long long vet[MAXN];
long long tree[4 * MAXN];


void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node] = vet[start];
        return;
    }

    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    build(left_child, start, mid);
    build(right_child, mid + 1, end);

    // MUDANÇA: Em vez de somar, pegamos o mínimo dos filhos
    tree[node] = min(tree[left_child], tree[right_child]);
}

// Função para atualizar um valor na árvore
// A única mudança é usar min() em vez de '+'
void update(int node, int start, int end, int idx, int val)
{
    if (start == end)
    {
        tree[node] = val;
        vet[idx] = val;
        return;
    }

    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    if (idx <= mid)
    {
        update(left_child, start, mid, idx, val);
    }
    else
    {
        update(right_child, mid + 1, end, idx, val);
    }

    // MUDANÇA: Recalculamos o mínimo dos filhos após a atualização
    tree[node] = min(tree[left_child], tree[right_child]);
}

// NOVA FUNÇÃO: Para consultar o mínimo em um intervalo [l, r]
long long query(int node, int start, int end, int l, int r)
{
    // Caso 1: O intervalo do nó está totalmente fora do intervalo da consulta
    // Retornamos um valor muito grande para que ele não afete o resultado do min()
    if (r < start || end < l)
    {
        return LLONG_MAX;
    }

    // Caso 2: O intervalo do nó está totalmente dentro do intervalo da consulta
    // Retornamos o valor do nó, que já é o mínimo para este intervalo
    if (l <= start && end <= r)
    {
        return tree[node];
    }

    // Caso 3: O intervalo do nó tem uma sobreposição parcial com o da consulta
    // Dividimos e conquistamos, buscando nos filhos esquerdo e direito
    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    long long p1 = query(left_child, start, mid, l, r);
    long long p2 = query(right_child, mid + 1, end, l, r);

    // Retornamos o mínimo dos resultados das chamadas recursivas
    return min(p1, p2);
}


int main()
{
    // Otimizações de entrada/saída
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }

    // Constrói a árvore com o array inicial
    build(0, 0, n - 1);

    while (m--)
    {
        int type, c=0;
        cin >> type;
        if (type == 1)
        {
            int idx, v;
            cin >> idx >> v;
            update(0, 0, n - 1, idx, v);
        }
        else if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            // Chama a função de consulta. O intervalo é [l, r-1]
            // porque o problema diz que 'r' é exclusivo.
            long long result = query(0, 0, n - 1, l, r - 1);
            cout << result << "\n"; // Usar "\n" é um pouco mais rápido que endl
        }
    }

    return 0;
}
