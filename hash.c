#include "hash.h"
#include "main.h" 

TabelaHash* criarTabela(int tamanhoDesejado){
    TabelaHash* hash = malloc(sizeof(TabelaHash));
    if(hash == NULL){
        printf("Erro ao alocar memoria para a tabela hash.\n");
        exit(EXIT_FAILURE);
    }

    if (tamanhoDesejado <= 0){
        printf("Tamanho da tabela deve ser maior que zero.\n");
        exit(EXIT_FAILURE);
    }
    
    hash->tamanho = proximoPrimo(tamanhoDesejado);  // Garante que o tamanho da tabela seja um número primo
    hash->tabela = malloc(hash->tamanho * sizeof(Item));    // Aloca memória para a tabela de itens
    if (hash->tabela == NULL) {
        printf("Erro ao alocar memoria para a tabela de itens.\n");
        free(hash); // Libera a memória alocada para a tabela hash
        exit(EXIT_FAILURE);
    }else{
        printf("Tabela hash criada com tamanho %d.\n", hash->tamanho);  
    }
    
    for (int i = 0; i < hash->tamanho; i++) {
        hash->tabela[i].ocupado = 0; // Marca todos os itens como vazios
    }

    return hash;
}

int ehPrimo(int n){
    if (n <= 1) return 0; // Números menores ou iguais a 1 não são primos
    if (n == 2) return 1; // 2 é o único número primo par
    if (n % 2 == 0) return 0; // Números pares maiores que 2 não são primos
    for (int i = 3; i * i <= n; i += 2){
        if (n % i == 0){
            return 0; // Se n é divisível por i, então não é primo
        }
    } // Verifica apenas números ímpares
    return 1; // Se não encontrou divisores e nem retornou nada em cima, então n é primo
}

int proximoPrimo(int n){ // Função para encontrar o próximo número primo maior ou igual a n
    while (!ehPrimo(n)){
        n++; // Incrementa n até encontrar um número primo
    };
        
    return n; // Retorna o próximo número primo encontrado
}

int poshash(int chave, int tamanho){ // Função de hash simples que calcula o índice baseado na chave e no tamanho da tabela
    if (tamanho <= 0) {
        printf("Tamanho da tabela deve ser maior que zero.\n");
        exit(EXIT_FAILURE);
    }
    return chave % tamanho; // Retorna o índice da tabela onde a chave deve ser armazenada
}

void inserir(TabelaHash* hash, int chave, int valor){

    for (int i = 0; i < hash->tamanho; i++){
        if(hash->tabela[i].ocupado == 1 && hash->tabela[i].chave == chave){
            printf("Chave %d ja existe na tabela, nao foi possivel inserir.\n", chave);
            return; // Se a chave já existe, não insere novamente
        } 
    }

    int posicao = poshash(chave, hash->tamanho);

    for (int i = 0; i < hash->tamanho; i++) {
        int indice = (posicao + i) % hash->tamanho; // Calcula o índice com tratamento de colisões usando sondagem linear

        if(hash->tabela[indice].ocupado == 0 || hash->tabela[indice].ocupado == -1){
            hash->tabela[indice].chave = chave;
            hash->tabela[indice].valor = valor;
            hash->tabela[indice].ocupado = 1;
            printf("Elemento inserido com sucesso: chave = %d, valor = %d.\n", chave, valor);
            return;
        }
    }

    printf("Tabela cheia, nao foi possivel inserir o elemento.\n");
    return;
}

void buscar(TabelaHash* hash, int chave, int valor){
    int posicao = poshash(chave, hash->tamanho);

    for (int i = 0; i < hash->tamanho; i++){
        int indice = (posicao + i) % hash->tamanho;

        if (hash->tabela[indice].ocupado == 1 && hash->tabela[indice].chave == chave){
            valor = hash->tabela[indice].valor; // Atribui o valor encontrado ao ponteiro passado
            printf("Chave %d encontrada com valor %d.\n", chave, valor);
            return;
        }
    }

    printf("Chave %d nao encontrada.\n", chave);
    return;
}

void remover(TabelaHash* hash, int chave){
    int posicao = poshash(chave, hash->tamanho);

    for (int i = 0; i < hash->tamanho; i++) {
        int indice = (posicao + i) % hash->tamanho;

        if (hash->tabela[indice].ocupado == 1 && hash->tabela[indice].chave == chave){
            hash->tabela[indice].ocupado = -1; // Marca como removido
            printf("Chave %d removida com sucesso.\n", chave);
            return;
        }
    }

    printf("Chave %d nao encontrada.\n", chave);
    return;
}

void liberarTabela(TabelaHash* hash){
    if(hash == NULL) {
        printf("Tabela hash ja esta vazia ou nao foi criada.\n");
        return;
    }
    free(hash->tabela);
    free(hash);
    printf("Tabela hash liberada da memoria.\n");
    hash = NULL;
    return;
}

void exibirTabela(TabelaHash* hash) {
    printf("Tabela Hash:\n");
    for (int i = 0; i < hash->tamanho; i++) {
        if (hash->tabela[i].ocupado == 1) {
            printf("Posição %d: Chave = %d, Valor = %d\n", i, hash->tabela[i].chave, hash->tabela[i].valor);
        } else if (hash->tabela[i].ocupado == -1) {
            printf("Posição %d: Removido\n", i);
        } else {
            printf("Posição %d: Vazio\n", i);
        }
    }
}