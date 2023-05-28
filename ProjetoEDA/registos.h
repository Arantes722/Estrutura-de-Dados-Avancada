#include <stdio.h>

typedef struct registo_meio
{
 char nome_meio[50],geolocalizacao[50];
 int preco, autonomia,id;
 struct registo_meio* seguinte;
} Meio;


Meio* inserirMeio(Meio* inicio, int id, char nome_meio[], int preco, int autonomia, char geolocalizacao[]); // Inserção de um novo registo
void listarMeios(Meio* inicio); // listar na consola o conteúdo da lista ligada
Meio* removerMeio(Meio* inicio, int id); // Remover um meio a partir do seu código
void alugarMeio(Meio *inicio, float *saldo); //aluga um meio de mobilidade elétrica a partir da lista ligada.
int guardarMeios(Meio* inicio); //guarda os meios de mobilidade elétrica em um arquivo.
void alterarDadosMeio(Meio *inicio); //altera os dados de um meio de mobilidade elétrica na lista ligada.
Meio* lerMeios(); //lê os meios de mobilidade elétrica a partir de um arquivo.
void listarMeios(Meio* inicio);
int guardarMeiosBin(Meio* inicio);
void listarMeiosOrdem(Meio * inicio);
void atualizarListaMeio(Meio* inicio);
void localizarMeioGeo(Meio* inicio, char geolocalizacao[]);
void listarMeiosPorGeolocalizacao(Meio* inicio);

typedef struct registo_cliente {
    char nome_utilizador[20];
    char password[20];
    char nome[50];
    char email[50];
    char endereco[100];
    int idade;
    float saldo;
    struct registo_cliente* seguinte;
    struct registo_aluguel* historicoAlugueres;
    struct No* localizacao;
} Cliente;

Cliente* inserirCliente(Cliente* inicio, char nome_utilizador[], char password[], char nome[], char email[], char endereco[]); // Inserção de um novo registo
int existeCliente(Cliente* inicio, char nome_utilizador[]); //determina se um cliente com um determinado nome de usuário existe na lista ligada.
Cliente* removerCliente(Cliente* inicio, char nome_utilizador[]); //remove um cliente a partir do seu nome de usuário.
int guardarClientes(Cliente* inicio); //guarda os clientes em um arquivo.
void alterarDadosCliente(Cliente* inicio); //altera os dados de um cliente na lista ligada.
Cliente* lerClientes();
void listarClientes(Cliente* inicio);
int guardarClientesBin(Cliente* inicio);
void atualizarListaCliente(Cliente* inicio);

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
void listarGestores(Gestor* inicio);
int guardarGestoresBin(Gestor* inicio);
Gestor* lerGestores();
void atualizarListaGestor(Gestor* inicio);

typedef struct registo_aluguel {
    char nome_meio[50];
    float valor_pago;
    struct registo_aluguel* proximo;
} Aluguel;

void verHistoricoAlugueres(Cliente* cliente);

#define TAM 50

typedef struct registo4
{
  Cliente* cliente;
  int idc;
  struct registo4* seguinte;
} * Clientes;


typedef struct registo3
{
  Meio* meio;
  int id;
  char nome_meio[50];
  struct registo3* seguinte;
} * Meios;

// Representação de um grafo orientado e pesado
typedef struct registo2
{char vertice[TAM]; // geocódigo what3words
 float peso;
 struct registo2 * seguinte;
} * Adjacente;

typedef struct registo1
{char vertice[TAM]; // geocódigo what3words
 Adjacente adjacentes;
 Meios meios;
 Clientes clientes; // Lista ligada com os códigos dos meios de transporte existente
   // neste geocódigo
 struct registo1 * seguinte;
} * Grafo;


// Protótipos

// Criar um novo vértice
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarVertice(Grafo *g, char novoId[]);
// Criar uma nova aresta
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarAresta(Grafo g, char vOrigem[], char vDestino[], float peso);
int existe(Grafo g, char vertice[]);
void listarAdjacentes(Grafo g, char vertice[]);
// Inserir meio de transporte na localização com geocódigo passado por parâmetro
int inserirMeioG(Grafo g, char geolocalizacao[], int id);
// Listar os códigos dos meios de transporte presente numa determinada localização passada por parâmetro
void listarMeiosG(Grafo g, char geolocalizacao[]);
int inserirClienteG(Grafo g, char geolocalizacao[], int idc);
void listarClientesG(Grafo g, char geolocalizacao[]);



