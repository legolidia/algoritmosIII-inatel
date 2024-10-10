#include <iostream>
#include <list>

using namespace std;

void cria_aresta(list<int> adj[], int u, int v)
{
    adj[u].push_back({v});
    adj[v].push_back({u});
}

int contar(list<int> lista)
{
    list<int>::iterator it;
    int contador = 0;

    for (it = lista.begin(); it != lista.end(); it++)
    {
        contador++;
    }

    return contador;
}

int main()
{
    int n, m;
    int a, b;

    cin >> n >> m;

    list<int> cidades[n];
    list<int>::iterator it;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        cria_aresta(cidades, a - 1, b - 1);
    }

    for (int i = 0; i < n; i++)
    {
        cidades[i].sort();
        cout << contar(cidades[i]) << " ";
        for (it = cidades[i].begin(); it != cidades[i].end(); it++)
        {
            cout << *it + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
