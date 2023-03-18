#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "registos.h"

Cliente* inserirCliente(Cliente* inicio, char nome_utilizador[], char password[], char nome[], char email[], char endereco[]) 
{
    if (!existeCliente(inicio, nome_utilizador)) //verifica se já existe um cliente na lista com o mesmo "nome_utilizador", usando a função "existeCliente".
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
    else
    {
        return(inicio); //retorna a lista "inicio" se já existir um cliente com o mesmo "nome_utilizador" na lista.
    }
}


int existeCliente(Cliente* inicio, char nome_utilizador[])
{while(inicio!=NULL) //define um loop "while" que percorre a lista ligada enquanto "inicio" não for NULL.
  {if (strcmp(inicio->nome_utilizador, nome_utilizador) == 0) //verifica se o "nome_utilizador" do cliente atual "inicio" é igual a true (diferente de zero).
    return(1); //retorna 1 se encontrar um cliente com o "nome_utilizador" buscado na lista.
   inicio = inicio->seguinte; //atualiza o apontador "inicio" para o próximo cliente da lista.
  }
 return(0); //retorna 0 se o cliente com o "nome_utilizador" buscado não for encontrado na lista.
}

Gestor* inserirGestor(Gestor* inicio, char nome_utilizador[], char password[], char nome[], char email[])
{
    if (!existeGestor(inicio, nome_utilizador)) //verifica se o gestor com o "nome_utilizador" informado já existe na lista ligada. Se não existir, entra no bloco "if". Se já existir, entra no bloco "else".
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
    else
    {
        return(inicio); //se o gestor já existir na lista ligada "inicio", retorna o próprio início da lista sem inserir um novo gestor.
    }
}


int existeGestor(Gestor* inicio, char nome_utilizador[])
{while(inicio!=NULL)
  {if (inicio->nome_utilizador) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}

Meio* inserirMeio(Meio* inicio, char nome_meio[], char tipo[], float preco, int disponivel, int quantidade, float autonomia)
{
    if (!existeMeio(inicio, nome_meio))
    {
        Meio* novo = malloc(sizeof(struct registo_meio));
        if (novo != NULL)
        {
            strcpy(novo->nome_meio, nome_meio);
            strcpy(novo->tipo, tipo);
            novo->preco,preco;
            novo->disponivel;
            novo->quantidade;
            novo->autonomia;
    
            novo->seguinte = inicio;
            return(novo);
        }
    }
    else
    {
        return(inicio);
    }
}


int existeMeio(Meio* inicio, char nome_meio[])
{while(inicio!=NULL)
  {if (inicio->nome_meio) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}


Meio* removerMeio(Meio* inicio, char nome_meio[]) 
{
 Meio *anterior=inicio, *atual=inicio, *aux; //declaração de três ponteiros para Meio: anterior, atual e aux.

 if (atual==NULL) return(NULL); //verificação se a lista está vazia.
 else if (atual->nome_meio) // verificação se o nome do meio a ser removido é igual ao nome do primeiro meio da lista.
 {aux = atual->seguinte; //atribuição do próximo meio como auxiliar.
  free(atual);//liberação da memória alocada para o meio atual.
  return(aux);//retorno do ponteiro para o próximo meio (novo início da lista).
 }
 else
 {while ((atual!=NULL)&&(atual->nome_meio)) //enquanto não for encontrado o meio com o nome correspondente ou até o final da lista ser alcançado, a busca continua.
  {anterior = atual;//atualização do ponteiro anterior.
   atual = atual->seguinte;//atualização do ponteiro atual.
  } 
  if (atual==NULL) //verificação se o final da lista foi alcançado sem encontrar o meio a ser removido.
  return(inicio);//retorno do início da lista (não houve alterações).
  else
  {anterior->seguinte = atual->seguinte;//atualização do ponteiro seguinte do meio anterior, pulando o meio a ser removido.
   free(atual);//liberação da memória alocada para o meio atual.
   return(inicio);//retorno do ponteiro para o início da lista (pode ter sido alterado).
  }
 }
}

Cliente* removerCliente(Cliente* inicio, char nome_utilizador[]) 
{
 Cliente *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->nome_utilizador) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->nome_utilizador)) 
  {anterior = atual;
   atual = atual->seguinte;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinte = atual->seguinte;
   free(atual);
   return(inicio);
  }
 }
}

