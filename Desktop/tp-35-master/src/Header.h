#ifndef HEADER_H
#define HEADER_H

// Estruturas de Dados
typedef struct {
    int id;
    char nome[100];
    char nif[10];
    char telefone[10];
} Funcionario;

typedef struct {
    char dia[10];
    char data[11];
    char pratoPeixe[100];
    int caloriasPeixe;
    char pratoCarne[100];
    int caloriasCarne;
    char pratoDieta[100];
    int caloriasDieta;
    char pratoVegetariano[100];
    int caloriasVegetariano;
} Ementa;

typedef struct {
    char dia[10];
    int idFuncionario;
    char tipoPrato; // C, P, D ou V
} Escolha;

// Funções para manipulação de ficheiros
int lerFuncionarios(const char *filename, Funcionario funcionarios[], int maxFuncionarios);
int lerEmenta(const char *filename, Ementa ementas[], int maxEmentas);
int lerEscolhas(const char *filename, Escolha escolhas[], int maxEscolhas);
int gravarFuncionarios(const char *filename, const Funcionario funcionarios[], int numFuncionarios);
int gravarEmenta(const char *filename, const Ementa ementas[], int numEmentas);
int gravarEscolhas(const char *filename, const Escolha escolhas[], int numEscolhas);

// Funções para exibição de dados
void mostrarFuncionarios(const Funcionario funcionarios[], int numFuncionarios);
void mostrarEmentas(const Ementa ementas[], int numEmentas);
void mostrarEscolhas(const Escolha escolhas[], int numEscolhas);
void RefeicoesPorDia(const Funcionario funcionarios[], int numFuncionarios, const Ementa ementas[], int numEmentas, const Escolha escolhas[], int numEscolhas, const char *diaProcurado);

#endif // HEADER_H
