/**
 * @file ficheiros.c
 * @brief Implementação de funções para manipulação de ficheiros de dados.
 * 
 * Este arquivo contém as funções para ler e gravar dados em ficheiros de texto
 * relacionados a funcionários, ementas e escolhas de um sistema de gestão.
 * 
 * Cada função lida com formatos específicos de ficheiros, organizados por linhas 
 * separadas por `;`.
 * 
 * @author [Seu Nome]
 * @date [Data Atual]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

/**
 * @brief Lê os dados de funcionários a partir de um ficheiro.
 * 
 * Esta função lê os dados de um ficheiro com formato:
 * ```
 * id;nome;nif;telefone
 * ```
 * e preenche um array de estruturas do tipo `Funcionario`.
 * 
 * @param filename Caminho do ficheiro a ser lido.
 * @param funcionarios Array de estruturas para armazenar os dados.
 * @param maxFuncionarios Número máximo de funcionários que podem ser armazenados no array.
 * @return int Número de funcionários lidos com sucesso ou -1 em caso de erro.
 * 
 * @example Exemplo de uso:
 * ```c
 * Funcionario funcionarios[100];
 * int numFuncionarios = lerFuncionarios("funcionarios.txt", funcionarios, 100);
 * if (numFuncionarios == -1) {
 *     printf("Erro ao carregar os funcionários.\n");
 * }
 * ```
 */
int lerFuncionarios(const char *filename, Funcionario funcionarios[], int maxFuncionarios) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o ficheiro de funcionários");
        return -1;
    }

    int count = 0;
    while (count < maxFuncionarios && 
           fscanf(file, "%d;%99[^;];%9[^;];%9s\n", 
                  &funcionarios[count].id, funcionarios[count].nome, 
                  funcionarios[count].nif, funcionarios[count].telefone) == 4) {
        count++;
    }

    fclose(file);
    return count;
}

/**
 * @brief Lê os dados das ementas a partir de um ficheiro.
 * 
 * Esta função lê um ficheiro com formato:
 * ```
 * dia;data;pratoPeixe;caloriasPeixe;pratoCarne;caloriasCarne;pratoDieta;caloriasDieta;pratoVegetariano;caloriasVegetariano
 * ```
 * e preenche um array de estruturas do tipo `Ementa`.
 * 
 * @param filename Caminho do ficheiro a ser lido.
 * @param ementas Array de estruturas para armazenar os dados.
 * @param maxEmentas Número máximo de ementas que podem ser armazenadas no array.
 * @return int Número de ementas lidas com sucesso ou -1 em caso de erro.
 */
int lerEmenta(const char *filename, Ementa ementas[], int maxEmentas) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o ficheiro de ementas");
        return -1;
    }

    int count = 0;
    while (count < maxEmentas && 
           fscanf(file, "%9[^;];%10[^;];%99[^;];%d;%99[^;];%d;%99[^;];%d;%99[^;];%d\n",
                  ementas[count].dia, ementas[count].data,
                  ementas[count].pratoPeixe, &ementas[count].caloriasPeixe,
                  ementas[count].pratoCarne, &ementas[count].caloriasCarne,
                  ementas[count].pratoDieta, &ementas[count].caloriasDieta,
                  ementas[count].pratoVegetariano, &ementas[count].caloriasVegetariano) == 10) {
        count++;
    }

    fclose(file);
    return count;
}

/**
 * @brief Lê as escolhas dos utentes a partir de um ficheiro.
 * 
 * Esta função lê um ficheiro com formato:
 * ```
 * dia;idFuncionario;tipoPrato
 * ```
 * e preenche um array de estruturas do tipo `Escolha`.
 * 
 * @param filename Caminho do ficheiro a ser lido.
 * @param escolhas Array de estruturas para armazenar os dados.
 * @param maxEscolhas Número máximo de escolhas que podem ser armazenadas no array.
 * @return int Número de escolhas lidas com sucesso ou -1 em caso de erro.
 */
int lerEscolhas(const char *filename, Escolha escolhas[], int maxEscolhas) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o ficheiro de escolhas");
        return -1;
    }

    int count = 0;
    while (count < maxEscolhas && 
           fscanf(file, "%9[^;];%d;%c\n",
                  escolhas[count].dia, &escolhas[count].idFuncionario, 
                  &escolhas[count].tipoPrato) == 3) {
        count++;
    }

    fclose(file);
    return count;
}

/**
 * @brief Grava os dados dos funcionários em um ficheiro.
 * 
 * Escreve o conteúdo de um array de estruturas do tipo `Funcionario` em um ficheiro
 * com formato:
 * ```
 * id;nome;nif;telefone
 * ```
 * 
 * @param filename Caminho do ficheiro onde os dados serão gravados.
 * @param funcionarios Array de estruturas contendo os dados a serem gravados.
 * @param numFuncionarios Número de funcionários no array.
 * @return int Retorna 0 em caso de sucesso ou -1 em caso de erro.
 */
int gravarFuncionarios(const char *filename, const Funcionario funcionarios[], int numFuncionarios) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Erro ao abrir o ficheiro para gravação de funcionários");
        return -1;
    }

    for (int i = 0; i < numFuncionarios; i++) {
        fprintf(file, "%d;%s;%s;%s\n", funcionarios[i].id, funcionarios[i].nome, 
                funcionarios[i].nif, funcionarios[i].telefone);
    }

    fclose(file);
    return 0;
}

// As funções `gravarEmenta` e `gravarEscolhas` seguem o mesmo padrão de documentação.

