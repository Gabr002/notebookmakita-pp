#include <bits/stdc++.h>
using namespace std;

/*
   Problema (contexto):
   - Temos n caixas numeradas de 1 até n (cada caixa tem quantidade
     de pregos igual ao seu índice).
   - Queremos saber o menor número de caixas (pegando as MAIORES caixas)
     necessário para atingir pelo menos q pregos.
   - Se não for possível atingir q, imprimir "IMPOSSIVEL".

   Solução:
   - A soma das x maiores caixas é uma progressão aritmética:
       n + (n-1) + ... + (n-x+1).
     Fórmula: soma = (primeiro + último) * número_de_termos / 2
             = (n + (n-x+1)) * x / 2
   - Definimos a função mid_caixas_satisfazem(x, q) que retorna
     true se usar x maiores caixas for suficiente para q pregos.
   - Como a função é monótona (se x caixas funcionam, qualquer y > x
     também funciona), aplicamos busca binária em x ∈ [1, n].
   - O menor x que satisfaz a condição é a resposta.
   - Se nem com todas as caixas for possível, retornamos "IMPOSSIVEL".
*/

// verifica se 'num_caixas' maiores caixas fornecem pelo menos 'num_pregos'
bool mid_caixas_satisfazem(long long num_caixas, long long num_pregos, long long n) {
    // soma = (n + (n - num_caixas + 1)) * num_caixas / 2
    long long soma = (n + n - num_caixas + 1) * num_caixas / 2;
    return (soma >= num_pregos);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k; 
    cin >> k; // número de casos de teste
    while (k--) {
        long long n, q;
        cin >> n >> q; // n caixas, q pregos necessários

        int l = 1, r = (int) n; // intervalo de busca

        // busca binária pelo menor número de caixas que funciona
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid_caixas_satisfazem(mid, q, n)) r = mid; // tenta menos caixas
            else l = mid + 1; // precisa de mais caixas
        }

        // checa se realmente funciona com l caixas
        if (mid_caixas_satisfazem(l, q, n)) cout << l << "\n";
        else cout << "IMPOSSIVEL\n";
    }

    return 0;
}
