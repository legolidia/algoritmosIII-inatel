#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
    int x, y;
} Ponto;

// Verifica se o ponto está na linha (inclusive nas extremidades)
bool pontoNaLinha(Ponto a, Ponto b, Ponto p)
{
    return (p.x <= max(a.x, b.x) && p.x >= min(a.x, b.x) &&
            p.y <= max(a.y, b.y) && p.y >= min(a.y, b.y));
}

// Calcula a orientação de três pontos
int orientacao(Ponto a, Ponto b, Ponto c)
{
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0)
        return 0;             // colinear
    return (val > 0) ? 1 : 2; // horário ou anti-horário
}

// Verifica se duas linhas se cruzam
bool linhasSeCruzam(Ponto p1, Ponto q1, Ponto p2, Ponto q2)
{
    int o1 = orientacao(p1, q1, p2);
    int o2 = orientacao(p1, q1, q2);
    int o3 = orientacao(p2, q2, p1);
    int o4 = orientacao(p2, q2, q1);

    // Caso geral
    if (o1 != o2 && o3 != o4)
        return true;

    // Casos especiais
    if (o1 == 0 && pontoNaLinha(p1, q1, p2))
        return true;
    if (o2 == 0 && pontoNaLinha(p1, q1, q2))
        return true;
    if (o3 == 0 && pontoNaLinha(p2, q2, p1))
        return true;
    if (o4 == 0 && pontoNaLinha(p2, q2, q1))
        return true;

    return false;
}

// Verifica se o ponto está dentro do polígono
bool pontoDentroPoligono(vector<Ponto> &poligono, Ponto p)
{
    int n = poligono.size();
    if (n < 3)
        return false; // Um polígono precisa de pelo menos 3 vértices

    // Criar um ponto muito longe para o "raio"
    Ponto extremo = {1001, p.y};

    int cont = 0; // Contador de interseções
    for (int i = 0; i < n; i++)
    {
        Ponto atual = poligono[i];
        Ponto prox = poligono[(i + 1) % n];

        // Verificar se o segmento (atual, prox) cruza o raio
        if (linhasSeCruzam(atual, prox, p, extremo))
        {
            // Se o ponto está colinear com o segmento, verificar se está no segmento
            if (orientacao(atual, prox, p) == 0)
                return pontoNaLinha(atual, prox, p);

            cont++;
        }
    }

    // O ponto está dentro se o número de interseções for ímpar
    return (cont % 2 == 1);
}

int main()
{
    int n;
    cin >> n;

    vector<Ponto> poligono(n);
    for (int i = 0; i < n; i++)
    {
        cin >> poligono[i].x >> poligono[i].y;
    }

    Ponto p;
    cin >> p.x >> p.y;

    if (pontoDentroPoligono(poligono, p))
        cout << "DENTRO" << endl;
    else
        cout << "!(DENTRO)" << endl;

    return 0;
}
