#include <bits/stdc++.h>
using namespace std;

/*
   Problema (contexto):
   - Temos um array de inteiros ORDENADO de tamanho n.
   - Recebemos k consultas. Em cada consulta é dado um valor x.
   - Objetivo: encontrar a posição (índice + 1) do maior elemento 
     <= x dentro do array. 
     Caso não exista, retorna 0. Caso todos sejam <= x, retorna n.

   Solução:
   - Usamos uma variação de busca binária para encontrar o "maior índice válido".
   - l começa em -1 (posição impossível à esquerda).
   - r começa em n (posição impossível à direita).
   - Enquanto restar espaço entre l e r, calculamos o meio:
        * Se a[m] <= x, movemos l para m (m é candidato).
        * Senão, movemos r para m (descartando a parte direita).
   - Ao final, l guarda o maior índice em que a[l] <= x.
   - Como o enunciado pede posições iniciando em 1, imprimimos l+1.
*/

int main() {
    int n, k;
    cin >> n >> k; // n = tamanho do array, k = número de consultas
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i]; // leitura do array ordenado

    while (k--) {
        int x;
        cin >> x; // valor a ser buscado
        int l = -1, r = n; // limites iniciais (fora do array)

        // busca binária adaptada
        while (l < r - 1) {
            int m = (l + r) / 2; 
            if (a[m] <= x) l = m; // m pode ser resposta
            else r = m;          // descarta a parte direita
        }

        // resultado: índice + 1 (se nada <= x, retorna 0)
        cout << l + 1 << endl;
    }
}
