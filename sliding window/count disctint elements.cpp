// Problema (contexto):
// Dado um array de inteiros `arr` e um inteiro `k`, queremos calcular
// quantos elementos distintos existem em cada subarray (janela) de tamanho `k`.
// Exemplo: arr = [1, 2, 1, 3, 4, 2, 3], k = 4
// Subarrays de tamanho 4 → [1,2,1,3], [2,1,3,4], [1,3,4,2], [3,4,2,3]
// Quantidade de distintos → [3, 4, 4, 3].

// Solução (usando Hash Map + Sliding Window):
// - Usamos um `unordered_map` para guardar a frequência dos elementos na janela.
// - Para cada nova posição, adicionamos o próximo elemento e removemos o mais antigo.
// - O número de distintos é dado pelo tamanho do mapa (chaves com freq > 0).

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> countDistinct(vector<int> &arr, int k) {
    int n = arr.size();  
    vector<int> res;
    unordered_map<int, int> freq;  // guarda frequência dos elementos
  
    // Frequência da primeira janela
    for(int i = 0; i < k; i++)
        freq[arr[i]]++;

    // Número de distintos da primeira janela
    res.push_back(freq.size());
  
    // Desliza a janela
    for(int i = k; i < n; i++) {
        // Adiciona o novo elemento
        freq[arr[i]]++;

        // Remove o elemento que saiu da janela
        freq[arr[i - k]]--;

        // Se a frequência dele zerar, apaga do mapa
        if(freq[arr[i - k]] == 0)
            freq.erase(arr[i - k]);

        // Quantidade de distintos na janela atual
        res.push_back(freq.size());
    }
      
    return res;
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;

    vector<int> res = countDistinct(arr, k);
    for(int ele: res)
        cout << ele << " ";
    return 0;
}
