#include <bits/stdc++.h>
using namespace std;

/*
    Problema (contexto):
    - Dada uma matriz com cores (valores inteiros), queremos encontrar o menor "bloco" de células conectadas da mesma cor.
    - Conexão considerada apenas nas 4 direções (cima, baixo, esquerda, direita).
    - Estratégia:
        1. Percorrer toda a matriz.
        2. Sempre que encontrar uma célula não visitada, usar DFS para marcar todas as células conectadas da mesma cor.
        3. Contar o tamanho de cada bloco e armazenar.
        4. Ao final, retornar o menor tamanho encontrado.
    - Complexidade: O(H*L), H = altura, L = largura da matriz.
*/

const int MAX = 250;
int mat[MAX][MAX]; // matriz de cores
vector<int> blocos; // armazena os tamanhos de cada bloco
int c = 0;          // contador do bloco atual

// DFS para explorar todas as células conectadas da mesma cor
void dfs(int cor, int i, int j, int h, int l) {
    if (i < 0 || i >= h || j < 0 || j >= l || mat[i][j] != cor)
        return;

    mat[i][j] = -1; // marca como visitado
    c++;             // incrementa tamanho do bloco

    dfs(cor, i - 1, j, h, l); // cima
    dfs(cor, i + 1, j, h, l); // baixo
    dfs(cor, i, j - 1, h, l); // esquerda
    dfs(cor, i, j + 1, h, l); // direita
}

int main() {
    int h, l;
    cin >> h >> l;

    // lê a matriz de cores
    for (int i = 0; i < h; i++)
        for (int j = 0; j < l; j++)
            cin >> mat[i][j];

    // percorre todas as células
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            if (mat[i][j] != -1) { // se ainda não foi visitada
                c = 0;             // reinicia contador
                dfs(mat[i][j], i, j, h, l); // explora bloco
                blocos.push_back(c);        // salva tamanho do bloco
            }
        }
    }

    // ordena blocos e imprime o menor
    sort(blocos.begin(), blocos.end());
    cout << *blocos.begin() << endl;

    return 0;
}
