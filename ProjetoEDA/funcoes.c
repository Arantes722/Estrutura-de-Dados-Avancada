#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "registos.h"

Cliente* inserirCliente(Cliente* inicio, char nome_utilizador[], char password[], char nome[], char email[], char endereco[]) 
{

        Cliente* novo = malloc(sizeof(struct registo_cliente)); //aloca memória para a nova estrutura "Cliente" usando a função "malloc".
        if (novo != NULL)
        {
            strcpy(novo->nome_utilizador, nome_utilizador); //copia o "nome_utilizador" para o campo "nome_utilizador" da nova estrutura usando a função "strcpy".
            strcpy(novo->password, password); //copia a "password" para o campo "password" da nova estrutura usando a função "strcpy".
            strcpy(novo->nome, nome); //copia o "nome" para o campo "nome" da nova estrutura usando a função "strcpy".
            strcpy(novo->email, email); //copia o "email" para o campo "email" da nova estrutura usando a função "strcpy".
            strcpy(novo->endereco, endereco); //copia o "endereco" para o campo "endereco" da nova estrutura usando a função "strcpy".
            novo->seguinte = inicio; //define o campo "seguinte" da nova estrutura como apontando para a lista "inicio".
            return(novo); //retorna a nova estrutura se a alocação de memória for bem sucedida e se não houver um cliente com o mesmo "nome_utilizador" na lista.
        }
}

Gestor* inserirGestor(Gestor* inicio, char nome_utilizador[], char password[], char nome[], char email[])
{

        Gestor* novo = malloc(sizeof(struct registo_gestor)); //aloca espaço na memória para um novo gestor "novo" usando a função "malloc". O tamanho alocado é do tamanho da estrutura "registo_gestor". Se a alocação for bem sucedida, entra no bloco "if". Se a alocação falhar, retorna NULL.
        if (novo != NULL)
        {
            //copia o "nome_utilizador", "password", "nome" e "email" para o novo gestor "novo" usando a função "strcpy".
            strcpy(novo->nome_utilizador, nome_utilizador);
            strcpy(novo->password, password);
            strcpy(novo->nome, nome);
            strcpy(novo->email, email);
    
            novo->seguinte = inicio; //atualiza o apontador "seguinte" do novo gestor "novo" para o início da lista ligada "inicio".
            return(novo); //retorna o endereço do novo gestor "novo".
        }

}

Meio* inserirMeio(Meio* inicio, int id,char nome_meio[], int preco, int autonomia, char geolocalizacao[])
{

        Meio* novo = malloc(sizeof(struct registo_meio));
        if (novo != NULL)
        {
            novo->id=id;
            strcpy(novo->nome_meio, nome_meio);
            novo->preco=preco;
            novo->autonomia=autonomia;
            novo->seguinte = inicio;
            strcpy(novo->geolocalizacao, geolocalizacao);
            return(novo);
        }

    
}



Meio* removerMeio(Meio* inicio, int id) {
    Meio* anterior = NULL;
    Meio* atual = inicio;

    if (atual == NULL)
        return NULL;
    else if (atual->id == id) {
        inicio = atual->seguinte;
        free(atual);
    } else {
        while (atual != NULL && atual->id != id) {
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual != NULL) {
            anterior->seguinte = atual->seguinte;
            free(atual);
        }
    }

    atualizarListaMeio(inicio); // Atualiza o arquivo com a lista atualizada
    return inicio;
}



Cliente* removerCliente(Cliente* inicio, char nome_utilizador[]) {
    Cliente* anterior = NULL;
    Cliente* atual = inicio;

    if (atual == NULL)
        return NULL;
    else if (strcmp(atual->nome_utilizador, nome_utilizador) == 0) {
        inicio = atual->seguinte;
        free(atual);
    } else {
        while (atual != NULL && strcmp(atual->nome_utilizador, nome_utilizador) != 0) {
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual != NULL) {
            anterior->seguinte = atual->seguinte;
            free(atual);
        }
    }

    atualizarListaCliente(inicio); // Atualiza o arquivo com a lista atualizada
    return inicio;
}





