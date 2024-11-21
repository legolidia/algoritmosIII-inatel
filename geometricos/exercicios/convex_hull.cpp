#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};

// Função para calcular a distância quadrada entre dois pontos
int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y);
}

// Função para calcular a orientação de três pontos
// Retorna 0 se colinear, 1 se horário, 2 se anti-horário
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;             // Colinear
    return (val > 0) ? 1 : 2; // 1 = horário, 2 = anti-horário
}

// Função para ordenar os pontos em relação ao ponto p0
bool compare(Point p1, Point p2, Point p0)
{
    int o = orientation(p0, p1, p2);
    if (o == 0)
        return distSq(p0, p1) < distSq(p0, p2); // Se colineares, escolhe o mais próximo
    return (o == 2);                            // Prioriza anti-horário
}

// Função para acessar o segundo item da pilha
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p); // Coloca de volta o topo
    return res;
}

// Função para encontrar o casco convexo
void grahamScan(Point points[], int n)
{
    // Encontra o ponto mais baixo (com o menor y) e mais à esquerda
    int ymin = points[0].y, min = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].y < ymin || (points[i].y == ymin && points[i].x < points[min].x))
        {
            ymin = points[i].y;
            min = i;
        }
    }

    // Troca o ponto mais embaixo com o primeiro
    swap(points[0], points[min]);
    Point p0 = points[0];

    // Ordena os pontos com base no ângulo polar em relação ao ponto p0
    sort(points + 1, points + n, [p0](Point p1, Point p2)
         { return compare(p1, p2, p0); });

    // Cria uma pilha para armazenar o casco
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < n; i++)
    {
        while (S.size() > 1 && orientation(S.top(), nextToTop(S), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    // Imprime os pontos do casco
    stack<Point> result;
    while (!S.empty())
    {
        result.push(S.top());
        S.pop();
    }

    // Agora imprima os pontos no formato desejado
    while (!result.empty())
    {
        Point p = result.top();
        cout << p.x << " " << p.y << endl;
        result.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    Point points[n];
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    grahamScan(points, n);
    return 0;
}
