#include <bits/stdc++.h>
using namespace std;

/*
    Problema (contexto):
    - Temos um array binário (0 ou 1) e queremos:
        1. Alternar valores na posição i (0 -> 1 ou 1 -> 0)
        2. Encontrar a posição do k-ésimo "1" no array.
    - Segment Tree armazena a soma dos valores no intervalo, permitindo:
        - Atualização de elementos (flip 0/1)
        - Consulta do k-ésimo "1" em O(log N)
*/

const int N = 1e5 + 10;
int st[4 * N], v[N];

// constrói a segment tree para somas no intervalo [l, r]
void build(int p, int l, int r) {
    if (l == r) {
        st[p] = v[l]; // nó folha recebe o valor do array
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);
    st[p] = st[2 * p] + st[2 * p + 1]; // soma dos filhos
}

// encontra a posição do k-ésimo "1" no intervalo [l, r]
int query(int p, int l, int r, int k) {
    if (l == r) return l; // nó folha: posição encontrada

    int m = (l + r) / 2;
    if (k < st[2 * p]) 
        return query(2 * p, l, m, k); // está na esquerda
    else 
        return query(2 * p + 1, m + 1, r, k - st[2 * p]); // está na direita, ajusta k
}

// atualiza a posição x para o valor v
void update(int p, int l, int r, int x, int v) {
    if (x < l || x > r) return;
    if (l == r) {
        st[p] = v;
        return;
    }
    int m = (l + r) / 2;
    update(2 * p, l, m, x, v);
    update(2 * p + 1, m + 1, r, x, v);
    st[p] = st[2 * p] + st[2 * p + 1]; // atualiza soma do nó
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> v[i]; // leitura do array binário

    build(1, 0, n - 1); // constroi segment tree

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i;
            cin >> i;
            // alterna valor: 0 -> 1, 1 -> 0
            int valor = (v[i] == 0) ? 1 : 0;
            v[i] = valor;
            update(1, 0, n - 1, i, valor);
        } else {
            int k;
            cin >> k;
            cout << query(1, 0, n - 1, k) << "\n"; // retorna posição do k-ésimo "1"
        }
    }
}
