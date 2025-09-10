#include <bits/stdc++.h>
using namespace std;

/*
   Problema (contexto):
   - Dada uma string S composta apenas pelos caracteres '0', '1' e '2'.
   - Queremos encontrar o tamanho da menor substring que contenha pelo
     menos um de cada caractere: '0', '1' e '2'.
   - Se não existir tal substring, retornamos -1.

   Solução:
   - Usamos a técnica de "Sliding Window" (janela deslizante).
   - Mantemos dois ponteiros i (início) e k (fim) que delimitam a janela atual.
   - Um array freq[3] armazena a frequência de '0', '1' e '2' dentro da janela.
   - Sempre que temos pelo menos um de cada caractere (freq[x] >= 1),
     tentamos reduzir a janela pelo lado esquerdo para achar a mínima.
   - Atualizamos o tamanho mínimo de substring encontrada durante o processo.
*/

int smallestSubstring(string &S) {
    int n = S.length();
    int i = 0, k = 0;         // ponteiros da janela
    int cnt = 0;              // conta quantos dos três caracteres estão na janela
    int min_len = INT_MAX;    // resultado: menor comprimento encontrado
    int freq[3] = {0};        // frequência de '0', '1', '2' na janela

    while (k < n) {
        // adiciona o caractere atual à janela
        freq[S[k]-'0']++;
        if (freq[S[k]-'0'] == 1) cnt++; // se for a primeira ocorrência, incrementa cnt

        // se a janela contém pelo menos um de cada caractere
        if (cnt == 3) {
            // tenta diminuir a janela pelo lado esquerdo enquanto possível
            while (freq[S[i]-'0'] > 1) {
                freq[S[i]-'0']--;
                i++;
            }

            // atualiza o tamanho mínimo
            min_len = min(min_len, k - i + 1);

            // move o início da janela adiante
            freq[S[i]-'0']--;
            i++;
            cnt--;
        }
        k++; // expande a janela pelo lado direito
    }

    // se nenhuma substring válida foi encontrada, retorna -1
    return (min_len == INT_MAX) ? -1 : min_len;
}

int main() {
    string S = "01212";
    cout << smallestSubstring(S) << endl; // saída esperada: 3
    return 0;
}
