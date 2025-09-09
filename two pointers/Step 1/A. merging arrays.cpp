#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEMA: Merge de dois arrays ordenados usando sentinelas
    Contexto: Dois vetores ordenados a[] e b[] devem ser combinados em um vetor c[] ordenado.
    Estratégia: Adicionar um valor "sentinela" (MAX) no final de cada vetor para evitar checagens de limites a cada iteração.
*/

using ll = long long;
const long long MAX = 1e9+10;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n + 1), b(m + 1);

    // leitura do vetor a e adiciona sentinela
    for (ll i = 0; i < n; i++) cin >> a[i];
    a[n] = MAX; // sentinela

    // leitura do vetor b e adiciona sentinela
    for (ll i = 0; i < m; i++) cin >> b[i];
    b[m] = MAX; // sentinela

    ll i = 0, j = 0, k = 0;
    vector<ll> c(n + m); // vetor final

    // merge usando sentinelas
    while (i < n || j < m) {
        if (a[i] < b[j]) {
            c[k] = a[i];
            k++; i++;
        } else {
            c[k] = b[j];
            k++; j++;
        }
    }

    // impressão do vetor combinado
    for (int x : c) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
