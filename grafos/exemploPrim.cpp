#include <iostream>
#include <list>

#define MAX_VERTICES 10
#define INT_MAX 999999

using namespace std;

struct Aresta
{
	int origem, destino, peso;
};

void prim(list<Aresta> adj[], int n, int start)
{
	bool intree[n];
	int distance[n], parent[n];
	for (int i = 0; i < n; i++)
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
		list<Aresta>::iterator it;
		for (it = adj[v].begin(); it != adj[v].end(); it++)
		{
			Aresta aresta = *it;
			if (distance[aresta.destino] > aresta.peso && intree[aresta.destino] == false)
			{
				distance[aresta.destino] = aresta.peso;
				parent[aresta.destino] = v;
			}
		}
		v = 0;
		int dist = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			if (intree[i] == false && dist > distance[i])
			{
				dist = distance[i];
				v = i;
			}
		}
	}
	int total = 0;
	cout << "Arvore Geradora Minima:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (parent[i] != -1)
			cout << parent[i] << " " << i << endl;
		total += distance[i];
	}
	cout << "Custo: " << total << endl;
}

int main()
{
	int vertices, arestas, origem, destino, peso;
	cin >> vertices >> arestas;

	// int grafo[vertices][vertices];
	list<Aresta> grafo[vertices];
	list<Aresta>::iterator it;

	// for(int i=0;i<vertices;i++)
	// 	for(int j=0;j<vertices;j++)
	// 		grafo[i][j] = INT_MAX;

	cin >> origem >> destino >> peso;
	while (origem != -1 && destino != -1 && peso != -1)
	{
		cin >> origem >> destino >> peso;
		// grafo[origem][destino] = peso;
		// grafo[destino][origem] = peso;
		grafo[origem].push_back({destino, peso});
		grafo[destino].push_back({origem, peso});
	}

	prim(grafo, vertices, slkk);

	return 0;
}