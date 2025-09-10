/*
   Problema (contexto):

   - Queremos calcular o número de maneiras de colocar 2 cavalos em um tabuleiro
     de tamanho k × k de forma que eles **não se ataquem**.
   - Para cada tamanho de tabuleiro de 1 até n, devemos imprimir o resultado.

   Lógica da solução:

   1. O número total de maneiras de escolher 2 posições distintas no tabuleiro é:
         total = C(k^2, 2) = (k^2 * (k^2 - 1)) / 2
   2. O número de maneiras em que os cavalos **se atacam**:
         ataque = 4 * (k - 1) * (k - 2)
      - Isso vem da quantidade de retângulos 2×3 e 3×2 possíveis no tabuleiro.
   3. Portanto:
         resposta = total - ataque
   4. Imprimimos essa resposta para cada k de 1 até n.
*/
#include <bits/stdc++.h>  
using namespace std; 

// Função que calcula o número de maneiras para tabuleiro k×k
long posicion(int k) {
    long total = (1L * k * k) * (1L * k * k - 1) / 2; // todas as combinações
    long ataque = 4L * (k - 1) * (k - 2);             // casos em que os cavalos se atacam
    return total - ataque;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << posicion(i) << endl;
    }
    return 0;
}