Gestor* removerGestor(Gestor* inicio, char nome_utilizador[]) {
    Gestor* anterior = NULL;
    Gestor* atual = inicio;

    if (atual == NULL)
        return NULL;
    else if (strcmp(atual->nome_utilizador, nome_utilizador) == 0) {
        inicio = atual->seguinte;
        free(atual);
    } else {
        while (atual != NULL && strcmp(atual->nome_utilizador, nome_utilizador) != 0) {
            anterior = atual;
            atual = atual->seguinte;
        }
        if (atual != NULL) {
            anterior->seguinte = atual->seguinte;
            free(atual);
        }
    }

    atualizarListaGestor(inicio); // Atualiza o arquivo com a lista atualizada
    return inicio;
}


void listarMeios(Meio* inicio) {
    printf("\n");
    printf(" ______________________________________________________________________________________________\n");
    printf("|   ID   |   Nome do Meio              |   Preco por hora   |   Autonomia                       |\n");
    printf("|________|____________________________|___________________|____________________________________|\n");
    
    while (inicio != NULL) {
        printf("|   %-4d |   %-25s |   %-16d |   %-30d |\n", inicio->id, inicio->nome_meio, inicio->preco, inicio->autonomia);
        inicio = inicio->seguinte;
    }
    
    printf("|________|____________________________|___________________|____________________________________|\n");
    printf("\n");
}


void listarClientes(Cliente* inicio) {
    printf("\n");
    printf(" _________________________________________________________________________________________________________________________\n");
    printf("|   Nome de utilizador    |   Password              |   Nome              |   Email              |   Endereco              |\n");
    printf("|_________________________|_________________________|_____________________|_____________________|_________________________|\n");

    while (inicio != NULL) {
        printf("|   %-22s |   %-21s |   %-18s |   %-18s |   %-22s |\n", inicio->nome_utilizador, inicio->password, inicio->nome, inicio->email, inicio->endereco);
        inicio = inicio->seguinte;
    }

    printf("|_________________________|_________________________|_____________________|_____________________|_________________________|\n");
    printf("\n");
}


void listarGestores(Gestor* inicio) {
    printf("\n");
    printf(" ___________________________________________________________________________________________________");
    printf("|   Nome de utilizador    |   Password              |   Nome              |   Email                 |\n");
    printf("|_________________________|_________________________|_____________________|__________________________|\n");

    while (inicio != NULL) {
        printf("|   %-22s |   %-21s |   %-18s |   %-25s |\n", inicio->nome_utilizador, inicio->password, inicio->nome, inicio->email);
        inicio = inicio->seguinte;
    }

    printf("|__________________________|_________________________|_____________________|__________________________|\n");
    printf("\n");
}


void verSaldo(float saldo) {
    printf("Saldo atual: %.2f\n", saldo);
}

void carregarSaldo(float *saldo) {
    float valor;
    printf("Digite o valor a ser carregado: ");
    scanf("%f", &valor);
    *saldo += valor;
    printf("Saldo carregado com sucesso!\n");
}

int guardarMeios(Meio* inicio) {
  FILE* fp;
  fp = fopen("meios.txt", "w");

  if (fp != NULL) {
    Meio* aux = inicio;
    while (aux != NULL) {
            fprintf(fp,"ID: %d\n",aux->id);
            fprintf(fp, "Nome do meio: %s\n", aux->nome_meio);
            fprintf(fp, "Preco do meio por hora: %d\n", aux->preco);
            fprintf(fp, "Autonomia: %d\n", aux->autonomia);
            fprintf(fp, "Geolocalizacao: %s\n\n", aux->geolocalizacao);
      aux = aux->seguinte;
    }
    fclose(fp);
    return 1;
  } else 
    return 0;
  }

  int guardarMeiosBin(Meio* inicio) {
    FILE* fp;
    fp = fopen("meios.bin", "wb");

    if (fp != NULL) {
        Meio* aux = inicio;
        while (aux != NULL) {
            fwrite(&(aux->id), sizeof(int), 1, fp);
            fwrite(aux->nome_meio, sizeof(char), strlen(aux->nome_meio) + 1, fp);
            fwrite(&(aux->preco), sizeof(int), 1, fp);
            fwrite(&(aux->autonomia), sizeof(int), 1, fp);
            fwrite(aux->geolocalizacao, sizeof(char), strlen(aux->geolocalizacao) + 1, fp);
            aux = aux->seguinte;
        }
        fclose(fp);
        return 1;
    } else {
        return 0;
    }
}


