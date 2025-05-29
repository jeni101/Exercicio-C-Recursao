#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX 100

// Estrutura da pilha
typedef struct {
    int dados[TAM_MAX];
    int topo;
} Pilha;

// Funções da pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return p->topo == -1;
}

int cheia(Pilha *p) {
    return p->topo == TAM_MAX - 1;
}

void empilhar(Pilha *p, int valor) {
    if (!cheia(p)) {
        p->dados[++(p->topo)] = valor;
    }
}

int desempilhar(Pilha *p) {
    if (!vazia(p)) {
        return p->dados[(p->topo)--];
    }
    return 0; // valor padrão de erro
}

// Função principal para avaliar expressão pós-fixa
int avaliar_posfixa(const char *expressao) {
    Pilha p;
    inicializar(&p);

    char token[20];
    int i = 0, j = 0;

    while (expressao[i] != '\0') {
        if (isspace(expressao[i])) {
            i++;
            continue;
        }

        // Se for número
        if (isdigit(expressao[i])) {
            j = 0;
            while (isdigit(expressao[i])) {
                token[j++] = expressao[i++];
            }
            token[j] = '\0';
            empilhar(&p, atoi(token));
        }
        // Se for operador
        else {
            int b = desempilhar(&p);
            int a = desempilhar(&p);
            int resultado;

            switch (expressao[i]) {
                case '+': resultado = a + b; break;
                case '-': resultado = a - b; break;
                case '*': resultado = a * b; break;
                case '/': resultado = a / b; break;
                default:
                    printf("Operador inválido: %c\n", expressao[i]);
                    return 0;
            }
            empilhar(&p, resultado);
            i++;
        }
    }

    return desempilhar(&p);
}

// Teste
int main() {
    const char *exp = "2 3 + 4 *"; // (2 + 3) * 4 = 20
    int resultado = avaliar_posfixa(exp);
    printf("Resultado: %d\n", resultado);
    return 0;
}
