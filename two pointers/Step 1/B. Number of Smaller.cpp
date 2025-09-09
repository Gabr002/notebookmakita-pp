#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEMA: Contagem de elementos menores
    Contexto: Dado dois vetores ordenados `a` e `b`, para cada elemento de `b` queremos saber quantos elementos em `a` são menores que ele.
    Estratégia: Percorrer ambos os vetores com dois ponteiros, evitando buscas repetidas, garantindo complexidade linear O(n + m).
*/

using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);

    // leitura do vetor a
    for (int i = 0; i < n; i++) cin >> a[i];
    // leitura do vetor b
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0, count = 0;
    vector<ll> c(m); // resultado: número de elementos de a menores que b[j]

    // percorrer ambos os vetores
    while (j < m) {
        while (i < n && a[i] < b[j]) {
            i++; 
            count++; // conta quantos elementos de a são menores que b[j]
        }
        c[j] = count;
        j++;
    }

    // imprime o resultado
    for (int x : c) cout << x << " ";
    cout << endl;

    return 0;
}
