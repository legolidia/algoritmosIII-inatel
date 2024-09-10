#include <iostream>
#include <string>

using namespace std;

struct Pedra
{
	string nome;
	float peso;
	int volume;
	int valor;
};

int potencia(int base, int expoente)
{
	if (expoente == 0)
		return 1;
	return base * potencia(base, expoente - 1);
}

int calcula_valor(Pedra pedras[], int n, int cap_peso, int cap_volume, bool pedras_atuais[])
{
	int valor = 0;
	for (int i = 0; i < n; i++)
	{
		if (pedras_atuais[i])
		{
			cap_peso -= pedras[i].peso;
			cap_volume -= pedras[i].volume;
			if (cap_peso >= 0 && cap_volume >= 0)
			{
				valor += pedras[i].valor;
			}
			else
				return 0;
		}
	}
	return valor;
}

void escolhePedras(Pedra pedras[], int n, int cap_peso, int cap_volume)
{
	bool melhores_pedras[n], pedras_atuais[n];
	for (int i = 0; i < n; i++)
	{
		melhores_pedras[i] = false;
		pedras_atuais[i] = false;
	}
	int valor_atual = 0, melhor_valor = 0;
	int limite = potencia(2, n);
	for (int i = 1; i <= limite; i++)
	{
		for (int i = 0; i < n; i++)
		{
			if (pedras_atuais[i] == false)
			{
				pedras_atuais[i] = true;
				break;
			}
			else
			{
				pedras_atuais[i] = false;
			}
		}
		valor_atual = calcula_valor(pedras, n, cap_peso, cap_volume, pedras_atuais);
		if (valor_atual > melhor_valor)
		{
			melhor_valor = valor_atual;
			for (int i = 0; i < n; i++)
				melhores_pedras[i] = pedras_atuais[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (melhores_pedras[i])
			cout << pedras[i].nome << endl;
	}
}

int main()
{
	int numeroDePedras;
	cin >> numeroDePedras;
	Pedra pedras[numeroDePedras];
	for (int i = 0; i < numeroDePedras; i++)
	{
		float volume;
		cin >> pedras[i].nome;
		cin >> volume;
		pedras[i].volume = volume * 1000;
		cin >> pedras[i].peso;
		cin >> pedras[i].valor;
	}

	escolhePedras(pedras, numeroDePedras, 400, 1000);

	return 0;
}