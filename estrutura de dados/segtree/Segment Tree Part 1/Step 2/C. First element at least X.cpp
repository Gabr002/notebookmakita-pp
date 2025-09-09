#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
    Problema (contexto):
    - Temos um array de números e queremos:
        1. Atualizar o valor de uma posição.
        2. Encontrar a primeira posição (menor índice) com valor >= x.
    - Segment Tree armazena o valor máximo em cada intervalo:
        - Permite responder consultas de "primeiro >= x" em O(log N)
        - Permite atualizar elementos em O(log N)
*/

const int N = 1e5 + 10;
ll st[4 * N], v[N];

// constrói a segment tree com máximos
void build(int p, int l, int r) {
    if (l == r) {
        st[p] = v[l]; // nó folha recebe valor do array
        return;
    }
    int m = (l + r) / 2;
    build(2 * p, l, m);
    build(2 * p + 1, m + 1, r);
    st[p] = max(st[2 * p], st[2 * p + 1]); // nó recebe máximo dos filhos
}

// retorna o menor índice com valor >= x
int query(int p, int l, int r, ll x) {
    if (l == r) {
        return (st[p] >= x) ? l : -1; // se folha satisfaz, retorna índice, senão -1
    }
    int m = (l + r) / 2;
    if (st[2 * p] >= x) 
        return query(2 * p, l, m, x); // procura no filho esquerdo
    else 
        return query(2 * p + 1, m + 1, r, x); // procura no filho direito
}

// atualiza a posição x com novo valor v
void update(int p, int l, int r, ll x, ll valor) {
    if (x < l || x > r) return; // fora do intervalo
    if (l == r) { // nó folha
        st[p] = valor;
        return;
    }
    int m = (l + r) / 2;
    update(2 * p, l, m, x, valor);
    update(2 * p + 1, m + 1, r, x, valor);
    st[p] = max(st[2 * p], st[2 * p + 1]); // atualiza máximo do nó
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i]; // leitura do array

    build(1, 0, n - 1); // construção da segment tree

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) { 
            // atualização: posição i recebe valor
            ll i, valor;
            cin >> i >> valor;
            update(1, 0, n - 1, i, valor);
        } else { 
            // consulta: retorna menor índice com valor >= x
            ll x;
            cin >> x;
            cout << query(1, 0, n - 1, x) << "\n";
        }
    }
}
