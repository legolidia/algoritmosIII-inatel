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
}

void dfs(list<no> adj[], int nVertices)
{
    char color[nVertices];
    int parent[nVertices];
    for (int u = 0; u < nVertices; u++)
    {
        color[u] = 'w';
        parent[u] = -1;
    }
    int time = 0;

    for (int u = 0; u < nVertices; u++)
    {
        if (color[u] == 'w')
        {
            dfsVisit(adj, u, nVertices, color, parent, time);
        }
    }
}

void dfsVisit(list<no> adj[], int u, int v, char color[], int parent[], int time)
{
    color[v] = 'g';
    time++;
    int d[v];
    d[u] = time;
    list<no>::iterator it;
    for (it = adj[u].begin(); it != adj[u].end(); it++)
    {
        if (color[it->v] == 'w')
        {
            parent[it->v] = u;
            dfsVisit(adj, it->v, v, color, parent, time);
        }
    }
    color[u] = 'b';
    int f[v];
    f[u] = time + 1;
}

void ordenacao_topologica(int f[], int nVertices)
{
}

int main()
{
    return 0;
}