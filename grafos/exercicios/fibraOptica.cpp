#include <iostream>
#include <list>

using namespace std;

#define INT_MAX 10000

// arvore geradora minima: subconjunto minimo de arestas que mantém o
// grafo conexo e que a soma dos pesos é minima

struct node
{
    int v;
    int peso;
};

void criaAresta(list<node> adj[], int u, int v, int p)
{
    adj[u].push_back({v, p});
    adj[v].push_back({u, p});
}

void prim(list<node> adj[], int vertices, int s)
{
    list<node>::iterator it;
    bool intree[vertices];
    int distance[vertices];
    int parent[vertices];
    int v;
    int weight;
    int destino;
    int dist;

    for (int u = 0; u < vertices; u++)
    {
        intree[u] = 0;
        distance[u] = INT_MAX;
        parent[u] = -1;
    }

    distance[s] = 0;
    v = s;
    while (!intree[v])
    {
        intree[v] = true;
        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            destino = it->v;
            weight = it->peso;
            if (distance[destino] > weight && !intree[destino])
            {
                distance[destino] = weight;
                parent[destino] = v;
            }
        }

        v = 0;
        dist = INT_MAX;
        for (int u = 0; u < vertices; u++)
        {
            if (!intree[u] && dist > distance[u])
            {
                dist = distance[u];
                v = u;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < vertices; i++)
    {
        total += distance[i];
    }
    cout << total << endl;
}

int main()
{
    int vertices, arestas;
    int u, v, w;

    cin >> vertices >> arestas;

    list<node> adj[vertices];

    for (int i = 0; i < arestas; i++)
    {
        cin >> u >> v >> w;
        criaAresta(adj, u - 1, v - 1, w);
    }

    prim(adj, vertices, 0);
}