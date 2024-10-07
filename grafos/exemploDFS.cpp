#include <iostream>
using namespace std;

#define MAX_VERTICES 100

void dfs(bool grafo[][MAX_VERTICES], int origem, int vertices, bool visitados[]){
    visitados[origem] = true;

    for(int adj=0; adj<vertices;adj++){
        if(grafo[origem][adj] && !visitados[adj]){
            dfs(grafo, adj, vertices, visitados);
        } 
    }
}

int main()
{
    int vertices, origem, destino;
    cin >> vertices;

    bool grafo[vertices][vertices];
    for (int i = 0; i < vertices; i++){
        for(int j=0; j < vertices; j++){
            grafo[i][i] = false;
        }
    }

    while (cin >> origem >> destino && origem != -1 && destino != -1) {
        grafo[origem][destino] = true;
        grafo[destino][origem] = true; //não direcionado - existe conexao entre ambos
    }

    bool visitados[vertices];
    for(int i = 0; i < vertices; i++){
            visitados[i] = false;
    }

    dfs(grafo,0,vertices, visitados);

    return 0;
}