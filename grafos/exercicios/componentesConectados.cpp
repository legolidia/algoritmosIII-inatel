#include<iostream>
#include<list>

using namespace std;

bool bfs(bool grafo[][10], int vertices, int origem){
	bool verticesVisitados[vertices];
	list<int> filaVisitacao;
	
	
	for(int i=0;i<vertices;i++)
		verticesVisitados[i] = false;
	
	filaVisitacao.push_back(origem);
	verticesVisitados[origem] = true;
	
	while(!filaVisitacao.empty()){
		int verticeAtual = filaVisitacao.front();
		
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
	int vertices, pontoOrigem;
	int origem, destino;
	
	cin >> vertices >> pontoOrigem;
	
	//grafo nao ponderado e n�o direcionado
	bool grafo[10][10];
	
	for(int i=0;i<vertices;i++)
		for(int j=0; j<vertices;j++)
			grafo[i][j] = false;
	
	do{
		cin >> origem >> destino;
		grafo[origem][destino] = true;
		grafo[destino][origem] = true;
	} while(origem!=-1 && destino!=-1);
	

	if(bfs(grafo, vertices, pontoOrigem))
		cout << "Conexo" << endl;
	else
		cout << "Desconexo" << endl;
}