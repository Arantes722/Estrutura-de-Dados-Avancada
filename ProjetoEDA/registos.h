#include <stdio.h>

typedef struct registo_meio
{
 char nome_meio[50];
 float preco;
 int codigo; // código do meio de mobilidade elétrica
 char tipo[50];
 float bateria;
 float autonomia;
 int disponivel;
 int quantidade;
 struct registo_meio* seguinte;
} Meio;


Meio* inserirMeio(Meio* inicio, char nome_meio[], char tipo[], float preco, int quantidade, int disponivel); // Inserção de um novo registo
void listarMeios(Meio* inicio); // listar na consola o conteúdo da lista ligada
int existeMeio(Meio* inicio, char nome_meio[]); // Determinar existência do 'codigo' na lista ligada 'inicio'
Meio* removerMeio(Meio* inicio, char nome_meio[]); // Remover um meio a partir do seu código
void alugarMeio(Meio *meios, int quantidade, float *saldo);
void verMeiosDisponiveis(Meio *inicio, int quantidade);
int guardarMeios(Meio* inicio);

int guardarMeios(Meio* inicio);
Meio* lerMeios();

typedef struct registo_cliente{
    char nome_utilizador[20];
    char password[20];
    int user_tipo; // 0 = cliente, 1 = administrador
    char nome[50];
    char email[50];
    char endereco[100];
    int idade;
    float saldo;
    struct registo_cliente* seguinte;
}Cliente;

Cliente* inserirCliente(Cliente* inicio, char nome_utilizador[], char password[], char nome[], char email[], char endereco[]); // Inserção de um novo registo
int existeCliente(Cliente* inicio, char nome_utilizador[]);
Cliente* removerCliente(Cliente* inicio, char nome_utilizador[]);
int guardarClientes(Cliente* inicio);

typedef struct registo_gestor{
    char nome_utilizador[20];
    char password[20];
    int user_tipo; // 0 = cliente, 1 = administrador
    char nome[20];
    char email[20];
    struct registo_gestor* seguinte;
}Gestor;

Gestor* inserirGestor(Gestor* inicio, char nome_utilizador[], char password[], char nome[], char email[]);
int existeGestor(Gestor* inicio, char nome_utilizador[]);
Gestor* removerGestor(Gestor* inicio, char nome_utilizador[]);
int guardarGestores(Gestor* inicio);

void carregarSaldo(float *saldo);
void verSaldo(float saldo);


