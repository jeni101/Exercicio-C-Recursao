#include <stdio.h>
#include <string.h>
#define MAX 100

// Estrutura da pilha
typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

void push(Pilha *p, char c) {
    p->itens[++(p->topo)] = c;
}

char pop(Pilha *p) {
    return p->itens[(p->topo)--];
}

void inverter_string(char *str) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; str[i] != '\0'; i++) {
        push(&p, str[i]); // Empilha todos os caracteres
    }

    for (int i = 0; !vazia(&p); i++) {
        str[i] = pop(&p); // Desempilha para inverter
    }
}

int main() {
    char texto[] = "Python";
    inverter_string(texto);
    printf("Invertida com pilha: %s\n", texto);
    return 0;
}
