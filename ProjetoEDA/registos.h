#include <stdio.h>

typedef struct registo_meio
{
 char nome_meio[50];
 float preco;
 int codigo; 
 char tipo[50];
 float bateria;
 float autonomia;
 int disponivel;
 int quantidade;
 struct registo_meio* seguinte;
} Meio;


Meio* inserirMeio(Meio* inicio, char nome_meio[], char tipo[], float preco, int quantidade, int disponivel, float autonomia); // Inserção de um novo registo
void listarMeios(Meio* inicio); // listar na consola o conteúdo da lista ligada
int existeMeio(Meio* inicio, char nome_meio[]); // Determinar existência do 'codigo' na lista ligada 'inicio'
Meio* removerMeio(Meio* inicio, char nome_meio[]); // Remover um meio a partir do seu código
void alugarMeio(Meio *inicio, int quantidade, float *saldo); //aluga um meio de mobilidade elétrica a partir da lista ligada.
void verMeiosDisponiveis(Meio *inicio, int quantidade); //lista os meios de mobilidade elétrica disponíveis para aluguel.
int guardarMeios(Meio* inicio); //guarda os meios de mobilidade elétrica em um arquivo.
void ordenarMeiosPorAutonomia(Meio* inicio, int n); //ordena os meios de mobilidade elétrica por autonomia.
void alterarDadosMeio(Meio *inicio); //altera os dados de um meio de mobilidade elétrica na lista ligada.

int guardarMeios(Meio* inicio);
Meio* lerMeios(); //lê os meios de mobilidade elétrica a partir de um arquivo.

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
int existeCliente(Cliente* inicio, char nome_utilizador[]); //determina se um cliente com um determinado nome de usuário existe na lista ligada.
Cliente* removerCliente(Cliente* inicio, char nome_utilizador[]); //remove um cliente a partir do seu nome de usuário.
int guardarClientes(Cliente* inicio); //guarda os clientes em um arquivo.
void alterarDadosCliente(Cliente* inicio); //altera os dados de um cliente na lista ligada.

typedef struct registo_gestor{
    char nome_utilizador[20];
    char password[20];
    int user_tipo; // 0 = cliente, 1 = administrador
    char nome[20];
    char email[20];
    struct registo_gestor* seguinte;
}Gestor;

Gestor* inserirGestor(Gestor* inicio, char nome_utilizador[], char password[], char nome[], char email[]); //insere um novo gestor na lista ligada.
int existeGestor(Gestor* inicio, char nome_utilizador[]); //determina se um gestor com um determinado nome de usuário existe na lista ligada.
Gestor* removerGestor(Gestor* inicio, char nome_utilizador[]); //remove um gestor a partir do seu nome de usuário.
int guardarGestores(Gestor* inicio); //guarda os gestores em um arquivo.
void alterarDadosGestor(Gestor *inicio); //que altera os dados de um gestor na lista ligada.
 
void carregarSaldo(float *saldo); //carrega o saldo de uma conta de cliente.
void verSaldo(float saldo); //mostra o saldo de uma conta de cliente.


