#include <iostream>
#include <list>

using namespace std;

// FIFO: first in, first out

int main()
{
    list<int> fila; // ponteiro para a fila

    // inserir na fila
    fila.push_back(2);
    fila.push_back(1);
    fila.push_back(3);

    // fila vazia
    fila.empty();

    // mostrar e remover todos os elementos da fila
    while (!fila.empty())
    {
        // elemento na frente da fila | primeiro nó da lista
        cout << *fila.begin() << endl;

        // remover os dados da fila
        fila.pop_front();
    }

    return 0;
}