#include <stdio.h>

// Função recursiva para calcular o fatorial de n
int fatorial(int n) {
    if (n == 0 || n == 1) {
        return 1; // Caso base: fatorial de 0 ou 1 é 1
    }
    return n * fatorial(n - 1); // Chamada recursiva
}

int main() {
    int num = 5;
    printf("Fatorial de %d = %d\n", num, fatorial(num));
    return 0;
}