int guardarClientes(Cliente* inicio)
{FILE* fp;
 fp = fopen("clientes.txt","w");
 if (fp!=NULL)
 {
 Cliente* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"Nome de utilizador: %s\n",aux->nome_utilizador);
  fprintf(fp,"Password: %s\n",aux->password);
  fprintf(fp,"Nome: %s\n", aux->nome);
  fprintf(fp,"Email: %s\n",aux->email);
  fprintf(fp,"Endereco: %s\n\n",aux->endereco);

  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

int guardarClientesBin(Cliente* inicio) {
    FILE* fp;
    fp = fopen("clientes.bin", "wb");
    
    if (fp != NULL) {
        Cliente* aux = inicio;
        
        while (aux != NULL) {
            fwrite(aux->nome_utilizador, sizeof(char), strlen(aux->nome_utilizador) + 1, fp);
            fwrite(aux->password, sizeof(char), strlen(aux->password) + 1, fp);
            fwrite(aux->nome, sizeof(char), strlen(aux->nome) + 1, fp);
            fwrite(aux->email, sizeof(char), strlen(aux->email) + 1, fp);
            fwrite(aux->endereco, sizeof(char), strlen(aux->endereco) + 1, fp);
            
            aux = aux->seguinte;
        }
        
        fclose(fp);
        return 1;
    } else {
        return 0;
    }
}


int guardarGestores(Gestor* inicio)
{FILE* fp;
 fp = fopen("gestores.txt","w");
 if (fp!=NULL)
 {
 Gestor* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"Nome de utilizador: %s\n",aux->nome_utilizador);
  fprintf(fp,"Password: %s\n",aux->password);
  fprintf(fp,"Nome: %s\n", aux->nome);
  fprintf(fp,"Email: %s\n\n",aux->email);

  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

int guardarGestoresBin(Gestor* inicio) {
    FILE* fp;
    fp = fopen("gestores.bin", "wb");
    
    if (fp != NULL) {
        Gestor* aux = inicio;
        
        while (aux != NULL) {
            fwrite(aux->nome_utilizador, sizeof(char), strlen(aux->nome_utilizador) + 1, fp);
            fwrite(aux->password, sizeof(char), strlen(aux->password) + 1, fp);
            fwrite(aux->nome, sizeof(char), strlen(aux->nome) + 1, fp);
            fwrite(aux->email, sizeof(char), strlen(aux->email) + 1, fp);
            
            aux = aux->seguinte;
        }
        
        fclose(fp);
        return 1;
    } else {
        return 0;
    }
}

// Declaração da função para buscar o cliente por nome de utilizador
Cliente* buscarClientePorNomeUtilizador(Cliente* inicio, const char* nome_utilizador) {
  Cliente* atual = inicio;
  while (atual != NULL) {
    if (strcmp(atual->nome_utilizador, nome_utilizador) == 0) {
      return atual;
    }
    atual = atual->seguinte;
  }
  return NULL; // Retorna NULL se o cliente com o nome de utilizador fornecido não for encontrado
}

// Função para alterar os dados do cliente por nome de utilizador
void alterarDadosCliente(Cliente* inicio) {
  char nome_utilizador[50];
  printf("Digite o nome de utilizador do cliente que deseja alterar: ");
  fgets(nome_utilizador, sizeof(nome_utilizador), stdin);
  nome_utilizador[strcspn(nome_utilizador, "\n")] = '\0'; // remove o caractere de nova linha

  Cliente* cliente = buscarClientePorNomeUtilizador(inicio, nome_utilizador);
  if (cliente == NULL) {
    printf("O cliente com o nome de utilizador fornecido não foi encontrado.\n");
    return;
  }

  // Aloca memória para uma nova estrutura Cliente
  Cliente* novoCliente = (Cliente*)malloc(sizeof(Cliente));

  // Solicita ao usuário que digite os novos dados do cliente
  printf("Digite o novo nome de utilizador do cliente: ");
  fgets(novoCliente->nome_utilizador, sizeof(novoCliente->nome_utilizador), stdin);
  novoCliente->nome_utilizador[strcspn(novoCliente->nome_utilizador, "\n")] = '\0'; // remove o caractere de nova linha

  printf("Digite a nova password do cliente: ");
  fgets(novoCliente->password, sizeof(novoCliente->password), stdin);
  novoCliente->password[strcspn(novoCliente->password, "\n")] = '\0'; // remove o caractere de nova linha

  printf("Digite o novo nome do cliente: ");
  fgets(novoCliente->nome, sizeof(novoCliente->nome), stdin);
  novoCliente->nome[strcspn(novoCliente->nome, "\n")] = '\0'; // remove o caractere de nova linha

  printf("Digite o novo email do cliente: ");
  fgets(novoCliente->email, sizeof(novoCliente->email), stdin);
  novoCliente->email[strcspn(novoCliente->email, "\n")] = '\0'; // remove o caractere de nova linha

  printf("Digite o novo endereco do cliente: ");
  fgets(novoCliente->endereco, sizeof(novoCliente->endereco), stdin);
  novoCliente->endereco[strcspn(novoCliente->endereco, "\n")] = '\0'; // remove o caractere de nova linha

  // Copia os novos dados para a estrutura original
  strcpy(cliente->nome_utilizador, novoCliente->nome_utilizador);
  strcpy(cliente->password, novoCliente->password);
  strcpy(cliente->nome, novoCliente->nome);
  strcpy(cliente->email, novoCliente->email);
  strcpy(cliente->endereco, novoCliente->endereco);

  // Libera a memória alocada para a nova estrutura
  free(novoCliente);

  // Exibe mensagem confirmando que os dados foram alterados
  printf("Dados do cliente atualizados com sucesso.\n");
}



// Declaração da função para buscar o meio por ID
Meio* buscarMeioPorId(Meio* inicio, int id) {
  Meio* atual = inicio;
  while (atual != NULL) {
    if (atual->id == id) {
      return atual;
    }
    atual = atual->seguinte;
  }
  return NULL; // Retorna NULL se o meio com o ID fornecido não for encontrado
}

// Função para alterar os dados do meio por ID
void alterarDadosMeio(Meio* inicio) {
  int id;
  printf("Insira o ID do meio que deseja alterar: ");
  scanf("%d", &id);

  Meio* meio = buscarMeioPorId(inicio, id);
  if (meio == NULL) {
    printf("O meio com o ID fornecido nao foi encontrado.\n");
    return;
  }

  // Solicita ao usuário que digite os novos dados do meio
  printf("Insira o nome do meio: ");
  fgets(meio->nome_meio, sizeof(meio->nome_meio), stdin);
  meio->nome_meio[strcspn(meio->nome_meio, "\n")] = '\0'; // remove o caractere de nova linha

  printf("Insira o preco por hora do meio: ");
  scanf("%d", &(meio->preco)); // remove o caractere de nova linha

  printf("Insira a autonomia do meio: ");
  scanf("%d", &(meio->autonomia)); // remove o caractere de nova linha

  printf("Insira a geolocalizacao do meio: ");
  fgets(meio->geolocalizacao, sizeof(meio->geolocalizacao), stdin);
  meio->geolocalizacao[strcspn(meio->geolocalizacao, "\n")] = '\0';

  // Exibe mensagem confirmando que os dados foram alterados
  printf("Dados do meio atualizados com sucesso.\n");
}




// Declaração da função para buscar o gestor por nome de utilizador
Gestor* buscarGestorPorNomeUtilizador(Gestor* inicio, const char* nome_utilizador) {
  Gestor* atual = inicio;
  while (atual != NULL) {
    if (strcmp(atual->nome_utilizador, nome_utilizador) == 0) {
      return atual;
    }
    atual = atual->seguinte;
  }
  return NULL; // Retorna NULL se o gestor com o nome de utilizador fornecido não for encontrado
}

// Função para alterar os dados do gestor por nome de utilizador
void alterarDadosGestor(Gestor* inicio) {
  char nome_utilizador[50];
  printf("Digite o nome de utilizador do gestor que deseja alterar: ");
  fgets(nome_utilizador, sizeof(nome_utilizador), stdin);
  nome_utilizador[strcspn(nome_utilizador, "\n")] = '\0'; // remove o caractere de nova linha

  Gestor* gestor = buscarGestorPorNomeUtilizador(inicio, nome_utilizador);
  if (gestor == NULL) {
    printf("O gestor com o nome de utilizador fornecido não foi encontrado.\n");
    return;
  }

  // Aloca memória para uma nova estrutura Gestor
  Gestor* novoGestor = (Gestor*)malloc(sizeof(Gestor));

  // Solicita ao usuário que digite os novos dados do gestor
  printf("Insira o novo nome de utilizador do gestor: ");
  fgets(novoGestor->nome_utilizador, sizeof(novoGestor->nome_utilizador), stdin);
  novoGestor->nome_utilizador[strcspn(novoGestor->nome_utilizador, "\n")] = '\0'; // remove o caractere de nova linha

  printf("Insira a nova password do gestor: ");
  fgets(novoGestor->password, sizeof(novoGestor->password), stdin);
  novoGestor->password[strcspn(novoGestor->password, "\n")] = '\0'; // remove o caractere de nova linha

  printf("Insira o novo nome do gestor: ");
  fgets(novoGestor->nome, sizeof(novoGestor->nome), stdin);
  novoGestor->nome[strcspn(novoGestor->nome, "\n")] = '\0'; // remove o caractere de nova linha

  printf("Insira o novo email do gestor: ");
  fgets(novoGestor->email, sizeof(novoGestor->email), stdin);
  novoGestor->email[strcspn(novoGestor->email, "\n")] = '\0'; // remove o caractere de nova linha

  // Copia os novos dados para a estrutura original
  strcpy(gestor->nome_utilizador, novoGestor->nome_utilizador);
  strcpy(gestor->password, novoGestor->password);
  strcpy(gestor->nome, novoGestor->nome);
  strcpy(gestor->email, novoGestor->email);

  // Libera a memória alocada para a nova estrutura
  free(novoGestor);

  // Exibe mensagem confirmando que os dados foram alterados
  printf("Dados do gestor atualizados com sucesso.\n");
}



Cliente* lerClientes()
{FILE* fp;
char nome_utilizador[50], password[50], nome[50], email[50], endereco[50];
 Cliente* aux=NULL;
 fp = fopen("clientes.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  {
  fscanf(fp,"Nome de utilizador: %s\n",nome_utilizador);
  fscanf(fp,"Password: %s\n",password);
  fscanf(fp,"Nome: %s\n", nome);
  fscanf(fp,"Email: %s\n",email);
  fscanf(fp,"Endereco: %s\n\n",endereco);
    aux = inserirCliente(aux, nome_utilizador, password, nome, email,endereco);
  }
  fclose(fp);
 }
 return(aux);
}

Meio* lerMeios()
{FILE* fp;
char nome_meio[50], geolocalizacao[50];
int autonomia,preco,id;
 Meio* aux=NULL;
 fp = fopen("meios.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  {
            fscanf(fp,"ID: %d\n",&id);
            fscanf(fp,"Nome do meio: %s\n",nome_meio);
            fscanf(fp,"Preco do meio por hora: %d\n",&preco);
            fscanf(fp,"Autonomia: %d\n",&autonomia);
            fscanf(fp,"Geolocalizacao: %s\n\n",geolocalizacao);
    aux = inserirMeio(aux, id, nome_meio, preco, autonomia, geolocalizacao);
  }
  fclose(fp);
 }
 return(aux);
}

