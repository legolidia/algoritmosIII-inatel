#include <iostream>
#include <list>
#include <string>
using namespace std;

#define INT_MAX 99999

struct Upgrade // nó
{
    int orig;
    int dest;
    int custo;
};

struct Habilidade
{
    string nome;
    int codigo;
    float poder;
    list<Upgrade> upgrades;
};

void prim(Habilidade adj[], int vertices, int start)
{
    bool intree[vertices];
    int distance[vertices], parent[vertices];
    for (int i = 0; i < vertices; i++)
    {
        intree[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }
    distance[start] = 0;
    int v = start;
    while (intree[v] == false)
    {
        intree[v] = true;
        list<Upgrade>::iterator p;
        for (p = adj[v].upgrades.begin(); p != adj[v].upgrades.end(); p++)
        {
            int dest = p->dest;
            int weigth = p->custo;
            if (distance[dest] > weigth && intree[dest] == false)
            {
                distance[dest] = weigth;
                parent[dest] = v;
            }
        }
        v = 0;
        int dist = INT_MAX;
        for (int i = 0; i < vertices; i++)
        {
            if (intree[i] == false && dist > distance[i])
            {
                dist = distance[i];
                v = i;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < vertices; i++)
    {
        total += distance[i];
    }
    cout << total << endl;
}

int main()
{
    int h; // num Habilidades
    cin >> h;

    Habilidade habilidades[h];
    char nome[50];
    int poder;

    for (int i = 0; i < h; i++)
    {

        cin >> habilidades[i].nome;
        cin >> habilidades[i].poder;
        habilidades[i].codigo = i;
    }

    int u; // num upgrades
    int origem, destino, custo;

    cin >> u;

    for (int i = 0; i < u; i++)
    {

        cin >> origem >> destino >> custo;
        habilidades[origem].upgrades.push_back({origem, destino, custo});
    }

    prim(habilidades, h, 0);

    return 0;
}
/*

Land 0
Dash 1
Thief 3
Hunter 3
Assassin 4
BeastMaster 5
Berserker 7
WildMagic 2
Vengeance 4
Life 5
12
0 1 1
1 2 2
1 3 2
3 4 3
3 5 3
3 6 4
0 7 2
7 8 3
7 9 3
1 7 3
8 6 5
2 4 5

23
---------

Poles está desenvolvendo uma árvore de habilidades para o seu jogo de RPG. Ele quer que os personagens possam escolher, partindo de uma habilidade principal, algumas ramificações possíveis.
Para cada upgrade de habilidade, o personagem deve gastar alguns pontos de experiência e pode adquirir alguma pontuação de poder.
<imagem>
Ele quer saber, dada um determinada árvore de habilidadades, qual é o custo mínimo de experiência para todas as habilidades.

Entrada
A entrada começa com um número inteiro indicando a quantidade H de habilidades. As H linhas seguintes contêm o nome (palavra) e o poder (número real) de cada habilidade (cada habilidade tem um código automático de 0 a H de acordo com a entrada de dados).
Em seguida é informado um valor inteiro indicando a quantidade U de upgrades possíveis. As U linhas seguintes contêm três inteiros indicando o código da habilidade origem, o código da habilidade destino e o custo de cada upgrade.

Saída
A saída é um número inteiro indicando o custo mínimo para desbloquear todas as habilidades.





*/