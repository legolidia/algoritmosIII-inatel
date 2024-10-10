#include <iostream>
#include <list>

using namespace std;

#define INT_MAX 100000

struct node
{
    int v;
    int peso;
};

void criaAresta(list<node> adj[], int u, int v, int w, int orientado)
{
    adj[u].push_back({v, w});
    if (!orientado)
    {
        adj[v].push_back({u, w});
    }
}

void ShortestsPath_Dijkstra(list<node> adj[], int vertices, int start, int end)
{
    bool intree[vertices];
    int distance[vertices];
    int parent[vertices];

    list<node>::iterator it;

    for (int u = 0; u < vertices; u++)
    {
        intree[u] = 0;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }

    distance[start] = 0;

    int v = start;
    int destino;
    int weight;

    while (!intree[v])
    {
        intree[v] = 1;
        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            destino = it->v;
            weight = it->peso;
            if (distance[destino] > distance[v] + weight)
            {
                distance[destino] = distance[v] + weight;
                parent[destino] = v;
            }
        }
        v = 0;
        int dist = INT_MAX;
        for (int u = 0; u < vertices; u++)
        {
            if (!intree[u] && dist > distance[u])
            {
                dist = distance[u];
                v = u;
            }
        }
    }

    list<int> menorCaminho;
    list<int>::iterator it2;

    int verticeAtual = end;
    int tamanho = 0;
    while (verticeAtual != -1)
    {
        menorCaminho.push_front(verticeAtual);
        verticeAtual = parent[verticeAtual];
        tamanho++;
    }

    if (distance[end] == INT_MAX)
    {
        cout << "IMPOSSIVEL" << endl;
        return;
    }

    cout << tamanho << endl;
}

int main()
{
    int n, m;
    int u, v;
    int s, d;

    cin >> n >> m;
    list<node> adj[n];

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        criaAresta(adj, u - 1, v - 1, 0, 1);
    }

    cin >> s >> d;

    ShortestsPath_Dijkstra(adj, n, s - 1, d - 1);
}