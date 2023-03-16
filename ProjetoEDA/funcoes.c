#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "registos.h"

Cliente* inserirCliente(Cliente* inicio, char nome_utilizador[], char password[], char nome[], char email[], char endereco[])
{
    if (!existeCliente(inicio, nome_utilizador))
    {
        Cliente* novo = malloc(sizeof(struct registo_cliente));
        if (novo != NULL)
        {
            strcpy(novo->nome_utilizador, nome_utilizador);
            strcpy(novo->password, password);
            strcpy(novo->nome, nome);
            strcpy(novo->email, email);
            strcpy(novo->endereco, endereco);
            novo->seguinte = inicio;
            return(novo);
        }
    }
    else
    {
        return(inicio);
    }
}


int existeCliente(Cliente* inicio, char nome_utilizador[])
{while(inicio!=NULL)
  {if (inicio->nome_utilizador) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}

Gestor* inserirGestor(Gestor* inicio, char nome_utilizador[], char password[], char nome[], char email[])
{
    if (!existeGestor(inicio, nome_utilizador))
    {
        Gestor* novo = malloc(sizeof(struct registo_gestor));
        if (novo != NULL)
        {
            strcpy(novo->nome_utilizador, nome_utilizador);
            strcpy(novo->password, password);
            strcpy(novo->nome, nome);
            strcpy(novo->email, email);
    
            novo->seguinte = inicio;
            return(novo);
        }
    }
    else
    {
        return(inicio);
    }
}


int existeGestor(Gestor* inicio, char nome_utilizador[])
{while(inicio!=NULL)
  {if (inicio->nome_utilizador) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}

Meio* inserirMeio(Meio* inicio, char nome_meio[], char tipo[], float preco, int disponivel, int quantidade)
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
 Meio *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->nome_meio) // remoção do 1º registo
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->nome_meio)) 
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
 {printf("%s %s \n",inicio->nome_meio,inicio->tipo,inicio->preco,inicio->disponivel,inicio->quantidade);
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

    int index = -1;
    for (int i = 0; i < quantidade; i++) {
        if (inicio[i].nome_meio) {
            index = i;
            break;
        }
    }

if (index == -1) {
        printf("Meio nao encontrado!\n");
        return;
    }
    if (!inicio[index].disponivel) {
        printf("Meio indisponivel!\n");
        return;
    }


    if (*saldo < inicio[index].preco) {
        printf("Saldo insuficiente!\n");
        return;
    }

}
void verMeiosDisponiveis(Meio *inicio, int quantidade) {
    printf("ID\tPREÇO\tDISPONIVEL\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%s\t%.2f\t%d\n", inicio[i].nome_meio, inicio[i].preco, inicio[i].disponivel ? "Sim" : "Não");
    }
}

int guardarMeios(Meio* inicio)
{FILE* fp;
 fp = fopen("meios.txt","w");
 if (fp!=NULL)
 {
 Meio* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"Nome do meio: %s;\n Tipo do meio: %s;\n Preco do meio por hora: %f;\n Disponibilidade do meio: %s;\n Quantidade: %d \n", aux->nome_meio, aux->tipo, aux->preco,aux->disponivel, aux->quantidade);
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
  fprintf(fp,"Nome de utilizador: %s; Password: %s; Nome: %s; Email: %s; Endereco: %s;\n", aux->nome_utilizador, aux->password, aux->nome,aux->email, aux->endereco);
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
  fprintf(fp,"Nome de utilizador: %s; Password: %s; Nome: %s; Email: %s;", aux->nome_utilizador, aux->password, aux->nome,aux->email);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}
