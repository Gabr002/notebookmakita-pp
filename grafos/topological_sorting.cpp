#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEMA: Ordenação topológica com prioridade mínima
    Objetivo: Ordenar tarefas (ou projetos) de forma que cada tarefa venha após todas as suas dependências.
    Estratégia: Kahn's algorithm usando fila de prioridade para garantir ordem lexicográfica mínima.
*/

#define MAXN 100100

int n; // número de vértices
int m; // número de arestas
vector<int> grafo[MAXN]; // lista de adjacência
int grau[MAXN];          // grau de entrada de cada vértice

vector<int> lista_final; // resultado da ordenação topológica
priority_queue<int, vector<int>, greater<int>> pq; // fila de prioridade para garantir menor índice primeiro

int main()
{
    // leitura do número de vértices e arestas
    cin >> n >> m;

    // leitura das arestas e cálculo do grau de entrada
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        grau[y]++;        // incrementa grau de entrada do destino
        grafo[x].push_back(y); // adiciona aresta x -> y
    }

    // adiciona vértices com grau 0 na fila de prioridade
    for (int i = 1; i <= n; i++)
    {
        if (grau[i] == 0)
            pq.push(i);
    }

    // processa vértices em ordem de prioridade
    while (!pq.empty())
    {
        int atual = pq.top();
        pq.pop();

        lista_final.push_back(atual);

        // reduz grau de entrada dos vizinhos
        for (int v : grafo[atual])
        {
            grau[v]--;
            if (grau[v] == 0)
                pq.push(v);
        }
    }

    // se não foi possível processar todos os vértices, há ciclo
    if ((int)lista_final.size() < n)
    {
        cout << "Sandro fails." << endl;
    }
    else
    {
        // imprime ordenação topológica
        for (int i = 0; i < (int)lista_final.size(); i++)
        {
            cout << lista_final[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
