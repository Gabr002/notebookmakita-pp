#include <bits/stdc++.h>
using namespace std;

/*
    Problema (contexto):
    - Detectar o menor ciclo em um grafo dirigido representando dependências entre arquivos.
    - Cada nó é um arquivo, cada aresta indica que um arquivo importa outro.
    - Estratégia:
        1. Floyd–Warshall para calcular todas as menores distâncias entre pares de nós.
        2. Armazena também o próximo nó para reconstruir o caminho do ciclo.
        3. Verifica ciclos de tamanho 1 (self-loop) e ciclos formados por dois ou mais nós.
    - Complexidade: O(N^3) devido ao Floyd–Warshall, N = número de arquivos.
*/

const int MAXN = 510;
const long long INF = 4e18;
typedef long long ll;

int n, x, y;
long long w[MAXN][MAXN], d[MAXN][MAXN]; // w: pesos originais, d: distâncias mínimas
int prox[MAXN][MAXN]; // prox[u][v] = próximo nó no caminho de u a v
bool self_loop[MAXN]; // marca se o nó tem loop em si mesmo

map<string,int> file_to_index; // mapeia nomes de arquivos para índices
vector<string> index_to_file;  // mapeia índices de volta para nomes de arquivos

// Reconstrói o caminho mínimo entre u e v usando prox
vector<int> get_path(int u, int v) {
    if (prox[u][v] == -1)
        return {};
    vector<int> path;
    path.push_back(u);
    while (u != v) {
        u = prox[u][v];
        path.push_back(u);
    }
    return path;
}

// Encontra o menor ciclo no grafo
void menor_ciclo() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = w[i][j];

    // Floyd–Warshall: calcula distâncias mínimas e caminho intermediário
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++) {
            if (d[i][k] >= INF) continue;
            for (int j = 0; j < n; j++) {
                if (d[k][j] >= INF) continue;
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    prox[i][j] = prox[i][k];
                }
            }
        }

    ll length = INF;
    x = y = -1;

    // Verifica todos os ciclos possíveis
    for (int i = 0; i < n; i++) {
        if (self_loop[i] && 1 < length) { 
            length = 1;
            x = y = i;
        }
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (d[i][j] < INF && d[j][i] < INF) {
                ll ciclo = d[i][j] + d[j][i];
                if (ciclo < length) {
                    length = ciclo;
                    x = i;
                    y = j;
                }
            }
        }
    }

    if (length >= INF) { // sem ciclos
        cout << "SHIP IT\n";
        return;
    }

    // Reconstrói o ciclo encontrado
    if (x == y) { // self-loop
        cout << index_to_file[x] << "\n";
    } else {
        vector<int> p1 = get_path(x, y);
        vector<int> p2 = get_path(y, x);

        for (int v : p1)
            cout << index_to_file[v] << " ";

        for (int k = 1; k < (int)p2.size()-1; k++) // evita duplicar y
            cout << index_to_file[p2[k]] << " ";

        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    index_to_file.resize(n);

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        file_to_index[name] = i;
        index_to_file[i] = name;
    }

    // Inicializa matrizes
    for (int i = 0; i < n; i++) {
        self_loop[i] = false;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                w[i][j] = 0;
                prox[i][j] = i;
            } else {
                w[i][j] = INF;
                prox[i][j] = -1;
            }
        }
    }

    // Ler dependências de cada arquivo
    for (int i = 0; i < n; i++) {
        string file;
        int k;
        cin >> file >> k;
        int u = file_to_index[file];
        cin.ignore();

        for (int j = 0; j < k; j++) {
            string line;
            getline(cin, line); // linha "import dep1, dep2,..."
            line = line.substr(7); // remove "import "
            stringstream ss(line);
            string dep;
            while (getline(ss, dep, ',')) {
                dep.erase(dep.begin(), find_if(dep.begin(), dep.end(), [](char c){ return !isspace(c); }));
                dep.erase(find_if(dep.rbegin(), dep.rend(), [](char c){ return !isspace(c); }).base(), dep.end());
                int v = file_to_index[dep];
                if(u == v) self_loop[u] = true; // self-loop
                w[u][v] = 1;
                prox[u][v] = v;
            }
        }
    }

    menor_ciclo(); // calcula e imprime o menor ciclo
    return 0;
}
