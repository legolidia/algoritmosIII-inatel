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

void uniao(list<int> lista1, list<int> lista2)
{
    list<int> uniao;
    list<int>::iterator it;

    for (it = lista1.begin(); it != lista1.end(); it++)
    {
        uniao.push_back(*it);
    }

    for (it = lista2.begin(); it != lista2.end(); it++)
    {
        if (!encontrar(uniao, *it))
        {
            uniao.push_back(*it);
        }
    }

    uniao.sort();

    for (it = uniao.begin(); it != uniao.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}

int main()
{
    list<int> lista1;
    list<int> lista2;

    int entrada;

    // lista 1
    cin >> entrada;
    while (entrada != 0)
    {
        lista1.push_back(entrada);
        cin >> entrada;
    }

    // lista 2
    cin >> entrada;
    while (entrada != 0)
    {
        lista2.push_back(entrada);
        cin >> entrada;
    }

    uniao(lista1, lista2);
}