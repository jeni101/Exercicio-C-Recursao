#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100

// Estrutura do cliente
typedef struct {
    int id;
    char nome[50];
} Cliente;

// Estrutura da fila
typedef struct {
    Cliente dados[TAM_MAX];
    int inicio;
    int fim;
} Fila;

// Inicializa a fila
void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está vazia
int vazia(Fila *f) {
    return f->inicio == f->fim;
}

// Verifica se a fila está cheia
int cheia(Fila *f) {
    return f->fim == TAM_MAX;
}

// Adiciona um cliente na fila
void enfileirar(Fila *f, Cliente c) {
    if (!cheia(f)) {
        f->dados[f->fim++] = c;
        printf("Cliente %s (ID %d) entrou na fila.\n", c.nome, c.id);
    } else {
        printf("Fila cheia! Não é possível adicionar mais clientes.\n");
    }
}

// Remove o próximo cliente da fila
Cliente desenfileirar(Fila *f) {
    Cliente vazio = {-1, ""};

    if (!vazia(f)) {
        Cliente c = f->dados[f->inicio++];
        printf("Cliente %s (ID %d) foi atendido.\n", c.nome, c.id);
        return c;
    } else {
        printf("Fila vazia! Nenhum cliente para atender.\n");
        return vazio;
    }
}

// Mostra os clientes na fila
void mostrarFila(Fila *f) {
    if (vazia(f)) {
        printf("Fila está vazia.\n");
        return;
    }

    printf("Clientes na fila:\n");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("  - %s (ID %d)\n