Gestor* removerGestor(Gestor* inicio, char nome_utilizador[]) 
{
 Gestor *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->nome_utilizador) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->nome_utilizador)) 
  {anterior = atual;
   atual = atual->seguinte;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinte = atual->seguinte;
   free(atual);
   return(inicio);
  }
 }
}

void listarMeios(Meio * inicio)
{while (inicio != NULL)
 {printf("%s %s %.2f %d %d %.2f\n",inicio->nome_meio,inicio->tipo,inicio->preco,inicio->disponivel,inicio->quantidade,inicio->autonomia);
  inicio = inicio->seguinte;
 }
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

void alugarMeio(Meio *inicio, int quantidade, float *saldo) {
    char nome_meio;
    printf("Digite o nome do meio que deseja alugar: ");
    scanf("%d", &nome_meio);
//inicializa uma variável do tipo inteiro index com o valor -1, em seguida, percorre o array de structs Meio procurando o primeiro elemento cujo campo nome_meio não é zero. Se um tal elemento for encontrado, seu índice é armazenado na variável index e o loop é encerrado com uma instrução break. Se nenhum elemento correspondente for encontrado, a variável index permanece como -1.
    int index = -1;
    for (int i = 0; i < quantidade; i++) {
        if (inicio[i].nome_meio) {
            index = i;
            break;
        }
    }
//verificam se a variável index ainda é igual a -1, indicando que nenhum meio correspondente foi encontrado no array. Se esse for o caso, uma mensagem de erro é exibida, e a função retorna.
//Se um meio correspondente for encontrado, o código verifica o campo disponivel desse meio. Se o campo for false, indicando que o meio não está disponível para aluguel, uma mensagem de erro é exibida, e a função retorna.
if (index == -1) {
        printf("Meio nao encontrado!\n");
        return;
    }
    if (!inicio[index].disponivel) {
        printf("Meio indisponivel!\n");
        return;
    }

//verifica se o saldo do usuário é menor que o preço do meio selecionado. Se este for o caso, uma mensagem de erro é exibida, e a função retorna. Caso contrário, a função é concluída com êxito.
    if (*saldo < inicio[index].preco) {
        printf("Saldo insuficiente!\n");
        return;
    }

}
void verMeiosDisponiveis(Meio *inicio, int quantidade) {
    printf("Nome do meio\tPreco por hora \tDsponibilidade \tAutonomia\n");
    //percorre o array de structs Meio e exibe informações sobre cada meio disponível. Para cada meio, o código exibe o valor dos campos nome_meio, preco, disponivel e autonomia. O valor do campo autonomia é exibido como "Sim" se for diferente de zero e "Não" caso contrário.
    for (int i = 0; i < quantidade; i++) {
        printf("%s\t%.2f\t%d\t%.2f\n", inicio[i].nome_meio, inicio[i].preco, inicio[i].disponivel, inicio[i].autonomia ? "Sim" : "Não");
    }
}

int guardarMeios(Meio* inicio)
//abrem o arquivo "meios.txt" em modo de escrita ("w") e retornam um ponteiro para o arquivo (fp).
{FILE* fp;
 fp = fopen("meios.txt","w");
 //escreve no arquivo "meios.txt" informações sobre cada elemento da lista encadeada de meios. Para cada elemento, o código usa a função fprintf para escrever uma string com informações sobre o meio, incluindo o nome do meio, o tipo do meio, o preço por hora, a disponibilidade, a quantidade e a autonomia. O ponteiro aux é usado para percorrer a lista encadeada. Após escrever todas as informações no arquivo, a função fecha o arquivo e retorna 1 se a operação foi bem sucedida ou 0 caso contrário.
 if (fp!=NULL)
 {
 Meio* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"Nome do meio: %s;\nTipo do meio: %s;\nPreco do meio por hora: %.2f;\nDisponibilidade do meio: %d;\nQuantidade: %d;\nAutonomia: %f", aux->nome_meio, aux->tipo, aux->preco,aux->disponivel, aux->quantidade, aux->autonomia);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

int guardarClientes(Cliente* inicio)
{FILE* fp;
 fp = fopen("clientes.txt","w");
 if (fp!=NULL)
 {
 Cliente* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"Nome de utilizador: %s;\nPassword: %s;\nNome: %s;\nEmail: %s;\nEndereco: %s;\n", aux->nome_utilizador, aux->password, aux->nome,aux->email, aux->endereco);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}


int guardarGestores(Gestor* inicio)
{FILE* fp;
 fp = fopen("gestores.txt","w");
 if (fp!=NULL)
 {
 Gestor* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"Nome de utilizador: %s;\nPassword: %s;\nNome: %s;\nEmail: %s;\n", aux->nome_utilizador, aux->password, aux->nome,aux->email);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}

void alterarDadosCliente(Cliente *inicio) {
  // solicita ao usuário que digite os novos dados do cliente
  printf("Digite o nome de utilizador do cliente: ");
  fgets(inicio->nome_utilizador, 50, stdin);
  inicio->nome_utilizador[strcspn(inicio->nome_utilizador, "\n")] = 0; // remove o caractere de nova linha

  printf("Digite a password do cliente: ");
  fgets(inicio->password, 20, stdin);
  inicio->password[strcspn(inicio->password, "\n")] = 0; // remove o caractere de nova linha

  printf("Digite o nome do cliente: ");
  fgets(inicio->nome, 20, stdin);
  inicio->nome[strcspn(inicio->nome, "\n")] = 0; // remove o caractere de nova linha

  printf("Digite o email do cliente: ");
  fgets(inicio->email, 20, stdin);
  inicio->email[strcspn(inicio->email, "\n")] = 0; // remove o caractere de nova linha

  printf("Digite o endereco do cliente: ");
  fgets(inicio->endereco, 20, stdin);
  inicio->endereco[strcspn(inicio->endereco, "\n")] = 0; // remove o caractere de nova linha

  // exibe mensagem confirmando que os dados foram alterados
  printf("Dados do cliente atualizados com sucesso.\n");
}

void alterarDadosMeio(Meio *inicio) {
  // solicita ao usuário que digite os novos dados do cliente
  printf("Digite o nome de utilizador do meio: ");
  fgets(inicio->nome_meio, 50, stdin);
  inicio->nome_meio[strcspn(inicio->nome_meio, "\n")] = 0; // remove o caractere de nova linha

  printf("Digite o tipo do meio: ");
  fgets(inicio->tipo, 20, stdin);
  inicio->tipo[strcspn(inicio->tipo, "\n")] = 0; // remove o caractere de nova linha

  // exibe mensagem confirmando que os dados foram alterados
  printf("Dados do Meio atualizados com sucesso.\n");
}

void alterarDadosGestor(Gestor *inicio) {
  // solicita ao usuário que digite os novos dados do cliente
  printf("Digite o nome de utilizador do gestor: ");
  fgets(inicio->nome_utilizador, 50, stdin);
  inicio->nome_utilizador[strcspn(inicio->nome_utilizador, "\n")] = 0; // remove o caractere de nova linha

  printf("Digite a password do gestor: ");
  fgets(inicio->password, 20, stdin);
  inicio->password[strcspn(inicio->password, "\n")] = 0; // remove o caractere de nova linha

  printf("Digite o nome do gestor: ");
  fgets(inicio->nome, 20, stdin);
  inicio->nome[strcspn(inicio->nome, "\n")] = 0; // remove o caractere de nova linha

  printf("Digite o email do gestor: ");
  fgets(inicio->email, 20, stdin);
  inicio->email[strcspn(inicio->email, "\n")] = 0; // remove o caractere de nova linha

  // exibe mensagem confirmando que os dados foram alterados
  printf("Dados do gestor atualizados com sucesso.\n");
}


void ordenarMeiosPorAutonomia(Meio* inicio, int n) {
    int i, j;
    Meio temp;

    // Aplicando o algoritmo de ordenação bubble sort
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (inicio[j].autonomia < inicio[j+1].autonomia) {
                // Troca os elementos
                temp = inicio[j];
                inicio[j] = inicio[j+1];
                inicio[j+1] = temp;
            }
        }
    }
}
