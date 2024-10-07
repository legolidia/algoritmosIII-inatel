#include<iostream>
#include<list>

using namespace std;

int main(){
	int n, m;
	int a, b;
	
	cin >> n >> m;
	
	bool grafo[100][100];
	
	for(int i=0;i<n;i++)
		for(int j=0; j<n;j++)
			grafo[i][j] = false;
	
	for(int i=0; i<m; i++){
		cin >> a >> b;
		a--;
		b--;
		grafo[a][b] = true;
		grafo[b][a] = true;
	}
	
	cout << endl;
	
	for(int i=0;i<n;i++){
		for(int j=0; j<n;j++){
			cout << grafo[i][j] << " ";
		}
		cout << endl <<endl;
	}
	
}