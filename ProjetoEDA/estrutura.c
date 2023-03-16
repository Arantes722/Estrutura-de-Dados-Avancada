#include <stdio.h>
#include <string.h>
#include "registos.h"


int main() {

    Cliente* clientes = NULL;
    Gestor* gestores = NULL;
    Meio* meios = NULL;
    char nome_meio[50];
    char tipo[50];
    char nome_utilizador[20];
    char password[20];
    int user_tipo; 
    char nome[50];
    char email[50];
    char endereco[100];
    int idade;
    float saldo;
    float preco;
    char id[50];
    int disponivel;
    int quantidade;
    int nMeios;

    Meio meioss[3] = {
        {1, 5.0, 1},
        {2, 7.5, 1},
        {3, 10.0, 0}
    };


    Cliente cliente = {"cliente1", "123", 0};
    Gestor gestor = {"gestor", "123", 1};

    int opcao;
    do {
        printf("------BEM-VINDO AO MENU------\n");
        printf("1 - Login\n");
        printf("2 - Registar\n");
        printf("0 - Sair\n");
        printf("\n");
        printf("Selecione a opcao:\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            printf("--------------------------- \n");
                printf("Insira o nome de utilizador:\n");
                scanf("%s", &nome_utilizador);
                printf("Insira a palavra passe:\n");
                scanf("%s", &password);

                if (strcmp(nome_utilizador, cliente.nome_utilizador) == 0 && strcmp(password, cliente.password) == 0) {
                printf("--------------------------- \n");
                printf("Bem-vindo, cliente!\n");

                while (opcao != 0) {
                                    printf("\nEscolha uma opcao:\n");
                                    printf("1 - Alugar meio\n");
                                    printf("2 - Ver meios disponiveis\n");
                                    printf("3 - Ver saldo\n");
                                    printf("4 - Carregar saldo\n");
                                    printf("0 - Sair\n");
                                    
                                    scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                alugarMeio(meioss, quantidade, &saldo);
                break;
            case 2:
                verMeiosDisponiveis(meios, quantidade);
                break;
            case 3:
                verSaldo(saldo);
                break;
            case 4:
                carregarSaldo(&saldo);
                break;
        }
                }
                // código para o menu do cliente
                } else if (strcmp(nome_utilizador, gestor.nome_utilizador) == 0 && strcmp(password, gestor.password) == 0) {
                printf("--------------------------- \n");
                printf("Bem-vindo, gestor!\n");
                 // código para o menu do administrador

                                do {
                    printf("\n");                
                    printf("Escolha uma opcao:\n");
                    printf("1. Insercao de novos dados\n");
                    printf("2. Remocao de dados\n");
                    printf("3. Alteracao de dados\n");
                    printf("4. Registo do aluguer de um determinado meio de mobilidade\n");
                    printf("5. Listagem dos meios de mobilidade eletrica por ordem decrescente de autonomia\n");
                    printf("6. Listagem dos meios de mobilidade eletrica existentes numa localizacao\n");
                    printf("0. Sair\n");
                    printf("--------------------------- \n");

                    scanf("%d", &opcao);

                    switch (opcao) {
                        case 1:
                            do {
                                printf("1. Inserir novo cliente\n");
                                printf("2. Inserir novo gestor\n");
                                printf("3. Inserir novo meio de mobilidade eletrica\n");
                                printf("4. Guardar dados inseridos\n");
                                printf("5. Sair\n");
                                printf("Selecione uma opcao: ");

                                scanf("%d", &opcao);

                                switch (opcao) {
                                                case 1:
                                                        printf("Insira o nome de utilizador: \n");
                                                        scanf("%s",&nome_utilizador);
                                                        printf("Insira a password: \n");
                                                        scanf("%s",&password);
                                                        printf("Insira o nome: \n");
                                                        scanf("%s",&nome);
                                                        printf("Insira o email: \n");
                                                        scanf("%s",&email);
                                                        printf("Insira o endereco: \n");
                                                        scanf("%s",&endereco);
                                                        printf("Cliente registado com sucesso! \n");
                                                     
                                                        clientes = inserirCliente(clientes,nome_utilizador,password,nome,email,endereco);

                                                        break;
                                                case 2:
                                                        printf("Insira o nome de utilizador: \n");
                                                        scanf("%s",&nome_utilizador);
                                                        printf("Insira a password: \n");
                                                        scanf("%s",&password);
                                                        printf("Insira o nome: \n");
                                                        scanf("%s",&nome);
                                                        printf("Insira o email: \n");
                                                        scanf("%s",&email);


                                                        printf("Gestor registado com sucesso! \n");

                                                        gestores = inserirGestor(gestores,nome_utilizador,password,nome,email);

                                                        break;
                                                case 3:
                                                        printf("Insira o nome do meio: \n");
                                                        scanf("%s",&nome_meio);
                                                        printf("Insira o tipo de meio: \n");
                                                        scanf("%s",&tipo);
                                                        printf("Insira o preco do meio por hora: \n");
                                                        scanf("%.2f",&preco);
                                                        printf("Insira a quantidade de meios destes a adicionar: \n");
                                                        scanf("%d",&quantidade);
                                                        printf("Insira a disponibilidade do meio: \n");
                                                        scanf("%d",&disponivel);

                                                        printf("Meio registado com sucesso! \n");

                                                        meios = inserirMeio(meios,nome_meio,tipo,preco,quantidade,disponivel);

                                                        break;

                                                case 4:
                                                guardarClientes(clientes);
                                                guardarMeios(meios);
                                                guardarGestores(gestores);
                                                break;

                
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 4);

                            break;
                        case 2:
                            // Remover dados
                            do {
                                printf("1. Remover cliente\n");
                                printf("2. Remover gestor\n");
                                printf("3. Remover meio de mobilidade eletrica\n");
                                printf("4. Sair\n");
                                printf("Selecione uma opcao: ");

                                scanf("%d", &opcao);

                                switch (opcao) {
                                                case 1:
                                                        printf("Nome do cliente a remover?\n");
                                                        scanf("%s",&nome_utilizador);
                                                        clientes = removerCliente(clientes, nome_utilizador);
                                                    
                                                        break;
                                                case 2:
                                                        printf("Nome do gestor a remover?\n");
                                                        scanf("%s",&nome_utilizador);
                                                        gestores = removerGestor(gestores, nome_utilizador);
                                                    
                                                        break;
                                                case 3:
                                                        printf("Nome do meio de mobilidade a remover?\n");
                                                        scanf("%s",&nome_meio);
                                                        meios = removerMeio(meios, nome_meio);
                                                    
                                                        break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }

    } while (opcao != 4);

                            break;
                        case 3:
                            // Alterar dados
                            do {
                                printf("1. Alterar dados do cliente\n");
                                printf("2. Alterar dados do gestor\n");
                                printf("3. Alterar dados do meio de mobilidade eletrica\n");
                                printf("4. Sair\n");
                                printf("Selecione uma opcao: ");

                                scanf("%d", &opcao);

                                switch (opcao) {
                                                case 1:
                                                        
                                                        break;
                                                case 2:
                                                    
                                                        break;
                                                case 3:
                
                                                        break;
                                                case 4:
                                                    printf("Saindo...\n");
                                                    break;
                                                default:
                                                    printf("Opção inválida! Tente novamente.\n");
                                                    break;
                                            }

                                } while (opcao != 4);

                            break;
                        case 4:
                            // Registrar aluguer
                            printf("Opcao 4 selecionada.\n");
                            break;
                        case 5:
                            listarMeios(meios);
                            break;
                        case 6:
                            // Listar meios de mobilidade elétrica em uma localização
                            printf("Opcao 6 selecionada.\n");
                            break;
                        case 0:
                            // Sair
                            printf("Saindo...\n");
                            break;
                        default:
                            printf("Opcao inválida.\n");
        }

    } while (opcao != 0);

                } else {
                printf("Usuário ou senha inválidos.\n");
                // código para lidar com a falha de autenticação
    }

    

                break;
                                                case 2:
                                                        printf("Insira o nome de utilizador: \n");
                                                        scanf("%s",&nome_utilizador);
                                                        printf("Insira a password: \n");
                                                        scanf("%s",&password);
                                                        printf("Insira o nome: \n");
                                                        scanf("%s",&nome);
                                                        printf("Insira o email: \n");
                                                        scanf("%s",&email);
                                                        printf("Insira o endereco: \n");
                                                        scanf("%s",&endereco);
                                                        printf("Cliente registado com sucesso! \n");
                                                     
                                                        clientes = inserirCliente(clientes,nome_utilizador,password,nome,email,endereco); 

                                                        break;
            case 0:
                printf("A sair do programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}



