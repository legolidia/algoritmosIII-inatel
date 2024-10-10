#include <iostream>
#include <list>

using namespace std;

int soma(list<int> lista)
{
    list<int>::iterator it;
    int soma = 0;

    for (it = lista.begin(); it != lista.end(); it++)
    {
        soma += *it;
    }

    return soma;
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

    cout << soma(lista) << endl;
}