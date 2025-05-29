#include <stdio.h>

// Função recursiva para somar os elementos de um vetor
int soma_lista(int lista[], int tamanho) {
    if (tamanho == 0) {
        return 0; // Caso base: lista vazia retorna 0
    }
    return lista[tamanho - 1] + soma_lista(lista, tamanho - 1);
}

int main() {
    int lista[] = {1, 2, 3, 4, 5};
    int tamanho = sizeof(lista) / sizeof(lista[0]); // Calcula o tamanho do vetor 5 x5 = 25/ 4 = 5 
    printf("Soma da lista = %d\n", soma_lista(lista, tamanho));
    return 0;
}