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

bool bfs(list<node> adj[], int vertices, int s)
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
            if (state[it->v] == 'u')
            {
                state[it->v] = 'd';
                p[v] = u;
                Q.push_back(v);
            }
        }
        state[u] = 'p';
    }

    for (int i = 0; i < vertices; i++)
    {
        if (state[i] != 'p')
            return false;
    }
    return true;
}

int main()
{
    list<node> adj[10]; // lista de adjacencias
    int vertices;       // numero de vertices
    int u, v;           // origem e destino da aresta
    int s;

    cin >> vertices >> s;

    cin >> u >> v;
    while (u != -1 && v != -1)
    {
        criaAresta(adj, u, v, 0, 0);
        cin >> u >> v;
    }

    (bfs(adj, vertices, s)) ? cout << "Conexo" << endl : cout << "Nao conexo" << endl;

    return 0;
}
