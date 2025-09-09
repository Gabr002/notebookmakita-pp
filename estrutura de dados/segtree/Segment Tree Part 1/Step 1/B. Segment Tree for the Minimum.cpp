#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
   Problema (contexto):
   - Temos um array de tamanho n.
   - Precisamos processar m operações de dois tipos:
       1) Atualizar o valor em uma posição.
       2) Consultar o valor mínimo em um intervalo [l, r).
   - Segment Tree permite resolver essas operações em O(log n) cada.

   Estrutura:
   - st[]: guarda os valores mínimos dos intervalos.
   - v[]: array original.
   - build(): constrói a árvore.
   - query(): retorna o mínimo em um intervalo.
   - update(): atualiza valor em uma posição.
*/

const int N = 100000 + 10;
const int INF = 1e9 + 10;

int st[4 * N], v[N];

// constrói a segment tree no intervalo [l, r] com raiz p
void build(int p, int l, int r) {
    if (l == r) {
        st[p] = v[l]; // nó folha
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);       // filho esquerdo
    build(2 * p + 1, m + 1, r); // filho direito
    st[p] = min(st[2 * p], st[2 * p + 1]); // atualiza mínimo
}

// consulta o mínimo no intervalo [i, j]
int query(int p, int l, int r, int i, int j) {
    if (r < i || j < l) return INF;         // fora do intervalo
    if (i <= l && r <= j) return st[p];     // totalmente dentro
    int m = (l + r) / 2;
    int x = query(2 * p, l, m, i, j);
    int y = query(2 * p + 1, m + 1, r, i, j);
    return min(x, y);                       // mínimo entre filhos
}

// atualiza a posição x para valor val
void update(int p, int l, int r, int x, int val) {
    if (x < l || x > r) return;             // fora do intervalo
    if (l == r && l == x) {                 // nó folha
        st[p] = val;
        return;
    }
    int m = (l + r) / 2;
    update(2 * p, l, m, x, val);           // filho esquerdo
    update(2 * p + 1, m + 1, r, x, val);   // filho direito
    st[p] = min(st[2 * p], st[2 * p + 1]); // atualiza mínimo
}

int main() {
    ll n, m;
    cin >> n >> m;                     // n = tamanho do array, m = número de operações
    for (ll i = 0; i < n; i++) cin >> v[i]; // leitura do array
    build(1, 0, n - 1);                // constrói a árvore

    while (m--) {
        ll op;
        cin >> op;
        if (op == 1) { // atualização de posição
            ll i, valor;
            cin >> i >> valor;
            update(1, 0, n - 1, i, valor);
        } else {       // consulta do mínimo no intervalo
            ll left, right;
            cin >> left >> right;
            cout << query(1, 0, n - 1, left, right - 1) << "\n";
        }
    }
}
