#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* -------------------------------------------------------------------
   ---------------------- NIVEL 1: INVENTÁRIO -------------------------
   -------------------------------------------------------------------*/

// Struct dos itens básicos
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor que armazena até 10 itens
Item mochilaVetor[10];
int totalItensVetor = 0;

// Função para inserir item no vetor
void inserirItemVetor() {
    if (totalItensVetor >= 10) {
        printf("Mochila cheia!\n");
        return;
    }
    Item novo;
    printf("Nome: ");
    scanf(" %[^\n]", novo.nome);

    printf("Tipo: ");
    scanf(" %[^\n]", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochilaVetor[totalItensVetor] = novo;
    totalItensVetor++;

    printf("Item inserido com sucesso!\n");
}

// Remover item do vetor
void removerItemVetor() {
    char nome[30];
    printf("Nome do item para remover: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < totalItensVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            for (int j = i; j < totalItensVetor - 1; j++) {
                mochilaVetor[j] = mochilaVetor[j + 1];
            }
            totalItensVetor--;
            printf("Item removido!\n");
            return;
        }
    }
    printf("Item não encontrado.\n");
}

// Listar vetor
void listarItensVetor() {
    if (totalItensVetor == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n--- ITENS NO VETOR ---\n");
    for (int i = 0; i < totalItensVetor; i++) {
        printf("%d. %s | %s | %d\n",
               i + 1,
               mochilaVetor[i].nome,
               mochilaVetor[i].tipo,
               mochilaVetor[i].quantidade);
    }
}

// Busca sequencial no vetor
void buscarItemVetor() {
    char nome[30];
    printf("Nome do item para buscar: ");
    scanf(" %[^\n]", nome);

    int comparacoes = 0;

    for (int i = 0; i < totalItensVetor; i++) {
        comparacoes++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            printf("Item encontrado: %s | %s | %d\n",
                   mochilaVetor[i].nome,
                   mochilaVetor[i].tipo,
                   mochilaVetor[i].quantidade);

            printf("Comparações realizadas: %d\n", comparacoes);
            return;
        }
    }
    printf("Item não encontrado. Comparações: %d\n", comparacoes);
}

/* -------------------------------------------------------------------
   --------------------- NIVEL 2: LISTA ENCADEADA ---------------------
   -------------------------------------------------------------------*/

// Nó da lista encadeada
typedef struct No {
    Item dados;
    struct No *proximo;
} No;

No *inicio = NULL;

// Inserir item na lista encadeada
void inserirItemLista() {
    No *novo = (No *)malloc(sizeof(No));
    printf("Nome: ");
    scanf(" %[^\n]", novo->dados.nome);

    printf("Tipo: ");
    scanf(" %[^\n]", novo->dados.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo->dados.quantidade);

    novo->proximo = inicio;
    inicio = novo;

    printf("Item inserido na lista.\n");
}

// Remover item da lista encadeada
void removerItemLista() {
    char nome[30];
    printf("Nome do item: ");
    scanf(" %[^\n]", nome);

    No *atual = inicio, *ant = NULL;

    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            if (ant == NULL) inicio = atual->proximo;
            else ant->proximo = atual->proximo;

            free(atual);
            printf("Item removido.\n");
            return;
        }
        ant = atual;
        atual = atual->proximo;
    }

    printf("Item não encontrado.\n");
}

// Listar lista encadeada
void listarLista() {
    No *atual = inicio;

    if (!atual) {
        printf("Lista vazia.\n");
        return;
    }

    printf("\n--- ITENS NA LISTA ---\n");
    while (atual != NULL) {
        printf("%s | %s | %d\n",
               atual->dados.nome,
               atual->dados.tipo,
               atual->dados.quantidade);
        atual = atual->proximo;
    }
}

// Busca sequencial na lista
void buscarItemLista() {
    char nome[30];
    printf("Buscar item: ");
    scanf(" %[^\n]", nome);

    No *atual = inicio;
    int comparacoes = 0;

    while (atual != NULL) {
        comparacoes++;
        if (strcmp(atual->dados.nome, nome) == 0) {
            printf("Item encontrado: %s | %s | %d\n",
                   atual->dados.nome,
                   atual->dados.tipo,
                   atual->dados.quantidade);

            printf("Comparações: %d\n", comparacoes);
            return;
        }
        atual = atual->proximo;
    }

    printf("Item não encontrado. Comparações: %d\n", comparacoes);
}

/* -------------------------------------------------------------------
   --------------- NIVEL 3: TORRE FINAL – ORDENAÇÃO ------------------
   -------------------------------------------------------------------*/

typedef struct {
    char nome[30];
    char tipo[20];
    int prioridade;
} Componente;

Componente torre[20];
int totalComp = 0;

// Mostrar componentes
void mostrarComponentes(Componente v[], int n) {
    printf("\n--- COMPONENTES ---\n");
    for (int i = 0; i < n; i++) {
        printf("%s | %s | Prioridade: %d\n",
               v[i].nome, v[i].tipo, v[i].prioridade);
    }
}

