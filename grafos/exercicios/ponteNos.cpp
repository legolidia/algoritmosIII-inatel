#include <iostream>
#include <list>

using namespace std;

struct node
{
    int v;
};

void criaAresta(list<node> adj[], int u, int v)
{
    adj[u].push_back({v});
    adj[v].push_back({u});
}

void bfs(list<node> adj[], char state[], int vertices, int s)
{

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
}

void removeAresta(list<node> adj[], int x, int y)
{
    list<node>::iterator it;
    for (it = adj[x].begin(); it != adj[x].end(); it++)
    {
        if (it->v == y)
        {
            adj[x].erase(it);
            break;
        }
    }

    for (it = adj[y].begin(); it != adj[y].end(); it++)
    {
        if (it->v == x)
        {
            adj[y].erase(it);
            break;
        }
    }
}

int main()
{
    int n, m;
    int u, v;
    int x, y;

    cin >> n >> m;

    list<node> cidades[n];
    list<node>::iterator it;

    char state[n];
    char stateModificado[n];

    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        criaAresta(cidades, u - 1, v - 1);
    }

    cin >> x >> y;
    bfs(cidades, state, n, x - 1);
    removeAresta(cidades, x - 1, y - 1);

    bfs(cidades, stateModificado, n, x - 1);

    for (int i = 0; i < n; i++)
    {
        if (state[i] == 'p' && stateModificado[i] != 'p')
        {
            cout << i + 1 << " ";
        }
    }

    cout << endl;

    return 0;
}