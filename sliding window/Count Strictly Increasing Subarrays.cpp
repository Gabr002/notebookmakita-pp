#include <bits/stdc++.h>
using namespace std;

/*
   Problema (contexto):
   - Dado um array de inteiros, queremos contar quantos 
     subarrays estritamente crescentes existem nele.
   - Exemplo: arr = [1, 4, 5, 3]
       Subarrays crescentes = [1,4], [1,4,5], [4,5], [3]
       Resultado: 3 subarrays (sem contar unitários).

   Solução:
   - Percorremos o array e mantemos o tamanho da "sequência crescente atual".
   - Sempre que ela é quebrada (ou no final do array), aplicamos a fórmula:
       número de subarrays crescentes possíveis = len * (len - 1) / 2
   - Essa fórmula conta todos os subarrays possíveis dentro de um bloco crescente.
   - Complexidade: O(n).
*/

int countIncreasing(vector<int>& arr) {
    int n = arr.size();
    int count = 0; // total de subarrays crescentes
    int len = 1;   // tamanho da sequência crescente atual

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            // ainda estamos em uma sequência crescente
            len++;
        } else {
            // sequência terminou -> conta os subarrays desse bloco
            count += (len * (len - 1)) / 2;
            len = 1; // reinicia a contagem
        }
    }

    // soma os subarrays do último bloco crescente
    count += (len * (len - 1)) / 2;

    return count;
}

int main() {
    vector<int> arr = {1, 4, 5, 3, 7, 9};
    cout << countIncreasing(arr) << endl;
    return 0;
}
