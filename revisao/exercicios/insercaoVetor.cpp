#include <iostream>

using namespace std;

int main()
{
    int n;
    int aux;

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
        cout << *(p + i) << " ";
    }

    cout << endl;

    return 0;
}