#include<iostream>
#include<list>

using namespace std;

bool bfs(bool grafo[][5], int vertices, int origem){
	bool verticesVisitados[vertices];
	list<int> filaVisitacao;
	
	
	for(int i=0;i<vertices;i++)
		verticesVisitados[i] = false;
	
	filaVisitacao.push_back(origem);
	verticesVisitados[origem] = true;
	
	while(!filaVisitacao.empty()){
		int verticeAtual = filaVisitacao.front();

		cout << verticeAtual << endl;
		
			for(int i=0;i<vertices;i++){
				if(grafo[verticeAtual][i])
					if(!verticesVisitados[i]){
						filaVisitacao.push_back(i);	
						verticesVisitados[i] = true;
					}				
			}
		
		filaVisitacao.pop_front();
	}
	
	for(int i=0; i<vertices;i++)
		if(!verticesVisitados[i])
			return false;
		
    return true;
}

int main(){
	int vertices, arestas;
	int origem, destino;
	
	cin >> vertices >> arestas;
	
	//grafo nao ponderado e n�o direcionado
	bool grafo[5][5];
	
	for(int i=0;i<vertices;i++)
		for(int j=0; j<vertices;j++)
			grafo[i][j] = false;
	
	for(int i=0; i<arestas; i++){
		cin >> origem >> destino;
		grafo[origem][destino] = true;
		grafo[destino][origem] = true;
	}
	
	cout << endl;
	
	for(int i=0;i<vertices;i++){
		for(int j=0; j<vertices;j++)
			cout << grafo[i][j] << " ";
		cout << endl;
	}
	
	cout << endl;
	
	if(bfs(grafo, 5, 0))
		cout << "\nconexo" << endl;
	else
		cout << "\ndesconexo" << endl;
}