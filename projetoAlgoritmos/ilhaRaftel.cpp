#include <iostream>
#include <string>
using namespace std;

int buscaBinaria(string ilhas[], int tamanho, string pistaBuscada) {
    int esquerda = 0;
    int direita = tamanho - 1;
    
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        // Encontrou a pista
        if (ilhas[meio] == pistaBuscada) return meio;
        
        // Se a pista buscada é maior, ignore a metade esquerda
        if (ilhas[meio] < pistaBuscada) esquerda = meio + 1;
        // Se a pista buscada é menor, ignore a metade direita
        else direita = meio - 1;
    }
    
    // Se n�o encontrou a pista
    return -1;
}

int main() {
    string ilhas[] = {"Alabasta", "Dressrosa", "Enies Lobby", "Marineford", "Skypiea", "Water 7", "Wano"};
    int tamanho = sizeof(ilhas) / sizeof(ilhas[0]);
    string pistaBuscada = "Skypiea";
    
    int resultado = buscaBinaria(ilhas, tamanho, pistaBuscada);
    
    cout << "Indice da pista encontrada: " << resultado << endl;
    return 0;
}