Gestor* lerGestores()
{FILE* fp;
char nome_utilizador[50], password[50], nome[50], email[50];
 Gestor* aux=NULL;
 fp = fopen("gestores.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  {
    fscanf(fp,"Nome de utilizador: %s\n",nome_utilizador);
    fscanf(fp,"Password: %s\n",password);
    fscanf(fp,"Nome: %s\n",nome);
    fscanf(fp,"Email: %s\n\n",email);
    aux = inserirGestor(aux, nome_utilizador, password, nome,email);
  }
  fclose(fp);
 }
 return(aux);
}

void listarMeiosOrdem(Meio * inicio)
{
    // Ordenação da lista pelo campo autonomia usando o bubble sort
    int trocou;
    Meio *atual;
    Meio *anterior = NULL;
    Meio *prox = NULL;

    do {
        trocou = 0;
        atual = inicio;
        while (atual->seguinte != prox) {
            if (atual->autonomia < atual->seguinte->autonomia) {
                // Troca a posição dos elementos
                if (anterior != NULL) {
                    anterior->seguinte = atual->seguinte;
                } else {
                    inicio = atual->seguinte;
                }
                Meio *aux = atual->seguinte->seguinte;
                atual->seguinte->seguinte = atual;
                atual->seguinte = aux;
                trocou = 1;
            }
            anterior = atual;
            atual = atual->seguinte;
        }
        prox = atual;
    } while (trocou);

        printf("\n");
        printf(" ______________________________________________________________________________________________________\n");
        printf("|   ID   |   Nome do Meio             |   Preco por hora  |   Autonomia   |   Geolocalizacao         |\n");
        printf("|________|____________________________|___________________|_______________|__________________________|\n");
    
    // Impressão da lista ordenada
        while (inicio != NULL) {
        printf("|   %-4d |   %-25s |   %-16d |   %-30d |    %-15s\n", inicio->id, inicio->nome_meio, inicio->preco, inicio->autonomia, inicio->geolocalizacao);
        inicio = inicio->seguinte;
    }
    
    printf("|________|____________________________|___________________|____________________________________|\n");
    printf("\n");
}

