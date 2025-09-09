#include <bits/stdc++.h>
using namespace std;

/*
   Problema (contexto):
   - Dado um array de n inteiros.
   - Devemos responder k consultas, cada uma pedindo:
       "Quantos números estão dentro do intervalo [l, r]?"
   - O array pode estar desordenado, então precisamos ordená-lo.

   Solução:
   - Ordenamos o array (O(n log n)).
   - Para cada consulta:
       * lower_bound(l): primeiro elemento >= l.
       * upper_bound(r): primeiro elemento > r.
       * A diferença (itright - itleft) fornece a quantidade de
         elementos dentro do intervalo [l, r].
   - Cada consulta é O(log n), eficiente para k grande.
*/

int main() {
    int n, k;
    cin >> n; // tamanho do array
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end()); // ordena para usar busca binária

    cin >> k; // número de consultas
    while (k--) {
        int l, r;
        cin >> l >> r; // intervalo de consulta

        auto itleft = lower_bound(a.begin(), a.end(), l);  // >= l
        auto itright = upper_bound(a.begin(), a.end(), r); // > r

        cout << itright - itleft << " "; // quantidade no intervalo
    }
}
