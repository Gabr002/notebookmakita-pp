/*
   Problema (contexto):

   - Dadas duas strings s1 e s2, queremos encontrar o comprimento da menor string
     que contenha ambas como substrings. Esse problema é conhecido como "superstring mínima".
   - Se uma string já contém a outra, o resultado é o tamanho da maior.
   - Caso contrário, tentamos todas as sobreposições possíveis entre s1 e s2 e
     entre s2 e s1, para minimizar o tamanho final da string combinada.

   Solução:
   1. Verificamos se uma das strings contém a outra. Se sim, retornamos o tamanho da maior.
   2. Inicializamos o tamanho mínimo como a soma dos tamanhos das duas strings.
   3. Para cada possível sobreposição (de 0 até o tamanho mínimo das strings):
       a) Tentamos sobrepor o sufixo de s1 com o prefixo de s2.
       b) Tentamos sobrepor o sufixo de s2 com o prefixo de s1.
       c) Verificamos se a string resultante contém ambas como substrings.
       d) Atualizamos o tamanho mínimo se necessário.
   4. Retornamos o tamanho mínimo encontrado.
*/
#include <bits/stdc++.h>
using namespace std;

// verifica se a string combinada contem as strings de entrada como substrings
bool contem_substr(string merged, string a, string b) {
    return merged.find(a) != string::npos && merged.find(b) != string::npos;
}

// retorna a "superstring" combinando as strings com sobreposição de tamanho k
string merge_sobreposicao(string a, string b, int k) {
    return a + b.substr(k);
}

// calcula o tamanho da menor superstring contendo s1 e s2
int solution(string s1, string s2) {
    if (s1.find(s2) != string::npos || s2.find(s1) != string::npos)
        return max(s1.size(), s2.size());

    int tam_min = s1.size() + s2.size();

    for (int k = 0; k <= min(s1.size(), s2.size()); k++) {
        if (s1.substr(s1.size() - k) == s2.substr(0, k)) {
            string merged = merge_sobreposicao(s1, s2, k);
            if (contem_substr(merged, s1, s2))
                tam_min = min(tam_min, (int)merged.size());
        }
    }

    for (int k = 0; k <= min(s1.size(), s2.size()); k++) {
        if (s2.substr(s2.size() - k) == s1.substr(0, k)) {
            string merged = merge_sobreposicao(s2, s1, k);
            if (contem_substr(merged, s2, s1))
                tam_min = min(tam_min, (int)merged.size());
        }
    }

    return tam_min;
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        string s;
        cin >> s;
        cout << s.size() << endl;
    } else {
        string s1, s2;
        cin >> s1 >> s2;
        cout << solution(s1, s2) << endl;
    }
}
