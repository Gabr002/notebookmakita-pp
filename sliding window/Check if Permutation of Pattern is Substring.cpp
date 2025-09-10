// Problema (contexto):
// Verificar se **alguma permutação** da string `pat` aparece como substring dentro da string `txt`.
// Exemplo: txt = "geeks", pat = "eke".  
// A permutação "eke" existe em "geeks" → resposta = true.

// Solução (usando Sliding Window):
// - Usamos um vetor de frequência de 26 posições (letras minúsculas).
// - Para cada janela de tamanho m (tamanho da pattern) na string `txt`:
//     - Incrementamos contagem das letras da janela em `txt`.
//     - Decrementamos contagem das letras da `pat`.
// - Se todas as frequências forem zero → a janela atual é uma permutação de `pat`.
// - Deslizamos a janela removendo um caractere do início e adicionando um novo no fim.
// - Verificamos a cada passo.

#include <iostream>
#include <vector>
using namespace std;

const int MAX_CHAR = 26;

// Função para verificar se todas as frequências são zero
bool check(vector<int> &freq) {
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] != 0)
            return false;
    }
    return true;
}

// Função principal que busca se alguma permutação de `pat` é substring de `txt`
bool search(string &txt, string &pat) {
    int n = txt.length();
    int m = pat.length();

    vector<int> freq(MAX_CHAR, 0);

    // Construímos a primeira janela de tamanho m
    for (int i = 0; i < m; i++) {
        freq[txt[i] - 'a'] += 1;
        freq[pat[i] - 'a'] -= 1;
    }

    // Checa a primeira janela
    if (check(freq))
        return true;

    // Move a janela pelo texto
    for (int i = m; i < n; i++) {
        // Adiciona novo caractere da direita
        freq[txt[i] - 'a'] += 1;

        // Remove caractere da esquerda
        freq[txt[i - m] - 'a'] -= 1;

        // Checa a nova janela
        if (check(freq))
            return true;
    }

    return false;
}

int main() {
    string txt = "geeks";
    string pat = "eke";

    if (search(txt, pat))
        cout << "true";
    else
        cout << "false";

    return 0;
}
