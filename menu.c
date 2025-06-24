#include "hash.h"
#include "main.h"

void menu(){
    int opcao;

    system("clear"); // Limpa a tela
    printf("Bem-vindo ao Gerenciador de Tabela Hash!\n");
    printf("Digite o tamanho desejado da tabela hash: ");
    int tamanhoDesejado;
    setbuf(stdin, NULL); // Limpar o buffer de entrada
    scanf("%d", &tamanhoDesejado);

    TabelaHash* hash = criarTabela(tamanhoDesejado);

    do{
        int chave, valor;

        printf("Menu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Exibir tabela\n");
        printf("5. Limpar tabela\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        setbuf(stdin, NULL); // Limpar o buffer de entrada   
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                system("clear");
                printf("--------- Inserir elemento ---------\n");
                printf("Digite a chave: ");
                setbuf(stdin, NULL); // Limpar o buffer de entrada
                scanf("%d", &chave);
                printf("Digite o valor: ");
                setbuf(stdin, NULL); // Limpar o buffer de entrada
                scanf("%d", &valor);
                inserir(hash, chave, valor);
                break;
            case 2:
                system("clear");
                printf("--------- Buscar elemento ---------\n");
                printf("Digite a chave: ");
                setbuf(stdin, NULL); // Limpar o buffer de entrada
                scanf("%d", &chave);
                buscar(hash, chave, valor);
                break;
            case 3:
                system("clear");
                printf("--------- Remover elemento ---------\n");
                printf("Digite a chave: ");
                setbuf(stdin, NULL); // Limpar o buffer de entrada  
                scanf("%d", &chave);
                remover(hash, chave);
                break;
            case 4:
                system("clear");
                printf("--------- Exibir tabela ---------\n");
                exibirTabela(hash);
                printf("Pressione Enter para continuar...");
                setbuf(stdin, NULL); // Limpar o buffer de entrada
                getchar();
                break;
            case 5:
                system("clear");
                printf("Liberando tabela...\n");
                liberarTabela(hash);
                hash = criarTabela(10);
                break;
            case 0:
                system("clear");
                printf("Saindo...\n");
                break;
            default:
                system("clear");
                printf("Opcao invalida! Tente novamente.\n");
        }
    }while(opcao != 0);
}