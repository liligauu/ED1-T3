#ifndef HASH_H
#define HASH_H  

typedef struct {
    int chave;
    int valor;
    int ocupado; // 0 = vazio, 1 = ocupado, -1 = removido
} Item;

typedef struct {
    int tamanho;   // Tamanho da tabela (sempre um número primo)
    Item* tabela;  // Vetor de itens
} TabelaHash;

TabelaHash* criarTabela(int tamanhoDesejado);
int ehPrimo(int n);
int proximoPrimo(int n);
int poshash(int chave, int tamanho);
void inserir(TabelaHash* hash, int chave, int valor);
void buscar(TabelaHash* hash, int chave, int valor);
void remover(TabelaHash* hash, int chave);
void liberarTabela(TabelaHash* hash);
void exibirTabela(TabelaHash* hash);

#endif