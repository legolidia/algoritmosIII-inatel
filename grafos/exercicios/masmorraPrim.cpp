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

        v = -1;
        dist = INT_MAX;
        for (int u = 0; u < vertices; u++)
        {
            if (!intree[u] && dist > distance[u])
            {
                dist = distance[u];
                v = u; // Atualiza v para o próximo vértice a ser processado
            }
        }

        // Se v não foi atualizado, sai do loop
        if (v == -1)
            break;
    }

    for (int i = 0; i < vertices; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << " " << i << " " << distance[i] << endl;
        }
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
        criaAresta(adj, i, j, k);
    }

    prim(adj, s, 0);
}