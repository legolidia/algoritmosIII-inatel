#include <iostream>
#include <list>
using namespace std;

struct no
{
  int v;    // vertice adjacente
  int peso; // peso da aresta
};

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado)
{
  no no;
  no.v = v;
  no.peso = p;
  adj[u].push_back(no);
  if(!orientado){
    no.v = u;
    adj[v].push_back(no);
  }
}

int main()
{
  int vertices;
  bool orientado;

  cin >> vertices >> orientado;

  list<no> adj[vertices];

  int origem, destino, peso;

  cin >> origem >> destino >> peso;
  while (origem != -1 && destino != -1 && peso != -1)
  {
    cria_aresta(adj, origem, destino, peso, orientado);
    cin >> origem >> destino >> peso;
  }

  for (int i = 0; i < vertices; i++) {
        for (no n : adj[i]) {
            cout << i << " " << n.v << " " << n.peso << endl;
        }
    }

}

