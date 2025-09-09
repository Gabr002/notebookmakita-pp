#include <bits/stdc++.h>
using namespace std;

/*
   Problema (contexto):
   - Temos um array ORDENADO de tamanho n.
   - Recebemos k consultas, cada uma com um valor x.
   - Objetivo: encontrar a posição (índice + 1) do primeiro elemento 
     do array que seja >= x.
     Caso todos sejam menores que x, retornamos n+1 (fora do array).

   Solução:
   - Busca binária modificada (lower_bound):
     * l começa em -1 (antes do array).
     * r começa em n (depois do array).
     * Enquanto restar espaço, calculamos m = (l+r)/2:
         - Se a[m] >= x, movemos r para m (pois m pode ser resposta).
         - Caso contrário, movemos l para m (descartando valores menores).
   - Ao final, r será o menor índice tal que a[r] >= x.
   - Como queremos 1-based index, imprimimos r+1.
   - Se não existir (x maior que todos), r = n → saída = n+1.
*/

int main() {
    int n, k;
    cin >> n >> k; // n = tamanho do array, k = número de consultas
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; // leitura do array ordenado

    while (k--) {
        int x;
        cin >> x; // valor da consulta
        int l = -1, r = n; // limites fora do array

        // busca binária adaptada (lower_bound manual)
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (a[m] >= x) r = m; 
            else l = m;
        }

        cout << r + 1 << endl; // índice 1-based
    }
}