void alugarMeio(Meio* inicio, float* saldo) {
    int id;
    char nome_meio[50];
    printf("Insira o nome do meio de mobilidade que deseja alugar: ");
    scanf("%s", nome_meio);

    Meio* atual = inicio;
    while (atual != NULL) {
         if (strcmp(atual->nome_meio, nome_meio) == 0) {
            if (*saldo >= atual->preco) {
                *saldo -= atual->preco;
                printf("Meio alugado com sucesso.\n");
            } else {
                printf("Saldo insuficiente para alugar o meio de mobilidade.\n");
            }
            return;
        }
        atual = atual->seguinte;
    }

    printf("Meio com o nome %s nao encontrado.\n", nome_meio);
}


void atualizarListaMeio(Meio* inicio) {
    // Abre o arquivo para escrita
    FILE* fp = fopen("meios.txt", "w");

    // Verifica se o arquivo foi aberto corretamente
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Percorre a lista e escreve cada meio no arquivo
    while (inicio != NULL) {
            fprintf(fp,"ID: %d\n",inicio->id);
            fprintf(fp, "Nome do meio: %s\n", inicio->nome_meio);
            fprintf(fp, "Preco do meio por hora: %d\n", inicio->preco);
            fprintf(fp, "Autonomia: %d\n", inicio->autonomia);
            fprintf(fp, "Geolocalizacao: %s\n\n", inicio->geolocalizacao);
        inicio = inicio->seguinte;
    }

    // Fecha o arquivo
    fclose(fp);
}

