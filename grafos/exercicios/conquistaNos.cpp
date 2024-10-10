#include <iostream>

using namespace std;

int main()
{
	int m, n;
	int origem, destino;

	cin >> m >> n;

	bool matrizAdj[m][m];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrizAdj[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cin >> origem >> destino;
		matrizAdj[origem - 1][destino - 1] = 1;
		matrizAdj[destino - 1][origem - 1] = 1;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrizAdj[i][j] << " ";
		}
		cout << endl;
	}
}