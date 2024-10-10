#include <iostream>
#include <list>

using namespace std;

struct node
{
    int v;
    int weight;
};

void criaAresta(list<node> adj[], int u, int v, int w, bool orientado)
{
    node aux;
    aux.v = v;
    aux.weight = w;
    adj[u].push_back(aux);
    if (!orientado)
    {
        aux.v = u;
        adj[v].push_back(aux);
    }
}

void bfs(list<node> adj[], int vertices, int s)
{
    char state[vertices];
    int p[vertices];
    list<int> Q;
    int u;
    list<node>::iterator it;

    for (int i = 0; i < vertices; i++)
    {
        if (u != s)
        {
            state[i] = 'u';
            p[i] = -1;
        }
    }

    state[s] = 'd';
    p[s] = -1;
    Q.push_back(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop_front();
        for (it = adj[u].begin(); it != adj[u].end(); it++)
        {
            int v = it->v;
            cout << u << "->" << v << endl;
            if (state[it->v] == 'u')
            {
                state[it->v] = 'd';
                p[v] = u;
                Q.push_back(v);
            }
        }
        state[u] = 'p';
    }
}

int main()
{
    list<node> adj[10]; // lista de adjacencias
    int vertices;       // numero de vertices
    int u, v;           // origem e destino da aresta
    int w;              // peso da aresta

    cin >> vertices;

    for (int i = 0; i < vertices - 1; i++)
    {
        cin >> u >> v >> w;
        criaAresta(adj, u, v, w, 1);
    }

    list<node>::iterator it;
    for (int i = 0; i < vertices; i++)
    {
        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << i << " " << it->v << " " << it->weight << " " << endl;
        }
    }

    cout << endl;

    bfs(adj, vertices, 0);

    return 0;
}
