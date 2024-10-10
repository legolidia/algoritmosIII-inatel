#include <iostream>
#include <list>

using namespace std;

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
    list<int> lista;
    int entrada;

    cin >> entrada;

    while (entrada != 0)
    {
        lista.push_back(entrada);
        cin >> entrada;
    }

    cout << contar(lista) << endl;
}