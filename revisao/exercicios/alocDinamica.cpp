#include <iostream>
#include <iomanip>

using namespace std;

struct nota
{
    int nota1;
    int nota2;
    int nota3;
    int nota4;
    float media;
};

int main()
{
    nota *n;
    n = new nota;

    cin >> n->nota1;
    cin >> n->nota2;
    cin >> n->nota3;
    cin >> n->nota4;

    n->media = (n->nota1 + n->nota2 + n->nota3 + n->nota4) / 4.0;

    cout << fixed << setprecision(2);
    cout << n->media << endl;

    delete n;

    return 0;
}