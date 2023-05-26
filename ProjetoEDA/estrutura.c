#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registos.h"


int main() {

    Cliente* clientes = NULL; //cria um ponteiro chamado "clientes" que aponta para um objeto do tipo "Cliente", e o inicializa com o valor NULL.
    Gestor* gestores = NULL; // cria um ponteiro chamado "gestores" que aponta para um objeto do tipo "Gestor", e o inicializa com o valor NULL.
    Meio* meios = NULL; // cria um ponteiro chamado "meios" que aponta para um objeto do tipo "Meio", e o inicializa com o valor NULL.
    Grafo g = NULL;
    char nome_meio[50], nome_utilizador[50], password[20], nome[50], email[50], endereco[100],geolocalizacao[50];
    int idade,preco,autonomia,id;
    float saldo;

    Cliente cliente = {"cliente1", "123", 0};
    Gestor gestor = {"gestor", "123", 1};




    int opcao;
    int sair=0;

    while(!sair) {
        printf(" ___________________\n");
        printf("| BEM-VINDO AO MENU |\n");
        printf("|                   |\n");
        printf("| 1 - Login         |\n");
        printf("| 2 - Registar      |\n");
        printf("| 0 - Sair          |\n");
        printf("|___________________|\n");
        printf("\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) { // verifica a opção selecionada pelo usuário
            case 1: // se for 1, executa o código abaixo
            printf("--------------------------- \n");
                printf("Insira o nome de utilizador: "); // solicita o nome do usuário
                scanf("%s", &nome_utilizador); // lê o nome do usuário da entrada padrão
                printf("Insira a palavra passe: "); // solicita a senha do usuário
                scanf("%s", &password); // lê a senha do usuário da entrada padrão

                 // verifica se o nome de usuário e a senha correspondem aos de um cliente
                if (strcmp(nome_utilizador, cliente.nome_utilizador) == 0 && strcmp(password, cliente.password) == 0) {
                printf("--------------------------- \n");
                printf("Bem-vindo, cliente!\n"); // imprime uma mensagem de boas-vindas para o cliente

                // apresenta um menu de opções enquanto o usuário não selecionar a opção "0"
                while (opcao != 0) {
                                    
                                    printf("\n");
                                    printf("1 - Alugar meio\n"); // oferece a opção de alugar um meio de transporte 
                                    printf("2 - Ver saldo\n"); // oferece a opção de verificar o saldo do cliente
                                    printf("3 - Carregar saldo\n"); // oferece a opção de carregar o saldo do cliente
                                    printf("4 - Ver historico de alugueis\n");
                                    printf("0 - Sair\n");// oferece a opção de sair do programa
                                    printf("\n");
                                    printf("Selecione uma opcao: ");
                                    
                                    scanf("%d", &opcao); // lê a opção selecionada pelo usuário da entrada padrão
        
        switch (opcao) {// início da seleção da opção escolhida pelo usuário
            case 1:// caso a opção escolhida seja 1
                                meios = lerMeios();
                                clientes = lerClientes();
                                gestores = lerGestores();
                alugarMeio(meios, &saldo);// chama a função alugarMeio, passando o array de meios, a quantidade de meios e o saldo como parâmetros
                break;// interrompe o switch
            case 2:// caso a opção escolhida seja 2
                verSaldo(saldo);// chama a função verSaldo, passando o saldo como parâmetro
                break;// interrompe o switch
            case 3:// caso a opção escolhida seja 3
                carregarSaldo(&saldo);// chama a função carregarSaldo, passando o endereço do saldo como parâmetro
                break;// interrompe o switch
                case 4: {
                Cliente* cliente = malloc(sizeof(Cliente));
                verHistoricoAlugueres(cliente);
                break;
                }
        }
                }
                // verifica se o nome de usuário e a senha correspondem aos de um gestor
                } else if (strcmp(nome_utilizador, gestor.nome_utilizador) == 0 && strcmp(password, gestor.password) == 0) {

                printf("--------------------------- \n");
                printf("Bem-vindo, gestor!\n"); // imprime uma mensagem de boas-vindas para o cliente
                                do {
                       /*             
                    meios = lerMeios();
                    clientes = lerClientes();
                    gestores = lerGestores();
                    */
while (opcao != 0) {          
                                        
                    printf("\n");                
                    printf("1. Insercao de novos dados\n"); // oferece a opção de inserir novos dados
                    printf("2. Remocao de dados\n"); // oferece a opção de remover dados
                    printf("3. Alteracao de dados\n"); // oferece a opção de alterar dados
                    printf("4. Listagem dos meios de mobilidade eletrica existentes numa localizacao\n"); // oferece a opção de listar os meios de transporte eletrônicos disponíveis em uma determinada localização
                    printf("5. Localizacao dos clientes e meios de mobilidade eletrica\n");
                    printf("6. Listagem dos clientes\n");
                    printf("7. Listagem dos meios\n");
                    printf("8. Listagem dos gestores\n");
                    printf("0. Sair\n"); // oferece a opção de sair do programa
                    printf("\n");
                    printf("Seleciona uma opcao: ");
                    scanf("%d", &opcao); // lê a opção selecionada pelo usuário da entrada padrão

                                                                    meios = lerMeios();
                    clientes = lerClientes();
                    gestores = lerGestores(); 


                    switch (opcao) {
                        case 1: // se a opção selecionada for 1

                                printf("\n");
                                printf("1. Inserir novo cliente\n"); // oferece a opção de inserir um novo cliente
                                printf("2. Inserir novo gestor\n"); // oferece a opção de inserir um novo gestor
                                printf("3. Inserir novo meio de mobilidade eletrica\n"); // oferece a opção de inserir um novo meio de transporte eletrônico
                                printf("0. Sair\n\n"); // oferece a opção de sair do submenu
                                printf("Selecione uma opcao: ");


                                scanf("%d", &opcao); // lê a opção selecionada pelo usuário da entrada padrão

                                switch (opcao) { //indica o início de um switch/case para a variável opcao.
                                                case 1: // inicia o primeiro caso em que o valor de opcao é 1.
                                                printf("\n");
                                                        printf("Insira o nome de utilizador: "); //exibe a mensagem para o usuário inserir o nome de utilizador.
                                                        scanf("%s",&nome_utilizador); //lê o valor inserido pelo usuário e armazena na variável nome_utilizador.
                                                        printf("Insira a password: "); //exibe a mensagem para o usuário inserir a senha.
                                                        scanf("%s",&password); //lê o valor inserido pelo usuário e armazena na variável password.
                                                        printf("Insira o nome: "); //exibe a mensagem para o usuário inserir o nome.
                                                        scanf("%s",&nome); //lê o valor inserido pelo usuário e armazena na variável nome.
                                                        printf("Insira o email: "); //exibe a mensagem para o usuário inserir o e-mail.
                                                        scanf("%s",&email); //lê o valor inserido pelo usuário e armazena na variável email.
                                                        printf("Insira o endereco: "); //exibe a mensagem para o usuário inserir o endereço.
                                                        scanf("%s",&endereco); //lê o valor inserido pelo usuário e armazena na variável endereco.
                                                        printf("\n");
                                                        printf("Cliente registado com sucesso! \n"); //exibe a mensagem de sucesso.
                                                     
                                                        clientes = inserirCliente(clientes,nome_utilizador,password,nome,email,endereco); //chama a função inserirCliente para inserir um novo cliente na lista de clientes.
                                                        guardarClientes(clientes);
                                                        guardarClientesBin(clientes);
                                                        break; //indica que o caso foi finalizado.
                                                case 2: //início do segundo caso do switch
                                                printf("\n");
                                                        printf("Insira o nome de utilizador: "); //solicita ao usuário que insira o nome de utilizador do gestor
                                                        scanf("%s",&nome_utilizador); //lê o nome de utilizador inserido pelo usuário
                                                        printf("Insira a password: "); //solicita ao usuário que insira a password do gestor
                                                        scanf("%s",&password); //lê a password inserida pelo usuário
                                                        printf("Insira o nome: "); //solicita ao usuário que insira o nome do gestor
                                                        scanf("%s",&nome); // lê o nome inserido pelo usuário
                                                        printf("Insira o email: "); //solicita ao usuário que insira o email do gestor
                                                        scanf("%s",&email);//lê o email inserido pelo usuário
                                                        printf("\n");
                                                        printf("Gestor registado com sucesso! \n"); //exibe uma mensagem informando que o gestor foi registrado com sucesso

                                                        gestores = inserirGestor(gestores,nome_utilizador,password,nome,email); //chama a função "inserirGestor" para inserir o gestor na lista de gestores
                                                        guardarGestores(gestores);
                                                        guardarGestoresBin(gestores);
                                                        break; //encerra o segundo caso do switch.
                                                case 3:
                                                printf("\n");
                                                        printf("Insira o ID do meio: ");
                                                        scanf("%d",&id);
                                                        printf("Insira o nome do meio: "); // pede ao utilizador para inserir o nome do meio
                                                        scanf("%s",&nome_meio); // lê o nome do meio inserido pelo utilizador
                                                        printf("Insira o preco do meio por hora: "); // pede ao utilizador para inserir o preço do meio por hora
                                                        scanf("%d",&preco); // lê o preço do meio por hora inserido pelo utilizador
                                                        printf("Insira a autonomia do meio: "); // pede ao utilizador para inserir a autonomia do meio
                                                        scanf("%d",&autonomia); // lê a autonomia do meio inserida pelo utilizador
                                                        printf("Insira a geolocalizacao do meio: ");
                                                        scanf("%s",&geolocalizacao);
                                                        printf("\n");
                                                        printf("Meio registado com sucesso! \n"); // informa o utilizador que o meio foi registado com sucesso

                                                        
                                                        meios = inserirMeio(meios,id,nome_meio,preco,autonomia,geolocalizacao); // insere o meio na lista de meios
                                                        guardarMeios(meios);
                                                        guardarMeiosBin(meios);
                                                        break;

                break;
            case 4:
                printf("Saindo...\n"); // oferece a opção de sair do submenu
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }



                            break;
                        case 2:
                            // Remover dados

                                printf("\n");
                                printf("1. Remover cliente\n"); //Exibe a opção de remover cliente.
                                printf("2. Remover gestor\n"); //Exibe a opção de remover gestor.
                                printf("3. Remover meio de mobilidade eletrica\n"); //Exibe a opção de remover meio de mobilidade elétrica.
                                printf("0. Sair\n"); //Exibe a opção de sair do menu de remoção de dados.
                                printf("\n");
                                printf("Selecione uma opcao: "); //Solicita ao usuário que selecione uma opção do menu.

                                scanf("%d", &opcao); //Recebe a opção selecionada pelo usuário.

                                switch (opcao) { //Inicia um switch case para tratar a opção selecionada.
                                                case 1: printf("\n");//Caso a opção seja "1", o usuário é solicitado a inserir o nome do cliente que deseja remover e a função "removerCliente" é chamada passando como parâmetro a lista de clientes e o nome do cliente a ser removido. Em seguida, exibe uma mensagem informando que o cliente foi removido com sucesso.
                                                        printf("Nome do cliente a remover: ");
                                                        scanf("%s",&nome_utilizador);
                                                        clientes = removerCliente(clientes, nome_utilizador);
                                                        printf("Cliente removido com sucesso!\n");
                                                    
                                                        break;
                                                case 2: printf("\n");//Caso a opção seja "2", o usuário é solicitado a inserir o nome do gestor que deseja remover e a função "removerGestor" é chamada passando como parâmetro a lista de gestores e o nome do gestor a ser removido. Em seguida, exibe uma mensagem informando que o gestor foi removido com sucesso.
                                                        printf("Nome do gestor a remover: ");
                                                        scanf("%s",&nome_utilizador);
                                                        gestores = removerGestor(gestores, nome_utilizador);

                                                        printf("Gestor removido com sucesso!\n");
                                                    
                                                        break;
                                                case 3: printf("\n");//Caso a opção seja "3", o usuário é solicitado a inserir o nome do meio de mobilidade elétrica que deseja remover e a função "removerMeio" é chamada passando como parâmetro a lista de meios e o nome do meio a ser removido. Em seguida, exibe uma mensagem informando que o meio foi removido com sucesso.
                                                
                                                        printf("ID do meio de mobilidade a remover: ");
                                                        scanf("%d",&id);
                                                        meios = removerMeio(meios, id);

                                                        printf("Meio removido com sucesso!\n");
                                                    
                                                        break;
            case 4: //Caso a opção seja "4", a mensagem "Saindo..." é exibida e o menu de remoção de dados é finalizado.
                printf("Saindo...\n");
                break;
            default: //Caso a opção selecionada pelo usuário não seja nenhuma das opções válidas, exibe a mensagem "Opção inválida! Tente novamente." e o menu é apresentado novamente até que o usuário selecione uma opção válida (com exceção da opção "4" que finaliza o menu). O laço do-while na linha 23 é responsável por manter o menu ativo enquanto o usuário não selecionar a opção "4".
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }



                            break;
                        case 3:
                            // Alterar dados
                            
                                printf("\n");
                                printf("1. Alterar dados do cliente\n");
                                printf("2. Alterar dados do gestor\n");
                                printf("3. Alterar dados do meio de mobilidade eletrica\n");
                                printf("0. Sair\n");
                                printf("\n");
                                printf("Selecione uma opcao: ");
                                scanf("%d", &opcao);

                                switch (opcao) {
                                                case 1:
                                                        printf("\n");
                                                        alterarDadosCliente(clientes);
                                                        break;
                                                case 2:
                                                        printf("\n");
                                                        alterarDadosGestor(gestores);
                                                        break;
                                                case 3:
                                                        printf("\n");
                                                        alterarDadosMeio(meios);
                                                        break;
                                                case 4:
                                                    printf("Saindo...\n");
                                                    break;
                                                default:
                                                    printf("Opcao invalida! Tente novamente.\n");
                                                    break;
                                            }

                            break;


                        case 4:
                            listarMeiosPorGeolocalizacao(meios);
                            break;
                        case 5:
                            // Listar meios de mobilidade elétrica em uma localização
                                    criarVertice(&g,"///crewcut.condense.perceive"); //0
                                    criarVertice(&g,"///deregulated.stress.oval"); //1
                                    criarVertice(&g,"///spied.contract.bounded");//2
                                    criarVertice(&g,"///slider.condors.roughness");//3
                                    
                                    criarAresta(g,"///crewcut.condense.perceive","///deregulated.stress.oval",50);
                                    criarAresta(g,"///deregulated.stress.oval","///spied.contract.bounded",200);
                                    criarAresta(g,"///spied.contract.bounded","///crewcut.condense.perceive",100);
                                    criarAresta(g,"///slider.condors.roughness","///crewcut.condense.perceive",50);


                                    inserirMeioG(g,"///crewcut.condense.perceive",111);
                                    inserirMeioG(g,"///crewcut.condense.perceive",112);
                                    inserirMeioG(g,"///crewcut.condense.perceive",113);
                                    inserirMeioG(g,"///spied.contract.bounded",200);
                                    inserirMeioG(g,"///slider.condors.roughness",300);

                                    printf("----------------\n");
                                    printf("Geolocalizacoes perto da localizacao ///crewcut.condense.perceive\n");
                                    listarAdjacentes(g,"///crewcut.condense.perceive");
                                    printf("----------------\n");
                                    printf("Geolocalizacoes perto da localizacao ///deregulated.stress.oval\n");
                                    listarAdjacentes(g,"///deregulated.stress.oval");
                                    printf("----------------\n");
                                    printf("Vertices adjacentes a ///spied.contract.bounded\n");
                                    listarAdjacentes(g,"///spied.contract.bounded");
                                    printf("----------------\n");
                                    printf("Vertices adjacentes a ///slider.condors.roughness\n");
                                    listarAdjacentes(g,"///slider.condors.roughness");
                                    printf("----------------\n");

                                    printf("Meios de transporte existentes na localizacao ///crewcut.condense.perceive\n");
                                    listarMeiosG(g,"///crewcut.condense.perceive");
                                    printf("----------------\n");
                                     printf("Meios de transporte existentes na localizacao ///deregulated.stress.oval\n");
                                    listarMeiosG(g,"///deregulated.stress.oval");
                                    printf("----------------\n");
                                    printf("Meios de transporte existentes na localizacao ///spied.contract.bounded\n");
                                    listarMeiosG(g,"///spied.contract.bounded");
                                    printf("----------------\n");
                                    printf("Meios de transporte existentes na localizacao ///slider.condors.roughness\n");
                                    listarMeiosG(g,"///slider.condors.roughness");
                                    printf("----------------\n");
                            break;
                        case 6:
                            // Listar meios de mobilidade elétrica em uma localização
                            listarClientes(clientes);
                            break;
                        case 7:
                            // Listar meios de mobilidade elétrica em uma localização
                            listarMeiosOrdem(meios);
                            break;
                        case 8:
                            // Listar meios de mobilidade elétrica em uma localização
                            listarGestores(gestores);
                            break;
                        case 0:
                            printf("Voltando ao menu de login...\n");
                            system("cls");
                            break;
                        default:
                            printf("Opcao invalida.\n");
        }

    }
                                 } while (opcao != 0);

                } else {
                printf("Username ou palavra-passe invalidos.\n");
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



