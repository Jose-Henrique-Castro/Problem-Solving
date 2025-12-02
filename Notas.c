#include <stdio.h>
#include "notas.h"

void lerNotas(float notas[][QTD_NOTAS], int qtdAlunos) {
    int i, j;
    
    printf("\n--- Cadastro de Notas ---\n");
    for (i = 0; i < qtdAlunos; i++) {
        printf("Aluno #%d:\n", i + 1);
        for (j = 0; j < QTD_NOTAS; j++) {
            printf("  Digite a nota da avaliacao %d: ", j + 1);
            scanf("%f", &notas[i][j]);
            
            // Validação: nota deve ser entre 0 e 10
            while(notas[i][j] < 0 || notas[i][j] > 10) {
                printf("  Nota invalida! Digite entre 0 e 10: ");
                scanf("%f", &notas[i][j]);
            }
        }
        printf("\n");
    }
    printf("Notas cadastradas com sucesso!\n");
}

void calcularMedias(float notas[][QTD_NOTAS], float medias[], int qtdAlunos) {
    int i, j;
    float soma;

    for (i = 0; i < qtdAlunos; i++) {
        soma = 0; // Reinicia a soma para cada aluno
        for (j = 0; j < QTD_NOTAS; j++) {
            soma += notas[i][j];
        }
        medias[i] = soma / QTD_NOTAS;
    }
    printf("\nMedias calculadas (atualizadas internamente).\n");
}

void exibirMedias(float medias[], int qtdAlunos) {
    int i;
    printf("\n--- Relatorio de Medias ---\n");
    for (i = 0; i < qtdAlunos; i++) {
        printf("Aluno #%d -> Media: %.2f\n", i + 1, medias[i]);
    }
}

void maiorMenorNota(float notas[][QTD_NOTAS], int qtdAlunos, float *maior, float *menor) {
    int i, j;
    
    // Inicializa com a primeira nota do primeiro aluno
    *maior = notas[0][0];
    *menor = notas[0][0];

    // Percorre toda a matriz comparando
    for (i = 0; i < qtdAlunos; i++) {
        for (j = 0; j < QTD_NOTAS; j++) {
            if (notas[i][j] > *maior) {
                *maior = notas[i][j];
            }
            if (notas[i][j] < *menor) {
                *menor = notas[i][j];
            }
        }
    }
}

void listarAprovadosReprovados(float medias[], int qtdAlunos) {
    int i;
    printf("\n--- Status Final (Aprovacao) ---\n");
    for (i = 0; i < qtdAlunos; i++) {
        printf("Aluno #%d (Media %.2f): ", i + 1, medias[i]);
        
        // Estrutura de decisão (if/else)
        if (medias[i] >= 6.0) {
            printf("APROVADO\n");
        } else {
            printf("REPROVADO\n");
        }
    }
}
