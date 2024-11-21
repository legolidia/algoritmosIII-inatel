#include <iostream>
#include <cmath>
using namespace std;

typedef struct
{
    int x, y;
} Ponto;

// Calcula a distância euclidiana ao quadrado (evitando raiz quadrada para melhor desempenho)
int distanciaQuadrada(Ponto a, Ponto b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{
    int n;
    cin >> n;

    Ponto pontos[100]; // Máximo de 100 pontos, conforme a restrição
    for (int i = 0; i < n; i++)
    {
        cin >> pontos[i].x >> pontos[i].y;
    }

    Ponto usuario;
    cin >> usuario.x >> usuario.y;

    Ponto maisProximo = pontos[0];
    int menorDistancia = distanciaQuadrada(pontos[0], usuario);

    for (int i = 1; i < n; i++)
    {
        int dist = distanciaQuadrada(pontos[i], usuario);

        // Atualiza o ponto mais próximo com base nos critérios
        if (dist < menorDistancia ||
            (dist == menorDistancia && (pontos[i].x < maisProximo.x ||
                                        (pontos[i].x == maisProximo.x && pontos[i].y < maisProximo.y))))
        {
            maisProximo = pontos[i];
            menorDistancia = dist;
        }
    }

    cout << maisProximo.x << " " << maisProximo.y << endl;

    return 0;
}
