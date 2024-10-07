#include <iostream>
#include <list>

using namespace std;

// LIFO: last in, first out

int main()
{
    list<int> pilha; // ponteiro para a pilha

    // inserir na pilha
    pilha.push_front(2);
    pilha.push_front(1);
    pilha.push_front(3);

    // pilha vazia
    pilha.empty();

    // mostrar e remover todos os elementos da pilha
    while (!pilha.empty())
    {
        // elemento na frente da pilha
        cout << *pilha.begin() << endl;

        // remover os dados da pilha
        pilha.pop_front();
    }

    return 0;
}