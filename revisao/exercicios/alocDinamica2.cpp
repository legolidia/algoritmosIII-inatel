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
    int num;
    nota *n;
    float media = 0;

    n = new nota[10];

    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cin >> (n + i)->nota1;
        cin >> (n + i)->nota2;
        cin >> (n + i)->nota3;
        cin >> (n + i)->nota4;

        (n + i)->media = ((n + i)->nota1 + (n + i)->nota2 + (n + i)->nota3 + (n + i)->nota4) / 4.0;

        media += (n + i)->media;
    }

    media = (media) / num;

    cout << fixed << setprecision(2);
    cout << media << endl;

    delete[] n;
}