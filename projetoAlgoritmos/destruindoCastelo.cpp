#include <iostream>
using namespace std;

struct Projetil
{
  int poder;
  int peso;
};

int main()
{
  int t;
  int n;
  int k;
  int r;

  cin >> t;

  for (int teste = 0; teste < t; teste++)
  {

     cin >> n;

    Projetil projeteis[n];

    for (int i = 0; i < n; i++)
      cin >> projeteis[i].poder >> projeteis[i].peso;

    cin >> k;

    int vetor[k + 1];

    for (int i = 0; i <= k; i++)
      vetor[i] = 0;

    for (int i = 0; i < n; i++)
      for (int j = k; j >= projeteis[i].peso; j--)
        vetor[j] = max(vetor[j], vetor[j - projeteis[i].peso] + projeteis[i].poder);

      cin >> r;

    if (vetor[k] >= r)
      cout << "Missao completada com sucesso" << endl;
    else
      cout << "Falha na missao" << endl;
  }
  return 0;
}