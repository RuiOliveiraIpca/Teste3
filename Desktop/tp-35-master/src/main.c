/**
 * @file main.c
 * @brief Programa principal para gestão de funcionários, ementas e escolhas no espaço social.
 * 
 * Este programa realiza a leitura de dados de funcionários, ementas e escolhas 
 * de ficheiros específicos e apresenta informações relevantes, como:
 * - Lista de funcionários
 * - Ementas da semana
 * - Escolhas realizadas pelos utentes
 * - Refeições solicitadas para um dia específico
 * 
 * @author [Seu Nome]
 * @date [Data Atual]
 */

#include <stdio.h>
#include "Header.h" // Declarações de funções e estruturas globais

/// Array global para armazenar os dados dos funcionários.
Funcionario funcionarios[100];

/// Array global para armazenar os dados das ementas.
Ementa ementas[50];

/// Array global para armazenar as escolhas realizadas pelos utentes.
Escolha escolhas[200];

/**
 * @brief Função principal do programa.
 * 
 * Realiza a inicialização do programa, lendo os dados de funcionários, ementas e escolhas
 * a partir de ficheiros, e apresenta as informações para o utilizador.
 * 
 * As principais etapas do programa são:
 * - Ler dados de ficheiros
 * - Verificar erros durante a leitura
 * - Mostrar listas detalhadas
 * - Apresentar refeições por dia
 * 
 * @return int Retorna 0 se o programa for executado com sucesso, ou 1 em caso de erro.
 * 
 * @example Uso:
 * O programa espera que os ficheiros estejam organizados como no exemplo:
 * - Funcionários: "./data/funcionarios.txt"
 * - Ementas: "./data/ementas.txt"
 * - Escolhas: "./data/escolhas.txt"
 */
int main() {
    // Lê os dados do ficheiro de funcionários e armazena no array global
    int numFuncionarios = lerFuncionarios("./data/funcionarios.txt", funcionarios, 100);
    if (numFuncionarios == -1) {
        printf("Erro ao carregar dados de funcionários.\n");
        return 1;
    }

    // Lê os dados do ficheiro de ementas e armazena no array global
    int numEmentas = lerEmenta("./data/ementas.txt", ementas, 50);
    if (numEmentas == -1) {
        printf("Erro ao carregar dados de ementas.\n");
        return 1;
    }

    // Lê os dados do ficheiro de escolhas e armazena no array global
    int numEscolhas = lerEscolhas("./data/escolhas.txt", escolhas, 200);
    if (numEscolhas == -1) {
        printf("Erro ao carregar dados de escolhas.\n");
        return 1;
    }

    // Mostra a lista de funcionários carregados
    mostrarFuncionarios(funcionarios, numFuncionarios);

    // Mostra a lista de ementas carregadas
    mostrarEmentas(ementas, numEmentas);

    // Mostra a lista de escolhas carregadas
    mostrarEscolhas(escolhas, numEscolhas);

    // Solicita ao utilizador o dia da semana para verificar as refeições correspondentes
    char diaProcurado[10];
    printf("Digite o dia da semana (ex: 2feira): ");
    scanf("%s", diaProcurado);

    // Apresenta as refeições solicitadas para o dia escolhido
    RefeicoesPorDia(funcionarios, numFuncionarios, ementas, numEmentas, escolhas, numEscolhas, diaProcurado);

    return 0;
}
