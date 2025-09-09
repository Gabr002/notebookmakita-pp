#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEMA: Merge de dois arrays ordenados
    Contexto: Dado dois vetores já ordenados, combinar em um único vetor ordenado.
    Estratégia: Utilizar dois ponteiros (i, j) para percorrer os vetores simultaneamente.
*/

using ll = long long;
const long long MAX = 1e9+10;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);

    // leitura dos vetores já ordenados
    for (ll i = 0; i < n; i++) cin >> a[i];
    for (ll i = 0; i < m; i++) cin >> b[i];

    ll i = 0, j = 0;
    vector<ll> c(n + m); // vetor final

    // merge dos vetores
    while (i < a.size() || j < b.size()) {
        if (j == b.size() || (i < a.size() && a[i] < b[j])) {
            c[i + j] = a[i];
            i++;
        } else {
            c[i + j] = b[j];
            j++;
        }
    }

    // impressão do vetor combinado
    for (int x : c) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
