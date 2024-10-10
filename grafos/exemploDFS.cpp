#include <iostream>
#include <list>
using namespace std;

struct no
{
    int v;
    int peso;
};

void criaAresta(list<no> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // Não direcionado
}

void dfsVisit(list<no> adj[], int u, char color[], int parent[], int &time, int d[], int f[])
{
    color[u] = 'g'; // Visite o vértice
    time++;
    d[u] = time; // Marca o tempo de descoberta

    for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
    {
        if (color[it->v] == 'w')
        {
            parent[it->v] = u;
            dfsVisit(adj, it->v, color, parent, time, d, f);
        }
    }

    color[u] = 'b'; // Finalize o vértice
    time++;
    f[u] = time; // Marca o tempo de finalização
}

void dfs(list<no> adj[], int nVertices)
{
    char color[nVertices];
    int parent[nVertices];
    int d[nVertices]; // Tempo de descoberta
    int f[nVertices]; // Tempo de finalização
    int time = 0;

    for (int u = 0; u < nVertices; u++)
    {
        color[u] = 'w'; // Inicializa todos os vértices como não visitados
        parent[u] = -1; // Inicializa o pai como -1
    }

    for (int u = 0; u < nVertices; u++)
    {
        if (color[u] == 'w')
        {
            dfsVisit(adj, u, color, parent, time, d, f);
        }
    }
}

int main()
{
    int nVertices, u, v, w;
    cout << "Digite o número de vértices: ";
    cin >> nVertices;

    // Cria uma lista de adjacências
    list<no> adj[nVertices];

    cout << "Digite as arestas (u, v, peso). Use -1 para terminar:\n";
    while (cin >> u >> v && u != -1 && v != -1)
    {
        cout << "Digite o peso da aresta (" << u << ", " << v << "): ";
        cin >> w;
        criaAresta(adj, u, v, w);
    }

    // Executa DFS
    dfs(adj, nVertices);

    return 0;
}
