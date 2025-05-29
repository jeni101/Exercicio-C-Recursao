#include <stdio.h>
#include <string.h>

// Função recursiva para inverter uma string
void inverter_string(char *str, int inicio, int fim) {
    if (inicio >= fim) return; // Caso base: ponteiros se encontram
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    inverter_string(str, inicio + 1, fim - 1); // Chamada recursiva
}

int main() {
    char texto[] = "recursao";
    inverter_string(texto, 0, strlen(texto) - 1);
    printf("String invertida = %s\n", texto);
    return 0;
}