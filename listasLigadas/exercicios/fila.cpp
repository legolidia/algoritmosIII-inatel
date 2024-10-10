#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> fila;
    int valor;

    for (int i = 0; i < 4; i++)
    {
        cin >> valor;
        fila.push_back(valor);
    }

    while (!fila.empty())
    {
        cout << *fila.begin() << " ";
        fila.pop_front();
    }

    cout << endl;
}