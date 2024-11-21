#include <iostream>
#include <cmath>
using namespace std;

typedef struct
{
    int x, y;
} Ponto;

double calcularArea(Ponto a, Ponto b, Ponto c)
{
    // Fórmula da área do triângulo
    return fabs((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) / 2.0);
}

int main()
{
    Ponto p1, p2, p3;

    // Lê os pontos
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    // Calcula a área
    double area = calcularArea(p1, p2, p3);

    // Imprime a área com uma casa decimal
    cout << fixed;
    cout.precision(1);
    cout << area << endl;

    return 0;
}
