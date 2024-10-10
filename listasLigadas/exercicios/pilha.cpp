#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> pilha;
    list<int>::iterator it;

    int valor;

    for (int i = 0; i < 4; i++)
    {
        cin >> valor;
        pilha.push_front(valor);
    }

    while (!pilha.empty())
    {
        cout << *pilha.begin() << " ";
        pilha.pop_front();
    }

    cout << endl;
}