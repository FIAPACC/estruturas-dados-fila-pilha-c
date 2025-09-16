// pilha.c
#include <stdio.h>
#include <stdlib.h>

// Definição do nó da pilha
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Definição da pilha
typedef struct Stack {
    Node *top;
} Stack;

// Cria uma pilha vazia
Stack *create_stack() {
    Stack *s = malloc(sizeof(Stack));
    if (!s) {
        fprintf(stderr, "Erro ao alocar memória para a pilha\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    return s;
}

// Verifica se a pilha está vazia
int is_empty(Stack *s) {
    return (s->top == NULL);
}

// Empilha (push)
void push(Stack *s, int value) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Erro ao alocar memória para novo nó\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = s->top;
    s->top = new_node;
}

// Desempilha (pop), retorna valor; assume que não está vazia
int pop(Stack *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Pop em pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = s->top;
    int val = temp->data;
    s->top = temp->next;
    free(temp);
    return val;
}

// Vê elemento no topo sem remover
int peek(Stack *s) {
    if (is_empty(s)) {
        fprintf(stderr, "Peek em pilha vazia\n");
        exit(EXIT_FAILURE);
    }
    return s->top->data;
}

// Libera toda a pilha
void free_stack(Stack *s) {
    Node *current = s->top;
    while (current) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(s);
}

// Teste simples
int main() {
    Stack *s = create_stack();

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("Top: %d\n", peek(s));  // deve mostrar 30

    printf("Pop: %d\n", pop(s));    // retira 30
    printf("Pop: %d\n", pop(s));    // retira 20

    printf("Top agora: %d\n", peek(s));  // deve mostrar 10

    free_stack(s);
    return 0;
}
