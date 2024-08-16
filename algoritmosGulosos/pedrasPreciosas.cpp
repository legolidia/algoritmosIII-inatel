#include<iostream>
using namespace std;

struct pedra
{
    char nome[50];
	int valor;
	int peso;
	int volume;
};

int escolhe_pedras(pedra pedras[], int n, int i, int cap_peso, int cap_volume){
	
	if(i >= n || cap_peso <= 0 || cap_volume <= 0){
		return 0;
	}
	
	int solucao1=0, solucao2 = 0;

	solucao1 = 0 +
	escolhe_pedras(pedras, n, i + 1, cap_peso, cap_volume);

	int nova_cap_peso = cap_peso - pedras[i].peso;
	int nova_cap_volume = cap_volume - pedras[i].volume;

	if(nova_cap_peso >= 0 && nova_cap_volume >= 0){
		solucao2 = pedras[i].valor +
		escolhe_pedras(pedras, n, i + 1, nova_cap_peso, nova_cap_volume);
	}

	return max(solucao1, solucao2);
}


int main()
{
	int n;
	cin >> n;

	pedra pedras[n];

	for(int i = 0; i < n; i++)
	{
		float volume;
		cin >> pedras[i].nome;
		cin >> volume;
		pedras[i].volume = volume * 1000;
		cin >> pedras[i].peso;
		cin >> pedras[i].valor;
	}

	return 0;
}
