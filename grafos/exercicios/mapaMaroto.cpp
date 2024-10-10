#include <iostream>
#include <list>

using namespace std;

struct no
{
    int v;
    int peso;
};

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado)
{
    adj[u].push_back({v, p});
    if (!orientado)
    {
        adj[v].push_back({u, p});
    }
}

int main()
{
    int vertices, orientado;
    int origem, destino, peso;

    cin >> vertices >> orientado;

    list<no> adj[vertices];
    list<no>::iterator it;

    cin >> origem >> destino >> peso;
    while (origem != -1 && destino != -1 && peso != -1)
    {
        cria_aresta(adj, origem, destino, peso, orientado);
        cin >> origem >> destino >> peso;
    }

    for (int i = 0; i < vertices; i++)
    {
        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << i << " " << it->v << " " << it->peso << endl;
        }
    }

    return 0;
}
