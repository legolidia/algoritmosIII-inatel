#include <iostream>
#include <queue>
#include <list>
using namespace std;

struct Aresta
{
    int origem, destino, peso;
};

int prim(list<Aresta> grafo[], int vertices, int origem){
    priority_queue<Aresta> filaVisitacao;

    list<Aresta>::iterator it;
    bool visitado[vertices];

    for (int i = 0; i < vertices; i++)
    {
        visitado[i] = false;
    }

    

    while(!filaVisitacao.empty()){
        Aresta atual = filaVisitacao.top();
visitado[origem] = true;

    for (it = grafo[origem].begin(); it != grafo[origem].end(); it++){
        Aresta aux = *it;
        if (!visitado[aux->destino]){
            filaVisitacao.push(aux);
        }
    }
    }
}

int main(){
    int vertices, arestas, origem, destino, peso;

    list<Aresta> grafo[vertices];
    list<Aresta>::iterator it;

    for (int i = 0; i < arestas; i++)
    {
        cin >> origem >> destino >> peso;
        grafo[origem].push_back({origem, destino, peso});
        grafo[destino].push_back({destino, origem, peso});
    }

    for (int i = 0; i < vertices; i++)
    {
        cout << i << ": ";
        for (it = grafo[i].begin(); it != grafo[i].end(); it++)
        {
            cout << it->destino << "(" << it->peso << ")" << endl;
        }
    }

    cout << "custo minimo: " << prim(grafo, vertices, 0) << endl;
}