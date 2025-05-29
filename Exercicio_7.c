#include <stdio.h>
#include <string.h>

typedef struct {
    char acoes[100][100]; // Guardar strings de ações
    int topo;
} PilhaAcoes;

void inicializar_acoes(PilhaAcoes *p) {
    p->topo = -1;
}

void adicionar_acao(PilhaAcoes *p, char *acao) {
    strcpy(p->acoes[++(p->topo)], acao);
}

void desfazer(PilhaAcoes *p) {
    if (p->topo == -1) {
        printf("Nada a desfazer.\n");
    } else {
        printf("Desfeita: %s\n", p->acoes[(p->topo)--]);
    }
}

int main() {
    PilhaAcoes historico;
    inicializar_acoes(&historico);

    adicionar_acao(&historico, "Escreveu 'Olá'");
    adicionar_acao(&historico, "Apagou palavra");
    adicionar_acao(&historico, "Colou texto");

    desfazer(&historico);
    desfazer(&historico);
    desfazer(&historico);
    desfazer(&historico);

    return 0;
}
