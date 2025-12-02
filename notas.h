#ifndef NOTAS_H
#define NOTAS_H

// Definições de constantes
#define MAX_ALUNOS 30
#define QTD_NOTAS 4

/* --- Protótipos das Funções --- */

// Lê as 4 notas de cada aluno e preenche a matriz
void lerNotas(float notas[][QTD_NOTAS], int qtdAlunos);

// Calcula a média de cada aluno e armazena no vetor de médias
void calcularMedias(float notas[][QTD_NOTAS], float medias[], int qtdAlunos);

// Exibe a média de cada aluno na tela
void exibirMedias(float medias[], int qtdAlunos);

// Encontra a maior e a menor nota da turma (retorna por referência usando ponteiros)
void maiorMenorNota(float notas[][QTD_NOTAS], int qtdAlunos, float *maior, float *menor);

// Lista se os alunos foram aprovados (Média >= 6.0) ou reprovados
void listarAprovadosReprovados(float medias[], int qtdAlunos);

#endif
