#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6; // limite máximo para o crivo

/*
   Problema (contexto):
   - Dadas várias consultas [l, r], queremos saber
     quantos números primos existem nesse intervalo.
   - r pode chegar até 10^6.

   Solução:
   - Usamos o Crivo de Eratóstenes para pré-computar todos
     os primos até N = 10^6.
   - Construímos um prefixo (dp[i]) que armazena a quantidade
     de primos até i.
   - Assim, cada consulta [l, r] pode ser respondida em O(1) com:
         resposta = dp[r] - dp[l-1].
   - Complexidade:
       * Crivo: O(N log log N).
       * Pré-processamento do dp: O(N).
       * Cada consulta: O(1).
*/

// Crivo de Eratóstenes: retorna vetor booleano onde true = primo
vector<bool> crivo(int x) {
    vector<bool> ePrimo(x + 1, true);
    ePrimo[0] = ePrimo[1] = false;

    for (int i = 2; i * i <= x; i++) {
        if (ePrimo[i]) {
            for (int j = i * i; j <= x; j += i) {
                ePrimo[j] = false;
            }
        }
    }
    return ePrimo;
}

int main() {
    int t;
    cin >> t; // número de consultas

    // pré-processamento
    auto primos = crivo(N);
    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        if (primos[i]) dp[i] = dp[i - 1] + 1; // i é primo
        else dp[i] = dp[i - 1];              // copia valor anterior
    }

    // responde consultas
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << "\n";
    }
}
