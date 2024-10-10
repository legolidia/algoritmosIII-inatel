#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> estoque;
    list<int> venda;
    list<int>::iterator it;

    int n;
    int op, produto;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> produto;
            estoque.push_back(produto);
        }
        if (op == 2)
        {
            venda.push_front(*estoque.begin());
            estoque.pop_front();
        }
    }

    cout << "Estoque: ";
    for (it = estoque.begin(); it != estoque.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "\nVenda: ";
    for (it = venda.begin(); it != venda.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}