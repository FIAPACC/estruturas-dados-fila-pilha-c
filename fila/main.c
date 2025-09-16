#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int inicio;
    int fim;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->fim == MAX;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->inicio == f->fim;
}

// Enfileira (enqueue) um paciente
void enqueue(Fila *f, int senha) {
    if (filaCheia(f)) {
        printf("⚠️ Fila cheia! Não é possível adicionar mais pacientes.\n");
        return;
    }
    f->itens[f->fim++] = senha;
    printf("✅ Paciente com senha %d adicionado à fila.\n", senha);
}

// Desenfileira (dequeue) o paciente do início da fila
void dequeue(Fila *f) {
    if (filaVazia(f)) {
        printf("⚠️ Fila vazia! Nenhum paciente para atender.\n");
        return;
    }
    int senha = f->itens[f->inicio++];
    printf("🩺 Atendendo paciente com senha: %d\n", senha);
}

// Mostra a fila atual
void mostrarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("📭 Fila vazia.\n");
        return;
    }
    printf("📋 Fila atual: ");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->itens[i]);
    }
    printf("\n");
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    // Simulação de atendimento
    enqueue(&fila, 1001);
    enqueue(&fila, 1002);
    enqueue(&fila, 1003);
    mostrarFila(&fila);

    dequeue(&fila);
    mostrarFila(&fila);

    enqueue(&fila, 1004);
    mostrarFila(&fila);

    dequeue(&fila);
    mostrarFila(&fila);

    dequeue(&fila);
    dequeue(&fila);
    mostrarFila(&fila);

    return 0;
}