// Bubble sort por nome
int bubbleSortNome(Componente v[], int n) {
    int comp = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (strcmp(v[j].nome, v[j + 1].nome) > 0) {
                Componente aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
    return comp;
}

// Insertion sort por tipo
int insertionSortTipo(Componente v[], int n) {
    int comp = 0;
    for (int i = 1; i < n; i++) {
        Componente chave = v[i];
        int j = i - 1;

        while (j >= 0 && strcmp(v[j].tipo, chave.tipo) > 0) {
            comp++;
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
    return comp;
}

// Selection sort por prioridade
int selectionSortPrioridade(Componente v[], int n) {
    int comp = 0;
    for (int i = 0; i < n - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < n; j++) {
            comp++;
            if (v[j].prioridade < v[menor].prioridade)
                menor = j;
        }

        Componente aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
    return comp;
}

// Busca binária por nome
int buscaBinaria(Componente v[], int n, char alvo[]) {
    int ini = 0, fim = n - 1, comp = 0;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        comp++;

        int r = strcmp(alvo, v[meio].nome);

        if (r == 0) {
            printf("Componente encontrado: %s\n", v[meio].nome);
            printf("Comparações na busca binária: %d\n", comp);
            return 1;
        } else if (r < 0) fim = meio - 1;
        else ini = meio + 1;
    }

    printf("Componente não encontrado. Comparações: %d\n", comp);
    return 0;
}

/* -------------------------------------------------------------------
   ----------------------------- MENU --------------------------------
   -------------------------------------------------------------------*/

void menuPrincipal() {
    int op;

    do {
        printf("\n=========== MENU PRINCIPAL ===========\n");
        printf("1 - Mochila com Vetor\n");
        printf("2 - Mochila com Lista Encadeada\n");
        printf("3 - Torre Final (Ordenação + Busca)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        // ---------------------- Vetor --------------------------
        if (op == 1) {
            int op2;
            do {
                printf("\n--- MENU VETOR ---\n");
                printf("1 - Inserir\n");
                printf("2 - Remover\n");
                printf("3 - Listar\n");
                printf("4 - Buscar\n");
                printf("0 - Voltar\n");
                scanf("%d", &op2);

                if (op2 == 1) inserirItemVetor();
                if (op2 == 2) removerItemVetor();
                if (op2 == 3) listarItensVetor();
                if (op2 == 4) buscarItemVetor();

            } while (op2 != 0);
        }

        // ---------------------- Lista Encadeada ----------------
        if (op == 2) {
            int op3;
            do {
                printf("\n--- MENU LISTA ---\n");
                printf("1 - Inserir\n");
                printf("2 - Remover\n");
                printf("3 - Listar\n");
                printf("4 - Buscar\n");
                printf("0 - Voltar\n");
                scanf("%d", &op3);

                if (op3 == 1) inserirItemLista();
                if (op3 == 2) removerItemLista();
                if (op3 == 3) listarLista();
                if (op3 == 4) buscarItemLista();

            } while (op3 != 0);
        }

        // ---------------------- Torre Final ---------------------
        if (op == 3) {
            int opcao;
            printf("Quantos componentes deseja cadastrar? (max 20): ");
            scanf("%d", &totalComp);

            for (int i = 0; i < totalComp; i++) {
                printf("\nComponente %d:\n", i + 1);
                printf("Nome: ");
                scanf(" %[^\n]", torre[i].nome);
                printf("Tipo: ");
                scanf(" %[^\n]", torre[i].tipo);
                printf("Prioridade (1-10): ");
                scanf("%d", &torre[i].prioridade);
            }

            printf("\nEscolha algoritmo de ordenação:\n");
            printf("1 - Bubble Sort (Nome)\n");
            printf("2 - Insertion Sort (Tipo)\n");
            printf("3 - Selection Sort (Prioridade)\n");
            scanf("%d", &opcao);

            int comparacoes = 0;
            clock_t inicioT, fimT;

            inicioT = clock();
            if (opcao == 1) comparacoes = bubbleSortNome(torre, totalComp);
            if (opcao == 2) comparacoes = insertionSortTipo(torre, totalComp);
            if (opcao == 3) comparacoes = selectionSortPrioridade(torre, totalComp);
            fimT = clock();

            double tempo = (double)(fimT - inicioT) / CLOCKS_PER_SEC;

            printf("\nOrdenação concluída!\nComparações: %d\nTempo: %.6f s\n", comparacoes, tempo);

            mostrarComponentes(torre, totalComp);

            // Se for ordenado por nome, permitir busca binária
            if (opcao == 1) {
                char chave[30];
                printf("\nNome do componente-chave: ");
                scanf(" %[^\n]", chave);

                buscaBinaria(torre, totalComp, chave);
            }
        }

    } while (op != 0);
}

/* -------------------------------------------------------------------
   ------------------------------ MAIN -------------------------------
   -------------------------------------------------------------------*/

int main() {
    menuPrincipal();
    return 0;
}
