#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEMA: Contar subarrays com soma igual a S
    Contexto: Dado um vetor `a` de tamanho n, queremos contar quantos subarrays possuem soma exatamente igual a s.
    Estratégia: Usar prefix sums e um hashmap para contar quantas vezes cada prefix sum já apareceu.
    Observação: Se prefix_sum[j] - prefix_sum[i] = s, então o subarray a[i+1..j] tem soma s.
    Complexidade: O(n) usando unordered_map.
*/

using ll = long long;

int main() {
    int n;
    ll s;
    cin >> n >> s;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    unordered_map<ll, ll> freq;    
    freq[0] = 1; // prefix sum zero já ocorre uma vez

    ll prefix = 0;  // soma prefixa acumulada
    ll total = 0;   // total de subarrays com soma s

    for (int i = 0; i < n; ++i) {
        prefix += a[i];
        ll falta = prefix - s; // buscamos quantos prefixos anteriores permitem subarray com soma s
        
        if (freq.find(falta) != freq.end()) {
            total += freq[falta]; // incrementa total com quantidade de prefixos que somam 'falta'
        }
        freq[prefix] += 1; // atualiza contagem do prefix sum atual
    }

    cout << total << "\n";
    return 0;
}
