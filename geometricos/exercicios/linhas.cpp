#include <iostream>
using namespace std;

typedef struct
{
    int x;
    int y;
} Ponto;

// Calcula a orientação de três pontos
// Retorna:
// 0 -> colinear
// 1 -> sentido horário
// 2 -> sentido anti-horário
int orientacao(Ponto a, Ponto b, Ponto c)
{
    int val = (b.y - a.y) * (c.x - b.x) -
              (b.x - a.x) * (c.y - b.y);

    if (val == 0)
        return 0;             // colinear
    return (val > 0) ? 1 : 2; // horário ou anti-horário
}

// Determina se o ponto p está na linha formada por q1 e q2
bool pontoNaLinha(Ponto q1, Ponto q2, Ponto p)
{
    return (p.x <= max(q1.x, q2.x) && p.x >= min(q1.x, q2.x) &&
            p.y <= max(q1.y, q2.y) && p.y >= min(q1.y, q2.y));
}

// Verifica se duas linhas se cruzam
bool linhasSeCruzam(Ponto p1, Ponto q1, Ponto p2, Ponto q2)
{
    // Encontrar as orientações necessárias
    int o1 = orientacao(p1, q1, p2);
    int o2 = orientacao(p1, q1, q2);
    int o3 = orientacao(p2, q2, p1);
    int o4 = orientacao(p2, q2, q1);

    // Caso geral: As linhas se cruzam se as orientações são diferentes
    if (o1 != o2 && o3 != o4)
        return true;

    // Casos especiais
    // p2 está na linha (p1, q1)
    if (o1 == 0 && pontoNaLinha(p1, q1, p2))
        return true;

    // q2 está na linha (p1, q1)
    if (o2 == 0 && pontoNaLinha(p1, q1, q2))
        return true;

    // p1 está na linha (p2, q2)
    if (o3 == 0 && pontoNaLinha(p2, q2, p1))
        return true;

    // q1 está na linha (p2, q2)
    if (o4 == 0 && pontoNaLinha(p2, q2, q1))
        return true;

    // Não se cruzam
    return false;
}

int main()
{
    Ponto p1, q1, p2, q2;
    // Entrada das coordenadas das duas linhas
    cin >> p1.x >> p1.y >> q1.x >> q1.y >> p2.x >> p2.y >> q2.x >> q2.y;

    if (linhasSeCruzam(p1, q1, p2, q2))
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;

    return 0;
}
