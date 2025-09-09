#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
   Problema (contexto):
   - Máximo subarray: dado um array, queremos o máximo de soma de qualquer subarray.
   - Além disso, suportamos atualizações de valores e consultas após cada atualização.
   - Segment Tree armazena, para cada nó, quatro valores:
       st[p][0] = prefix máximo
       st[p][1] = segmento máximo (resposta do nó)
       st[p][2] = sufix máximo
       st[p][3] = soma total do intervalo
   - Permite combinar dois nós rapidamente para obter o máximo subarray do pai.
*/

const int N = 100010;
const ll INF = 1e9 + 10;

ll st[4 * N][4], v[N];

// constroi a segment tree no intervalo [l, r] com raiz p
void build(int p, int l, int r) {
    if (l == r) {
        // nó folha: valores do próprio elemento
        if (v[l] < 0) {
            st[p][0] = 0;    // prefix
            st[p][1] = 0;    // segmento máximo
            st[p][2] = 0;    // sufix
            st[p][3] = v[l]; // soma total
        } else {
            st[p][0] = st[p][1] = st[p][2] = st[p][3] = v[l];
        }
        return;
    }

    int m = (l + r) / 2;
    build(2 * p, l, m);       // filho esquerdo
    build(2 * p + 1, m + 1, r); // filho direito

    // combina filhos para formar o pai
    ll prefix1 = st[2 * p][0], seg1 = st[2 * p][1], sufix1 = st[2 * p][2], sum1 = st[2 * p][3];
    ll prefix2 = st[2 * p + 1][0], seg2 = st[2 * p + 1][1], sufix2 = st[2 * p + 1][2], sum2 = st[2 * p + 1][3];

    st[p][0] = max(prefix1, sum1 + prefix2);
    st[p][1] = max({seg1, seg2, sufix1 + prefix2});
    st[p][2] = max(sufix2, sum2 + sufix1);
    st[p][3] = sum1 + sum2;
}

// consulta o máximo subarray no intervalo [i, j]
ll query(int p, int l, int r, int i, int j) {
    if (r < i || j < l) return -INF;       // fora do intervalo
    if (i <= l && r <= j) return st[p][1]; // nó totalmente dentro
    int m = (l + r) / 2;
    ll x = query(2 * p, l, m, i, j);
    ll y = query(2 * p + 1, m + 1, r, i, j);
    return max(x, y);
}

// atualiza a posição x para valor val
void update(int p, int l, int r, ll x, ll val) {
    if (x < l || x > r) return;
    if (l == r && l == x) {
        if (val < 0) {
            st[p][0] = 0; st[p][1] = 0; st[p][2] = 0; st[p][3] = val;
        } else {
            st[p][0] = st[p][1] = st[p][2] = st[p][3] = val;
        }
        return;
    }

    int m = (l + r) / 2;
    update(2 * p, l, m, x, val);
    update(2 * p + 1, m + 1, r, x, val);

    // combina filhos novamente
    ll prefix1 = st[2 * p][0], seg1 = st[2 * p][1], sufix1 = st[2 * p][2], sum1 = st[2 * p][3];
    ll prefix2 = st[2 * p + 1][0], seg2 = st[2 * p + 1][1], sufix2 = st[2 * p + 1][2], sum2 = st[2 * p + 1][3];

    st[p][0] = max(prefix1, sum1 + prefix2);
    st[p][1] = max({seg1, seg2, sufix1 + prefix2});
    st[p][2] = max(sufix2, sum2 + sufix1);
    st[p][3] = sum1 + sum2;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i]; // leitura do array

    build(1, 0, n - 1);                    // constroi árvore
    cout << query(1, 0, n - 1, 0, n - 1) << "\n"; // máximo subarray inicial

    while (m--) {
        ll i, val;
        cin >> i >> val;
        update(1, 0, n - 1, i, val);      // atualiza posição
        cout << query(1, 0, n - 1, 0, n - 1) << "\n"; // imprime máximo subarray atualizado
    }
}