void verHistoricoAlugueres(Cliente* inicio) {
    Aluguel* aluguelAtual = inicio->historicoAlugueres;

    if (aluguelAtual == NULL) {
        printf("Nenhum aluguel registado por este cliente.\n");
        return;
    }



    while (aluguelAtual != NULL) {
        printf("Meio de mobilidade: %s\n", aluguelAtual->nome_meio);
        printf("Valor pago: %d\n\n", aluguelAtual->valor_pago);

        aluguelAtual = aluguelAtual->proximo;
    }
}


void localizarMeioGeo(Meio* inicio, char geolocalizacao[]) {
    int encontrado = 0;

    while (inicio != NULL) {
        if (strcmp(inicio->geolocalizacao, geolocalizacao) == 0) {
            printf("\n");
        printf(" ______________________________________________________________________________________________________\n");
        printf("|   ID   |   Nome do Meio             |   Preco por hora  |   Autonomia   |   Geolocalizacao         |\n");
        printf("|________|____________________________|___________________|_______________|__________________________|\n");
    
    // Impressão da lista ordenada

        printf("|   %-4d |   %-25s |   %-16d |   %-30d |    %-15s\n", inicio->id, inicio->nome_meio, inicio->preco, inicio->autonomia, inicio->geolocalizacao);
    
    
    printf("|________|____________________________|___________________|____________________________________|\n");
    printf("\n");
            encontrado = 1;
        }
        inicio = inicio->seguinte;
    }

    if (!encontrado) {
        printf("Nenhum meio encontrado na geolocalizacao: %s\n", geolocalizacao);
    }
}

void listarMeiosPorGeolocalizacao(Meio* inicio) {
    char geolocalizacao[50];
    
    printf("Digite a geolocalizacao: ");
    scanf("%s", geolocalizacao);
    
    printf("Meios de mobilidade na geolocalizacao %s:\n", geolocalizacao);
    localizarMeioGeo(inicio, geolocalizacao);
}

void atualizarListaCliente(Cliente* inicio) {
    // Abre o arquivo para escrita
    FILE* fp = fopen("clientes.txt", "w");

    // Verifica se o arquivo foi aberto corretamente
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Percorre a lista e escreve cada meio no arquivo
    while (inicio != NULL) {
                              fprintf(fp,"Nome de utilizador: %s\n",inicio->nome_utilizador);
                              fprintf(fp,"Password: %s\n",inicio->password);
                              fprintf(fp,"Nome: %s\n", inicio->nome);
                              fprintf(fp,"Email: %s\n",inicio->email);
                              fprintf(fp,"Endereco: %s\n\n",inicio->endereco);
        inicio = inicio->seguinte;
    }

    // Fecha o arquivo
    fclose(fp);
}

