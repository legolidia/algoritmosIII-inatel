#include <iostream>
#include <list>

using namespace std;

bool encontrar(list<int> lista, int x)
{
    list<int>::iterator it;
    for (it = lista.begin(); it != lista.end(); it++)
    {
        if (*it == x)
        {
            return 1;
            break;
        }
    }

    return 0;
}

int main()
{
    list<int> lista;
    int entrada;
    int n;

    cin >> entrada;

    while (entrada != 0)
    {
        lista.push_back(entrada);
        cin >> entrada;
    }

    cin >> n;
    encontrar(lista, n) ? (cout << "Encontrado" << endl) : (cout << "Nao encontrado" << endl);
}