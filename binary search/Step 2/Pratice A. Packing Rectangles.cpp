#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
   Problema (contexto):
   - Dados dois inteiros a e b, e um valor n.
   - Queremos encontrar o menor número x tal que:
         floor(x / a) * floor(x / b) >= n
   - Isso pode representar, por exemplo, "quantos pares cabem" 
     se dividirmos x em blocos de tamanhos a e b.

   Solução:
   - Aplicamos busca binária no valor de x.
   - Intervalo de busca: [0, max(a, b) * n].
     (esse limite garante que a resposta sempre estará contida).
   - Função auxiliar cabe(x, a, b, n):
       * Verifica se floor(x / a) * floor(x / b) >= n.
       * Para evitar overflow em multiplicações grandes (~10^18),
         fazemos cast para __int128_t antes de multiplicar.
   - No final, r guardará o menor x que satisfaz a condição.
*/

/*em casos raros mesmo usando ll pode dar overflow em operações matematicas
para evitar isso uso (__int128_t) para aumentar o range de 64 bits para 128 antes da multiplicação
e assim evitar o overflow no pior caso que fica 10^18 bem no limite do long long int
*/

bool cabe(ll x, ll a, ll b, ll n) {
    // usa __int128_t para evitar overflow de 64 bits
    return (__int128_t)(x / a) * (x / b) >= n;
}

int main() {
    ll n, a, b;
    cin >> a >> b >> n; // entrada dos valores

    ll l = 0, r = max(a, b) * n; // intervalo inicial

    // busca binária pelo menor x válido
    while (r > l + 1) {
        ll m = (r + l) / 2;
        if (cabe(m, a, b, n)) r = m;
        else l = m;
    }

    cout << r; // menor x que satisfaz a condição
}
