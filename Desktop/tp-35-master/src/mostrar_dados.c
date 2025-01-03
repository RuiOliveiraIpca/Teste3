#include <stdio.h>
#include <string.h>
#include "Header.h"



// Função para exibir os funcionários
void mostrarFuncionarios(const Funcionario funcionarios[], int numFuncionarios)
{
    printf("\nLista de Funcionários:\n");
    printf("ID   Nome                    NIF        Telefone\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < numFuncionarios; i++)
    {
        printf("%-4d %-22s %-10s %-10s\n",
               funcionarios[i].id, funcionarios[i].nome,
               funcionarios[i].nif, funcionarios[i].telefone);
    }
}

// Função para exibir as ementas
void mostrarEmentas(const Ementa ementas[], int numEmentas)
{
    printf("\nLista de Ementas:\n");
    printf("Dia       Data       Peixe                    Calorias  Carne                    Calorias  Dieta                    Calorias  Vegetariano              Calorias\n");
    printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < numEmentas; i++)
    {
        printf("%-9s %-10s %-24s %-9d %-24s %-9d %-24s %-9d %-24s %-9d\n",
               ementas[i].dia, ementas[i].data,
               ementas[i].pratoPeixe, ementas[i].caloriasPeixe,
               ementas[i].pratoCarne, ementas[i].caloriasCarne,
               ementas[i].pratoDieta, ementas[i].caloriasDieta,
               ementas[i].pratoVegetariano, ementas[i].caloriasVegetariano);
    }
}

// Função para exibir as escolhas
void mostrarEscolhas(const Escolha escolhas[], int numEscolhas)
{
    printf("\nLista de Escolhas dos Utentes:\n");
    printf("Dia       ID Func.  Tipo de Prato\n");
    printf("----------------------------------\n");
    for (int i = 0; i < numEscolhas; i++)
    {
        printf("%-9s %-9d %-15c\n",
               escolhas[i].dia, escolhas[i].idFuncionario,
               escolhas[i].tipoPrato);
    }
}

// Função para apresentar as refeições requeridas pelos utentes
void RefeicoesPorDia(const Funcionario funcionarios[], int numFuncionarios,
                     const Ementa ementas[], int numEmentas,
                     const Escolha escolhas[], int numEscolhas,
                     const char *diaProcurado)
{
    printf("\nRefeições requeridas para o dia: %s\n", diaProcurado);
    printf("Funcionário   Nome                  Prato Escolhido          Dia da Semana\n");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < numEscolhas; i++)
    {
        if (strcmp(escolhas[i].dia, diaProcurado) == 0)
        {
            // Encontrar o funcionário correspondente
            char nomeFuncionario[100] = "Desconhecido";
            for (int j = 0; j < numFuncionarios; j++)
            {
                if (funcionarios[j].id == escolhas[i].idFuncionario)
                {
                    strncpy(nomeFuncionario, funcionarios[j].nome, sizeof(nomeFuncionario));
                    break;
                }
            }

            // Determinar o prato escolhido
            const char *pratoEscolhido = "Desconhecido";
            for (int k = 0; k < numEmentas; k++)
            {
                if (strcmp(ementas[k].dia, diaProcurado) == 0)
                {
                    switch (escolhas[i].tipoPrato)
                    {
                    case 'P':
                        pratoEscolhido = ementas[k].pratoPeixe;
                        break;
                    case 'C':
                        pratoEscolhido = ementas[k].pratoCarne;
                        break;
                    case 'D':
                        pratoEscolhido = ementas[k].pratoDieta;
                        break;
                    case 'V':
                        pratoEscolhido = ementas[k].pratoVegetariano;
                        break;
                    default:
                        pratoEscolhido = "Tipo de prato inválido";
                        break;
                    }
                    break;
                }
            }

            // Exibir as informações
            printf("%-12d %-20s %-24s %-15s\n",
                   escolhas[i].idFuncionario, nomeFuncionario, pratoEscolhido, diaProcurado);
        }
    }
}
