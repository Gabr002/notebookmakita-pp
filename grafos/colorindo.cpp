#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    Problema (contexto):
    - Dada uma matriz n x m, algumas células estão bloqueadas (1) e outras são livres (0).
    - Começando de uma célula inicial (x, y), queremos contar quantas células livres são acessíveis.
    - Movimentos permitidos: todas as 8 direções (horizontal, vertical e diagonais).
    - Solução: DFS (Depth-First Search) para visitar todas as células conectadas.
*/

int mat[250][250]; // matriz do problema
int q = 0;         // contador de células acessíveis

// função DFS que marca células visitadas e conta acessíveis
void dfs(int x, int y, int n, int m) {
    // condições de parada: fora da matriz ou célula não livre
    if (x < 0 || x >= n || y < 0 || y >= m || mat[x][y] != 0) {
        return;
    }

    mat[x][y] = 2; // marca como visitada
    q++;           // incrementa contador

    // percorre todas as 8 direções
    dfs(x - 1, y - 1, n, m);
    dfs(x - 1, y, n, m);
    dfs(x - 1, y + 1, n, m);
    dfs(x + 1, y - 1, n, m);
    dfs(x + 1, y, n, m);
    dfs(x + 1, y + 1, n, m);
    dfs(x, y - 1, n, m);
    dfs(x, y + 1, n, m);
}

int main() {
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;

    // inicializa a matriz com 0 (livre)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = 0;

    // marca as células bloqueadas
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;        // converte para índice 0-based
        mat[a][b] = 1;   // bloqueada
    }

    dfs(x - 1, y - 1, n, m); // inicia DFS na célula inicial
    cout << q << endl;       // imprime o número de células acessíveis

    return 0;
}
