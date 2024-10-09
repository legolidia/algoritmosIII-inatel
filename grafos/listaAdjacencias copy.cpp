#include <iostream>
#include <list>

using namespace std;

// nó
struct node
{
    int v; // vertice
    int weight;
};

int main()
{
    list<node> adj[10]; // lista de adjacencias
    int vertices;       // numero de vertices
    int u, v;           // origem e destino da aresta
    int w;              // peso da aresta
    node aux;           // variavel para inserir as arestas na lista de adjacencias

    cin >> vertices;

    for (int i = 0; i < vertices; i++)
    {
        cin >> u >> v >> w;
        aux.v = v;
        aux.weight = w;
        adj[u].push_back(aux);
    }

    list<node>::iterator it;
    for (int i = 0; i < vertices; i++)
    {
        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << i << " " << it->v << "(" << it->weight << ")" << endl;
        }
    }

    return 0;
}