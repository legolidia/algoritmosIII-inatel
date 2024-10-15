#include <iostream>
using namespace std;

struct Exemplo
{
    int x;
    int y;
};

int main()
{
    int a;
    int *p;

    // a = 5;

    // cout << a << endl;

    // p = &a; // p recebe endereço de a
    // *p = 7; //*p refere-se ao valor da variavel com endereço de memoria alocado em p (valor de a)

    // cout << a << endl;

    // int b[5];
    // cout << b << endl;
    // cout << b[2] << endl;

    // p = b;
    // p = b + 2;
    // *p = 7;

    // cout << b[2] << endl;
    // cout << *(b + 2) << endl;

    Exemplo e1;
    // cout << e1 << endl;

    cout << e1.x << endl;
    p = &e1.x;
    *p = 7;

    cout << e1.x << endl;

    // p = &e1;
    Exemplo *pEx;
    pEx = &e1;

    (*pEx).x = 7;

    cout << e1.x << endl;

    cout << &(e1.x) << endl;
    cout << &(e1.y) << endl;
    cout << &e1 << endl;

    return 0;
}