void atualizarListaGestor(Gestor* inicio) {
    // Abre o arquivo para escrita
    FILE* fp = fopen("gestores.txt", "w");

    // Verifica se o arquivo foi aberto corretamente
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Percorre a lista e escreve cada meio no arquivo
    while (inicio != NULL) {
                              fprintf(fp,"Nome de utilizador: %s\n",inicio->nome_utilizador);
                              fprintf(fp,"Password: %s\n",inicio->password);
                              fprintf(fp,"Nome: %s\n", inicio->nome);
                              fprintf(fp,"Email: %s\n",inicio->email);
        inicio = inicio->seguinte;
    }

    // Fecha o arquivo
    fclose(fp);
}

int criarVertice(Grafo *g, char novoId[])
{Grafo novo = malloc(sizeof(struct registo1));
 if (novo!=NULL)
 {strcpy(novo->vertice,novoId);
  novo->meios = NULL;
  novo->clientes = NULL;
  novo->seguinte = *g;
  *g = novo;
  return(1);
 }
 else return(0);
}

// Devolve 1 se o vertice existe no grafo ou 0 caso contrário
int existeVertice(Grafo g, char vertice[])
{while (g!=NULL)
 {if (strcmp(g->vertice,vertice)==0) return(1);
  else g=g->seguinte;
 }
 return(0);
}

// Criar uma nova aresta
// Devolve 1 em caso de sucesso ou 0 caso contrário
int criarAresta(Grafo g, char vOrigem[], char vDestino[], float peso)
{Adjacente novo;
 if (existeVertice(g,vOrigem) && existeVertice(g,vDestino))
 {
  while(strcmp(g->vertice,vOrigem)!=0) g=g->seguinte;
  novo = malloc(sizeof(struct registo1));
  if (novo!=NULL)
	{strcpy(novo->vertice,vDestino);
	 novo->peso = peso;
	 novo->seguinte=g->adjacentes;
	 g->adjacentes=novo;
	 return(1);
	}
  else return(0);
 }
 else return(0);
}

// Listar os vértices adjacentes 
void listarAdjacentesMeios(Grafo g, char vertice[])
{Adjacente aux;
 if (existeVertice(g,vertice))
 {while (strcmp(g->vertice,vertice)!=0) g=g->seguinte;
  aux = g->adjacentes;
  while (aux!=NULL) 
  {printf("Geolocalizacao proxima:%s \nDistancia:%.2f metros\n", aux->vertice, aux->peso);
   aux=aux->seguinte;
  }
 }
}

// Inserir meio de transporte na localização com geocódigo passado por parâmetro
// Devolve 1 em caso de sucesso ou 0 caso contrário
int inserirMeioG(Grafo g, char geolocalizacao[], int id)
{
 while ((g!=NULL)&&(strcmp(g->vertice,geolocalizacao)!=0))
	 g=g->seguinte;
 if (g==NULL) return(0);
 else {Meios novo = malloc(sizeof(struct registo3));
       novo->id=id;
       novo->seguinte = g->meios;
       g->meios = novo;
       return(1);	 
      }
}

int inserirClienteG(Grafo g, char geolocalizacao[], char nome_utilizador[])
{
 while ((g!=NULL)&&(strcmp(g->vertice,geolocalizacao)!=0))
	 g=g->seguinte;
 if (g==NULL) return(0);
 else {Meios novo = malloc(sizeof(struct registo3));
       novo->nome_utilizador=nome_utilizador;
       novo->seguinte = g->meios;
       g->meios = novo;
       return(1);	 
      }
}


// Listar os códigos dos meios de transporte presente numa determinada localização passada por parâmetro
void listarMeiosG(Grafo g, char geolocalizacao[])
{
 while ((g!=NULL)&&(strcmp(g->vertice,geolocalizacao)!=0))
	 g=g->seguinte;
 if (g!=NULL) 
 {Meios aux=g->meios;
  if (aux==NULL) printf("Sem meios de transporte nesta localizacao.\n");
  else while(aux!=NULL)
  {printf("ID: %d\n", aux->id);
   aux = aux->seguinte;
  }
 }
 else printf("Geocodigo inexistente.\n");
}















