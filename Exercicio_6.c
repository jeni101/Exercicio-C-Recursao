#include <stdio.h>

void decimal_para_binario(int num) {
    Pilha p;
    inicializar(&p);

    if (num == 0) {
        printf("0\n");
        return;
    }

    while (num > 0) {
        push(&p, (num % 2) + '0'); // Converte para caractere
        num = num / 2;
    }

    while (!vazia(&p)) {
        printf("%c", pop(&p)); // Imprime em ordem inversa
    }
    printf("\n");
}

int main() {
    int n = 10;
    printf("Binario de %d: ", n);
    decimal_para_binario(n);
    return 0;
}
