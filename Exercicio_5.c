#include <stdio.h>
#include <string.h>

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

int eh_abertura(char c) {
    return c == '(' || c == '[' || c == '{';
}

int combina(char ab, char fe) {
    return (ab == '(' && fe == ')') || (ab == '[' && fe == ']') || (ab == '{' && fe == '}');
}

int verifica_balanceamento(char *exp) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];
        if (eh_abertura(c)) {
            push(&p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (vazia(&p) || !combina(pop(&p), c)) {
                return 0; // Não está balanceado
            }
        }
    }
    return vazia(&p); // Está balanceado se pilha estiver vazia no final
}

int main() {
    char exp[] = "{[()]}";
    if (verifica_balanceamento(exp)) {
        printf("Expressao balanceada!\n");
    } else {
        printf("Expressao desequilibrada!\n");
    }
    return 0;
}
