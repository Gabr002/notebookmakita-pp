#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
   Problema (contexto):
   - Temos um array de tamanho n.
   - Precisamos processar m operações de dois tipos:
       1) Atualizar o valor em uma posição.
       2) Consultar o intervalo [l, r) e retornar:
           - o menor elemento do intervalo
           - quantas vezes ele aparece
   - Usamos Segment Tree para responder cada operação em O(log n).

   Estrutura:
   - st[p]: menor valor no intervalo do nó p
   - st_qtd[p]: quantidade de vezes que esse mínimo aparece
   - build(): constrói a árvore
   - query(): retorna {mínimo, quantidade} em intervalo
   - update(): atualiza valor em uma posição
*/

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

ll st[4 * N], v[N], st_qtd[4 * N];

// constrói a árvore no intervalo [l, r] com raiz p
void build(int p, int l, int r) {
    if (l == r) {
        st[p] = v[l];       // nó folha
        st_qtd[p] = 1;      // aparece uma vez
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);

    st[p] = min(st[2 * p], st[2 * p + 1]); // mínimo entre filhos

    // atualiza quantidade de vezes que o mínimo aparece
    if (st[2 * p] == st[2 * p + 1]) {
        if (st[p] == st[2 * p])
            st_qtd[p] = st_qtd[2 * p] + st_qtd[2 * p + 1];
    }
    else if (st[2 * p] == st[p]) st_qtd[p] = st_qtd[2 * p];
    else if (st[2 * p + 1] == st[p]) st_qtd[p] = st_qtd[2 * p + 1];
}

// consulta intervalo [i, j], retorna {mínimo, quantidade}
pair<int,int> query(int p, int l, int r, int i, int j) {
    if (r < i || j < l) return {INF, 0};          // fora do intervalo
    if (i <= l && r <= j) return {st[p], st_qtd[p]}; // totalmente dentro
    int m = (l + r) / 2;
    auto x = query(2 * p, l, m, i, j);
    auto y = query(2 * p + 1, m + 1, r, i, j);

    if (x.first == y.first) return {x.first, x.second + y.second}; // mesmos mínimos
    return min(x, y); // retorna o mínimo
}

// atualiza posição x para valor val
void update(int p, int l, int r, int x, int val) {
    if (x < l || x > r) return;          // fora do intervalo
    if (l == r && l == x) {              // nó folha
        st[p] = val;
        st_qtd[p] = 1;
        return;
    }
    int m = (l + r) / 2;
    update(2 * p, l, m, x, val);
    update(2 * p + 1, m + 1, r, x, val);

    st[p] = min(st[2 * p], st[2 * p + 1]); // atualiza mínimo
    if (st[2 * p] == st[2 * p + 1]) {
        if (st[p] == st[2 * p]) st_qtd[p] = st_qtd[2 * p] + st_qtd[2 * p + 1];
    }
    else if (st[2 * p] == st[p]) st_qtd[p] = st_qtd[2 * p];
    else if (st[2 * p + 1] == st[p]) st_qtd[p] = st_qtd[2 * p + 1];
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i]; // leitura do array
    build(1, 0, n - 1);                       // constrói árvore

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) { // atualização
            ll i, valor;
            cin >> i >> valor;
            update(1, 0, n - 1, i, valor);
        } else {       // consulta
            int left, right;
            cin >> left >> right;
            auto ans = query(1, 0, n - 1, left, right - 1);
            cout << ans.first << " " << ans.second << "\n"; // mínimo e qtd
        }
    }
}
