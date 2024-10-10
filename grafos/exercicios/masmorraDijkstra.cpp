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

void ShortestPath_Dijkstra(list<node> adj[], int vertices, int start, int end)
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
        v = -1;
        int dist = INT_MAX;
        for (int u = 0; u < vertices; u++)
        {
            if (!intree[u] && dist > distance[u])
            {
                dist = distance[u];
                v = u;
            }
        }
        if (v == -1)
            break;
    }

    for (int i = 1; i < vertices; i++)
    {
        cout << distance[i] << endl;
    }
}

int main()
{
    int s, c;
    int i, j, k;

    cin >> s >> c;
    list<node> adj[s];

    for (int x = 0; x < c; x++)
    {
        cin >> i >> j >> k;
        criaAresta(adj, i, j, k, 0);
    }

    ShortestPath_Dijkstra(adj, s, 0, s - 1);
}