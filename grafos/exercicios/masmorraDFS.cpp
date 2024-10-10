#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct no
{
    int v;
};

void criaAresta(list<no> adj[], int u, int v)
{
    adj[u].push_back({v});
    adj[v].push_back({u}); // Grafo não direcionado
}

bool dfsVisit(list<no> adj[], int u, vector<bool> &visited, int start, int count, int nVertices)
{
    visited[u] = true;
    if (count == nVertices)
    {
        // Verifica se há um caminho de volta para o início
        for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
        {
            if (it->v == start)
                return true;
        }
        visited[u] = false;
        return false;
    }
    for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
    {
        if (!visited[it->v])
        {
            if (dfsVisit(adj, it->v, visited, start, count + 1, nVertices))
                return true;
        }
    }
    visited[u] = false;
    return false;
}

bool dfs(list<no> adj[], int nVertices)
{
    vector<bool> visited(nVertices, false);
    for (int u = 0; u < nVertices; u++)
    {
        fill(visited.begin(), visited.end(), false); // Reset visited for each start vertex
        if (dfsVisit(adj, u, visited, u, 1, nVertices))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int nVertices, nArestas;
    cin >> nVertices >> nArestas;

    if (nVertices <= 0 || nArestas < 0)
    {
        cerr << "Número inválido de vértices ou arestas." << endl;
        return 1;
    }

    list<no> *adj = new list<no>[nVertices];

    for (int i = 0; i < nArestas; ++i)
    {
        int u, v, peso;
        cin >> u >> v >> peso; // Ignorar o peso
        if (u < 0 || u >= nVertices || v < 0 || v >= nVertices)
        {
            cerr << "Aresta inválida: " << u << " " << v << endl;
            delete[] adj;
            return 1;
        }
        criaAresta(adj, u, v);
    }

    if (dfs(adj, nVertices))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    delete[] adj;
    return 0;
}