#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    int aux;
    int maior = -10000;

    cin >> n;

    int *p, *begin;
    int v[n];

    p = v;
    begin = v;

    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        *p = aux;
        p = p + 1;
    }

    p = begin;

    for (int i = 0; i < n; i++)
    {
        if (*(p + i) > maior)
        {
            maior = *(p + i);
        }
    }

    cout << maior << endl;

    return 0;
}