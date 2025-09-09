#include <bits/stdc++.h>
using namespace std;

/*
   Problema (contexto):
   - Temos um array de inteiros ORDENADO.
   - Recebemos várias consultas (queries), cada uma perguntando 
     se um número X está presente no array.
   - Para cada consulta devemos imprimir "YES" se o número existir 
     e "NO" caso contrário.

   Solução:
   - Usamos busca binária (Binary Search), que tem complexidade O(log n).
   - Para cada uma das k consultas, aplicamos a busca no vetor.
*/

int main() {
    int n, k;
    cin >> n >> k; // n = tamanho do array, k = número de consultas

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // leitura do array (já ordenado)
    }

    while (k--) { 
        int x;
        cin >> x; // valor a ser buscado
        int l = 0, r = n - 1;
        bool found = false; // flag para saber se achamos o elemento

        // busca binária clássica
        while (l <= r) {
            int m = (l + r) / 2; // índice do meio
            if (a[m] == x) {     // achamos o elemento
                found = true;
                break;
            } else if (a[m] < x) { 
                l = m + 1; // busca na metade direita
            } else {
                r = m - 1; // busca na metade esquerda
            }
        }

        // imprime resultado da consulta
        if (found) cout << "YES\n";
        else cout << "NO\n";
    }
}
