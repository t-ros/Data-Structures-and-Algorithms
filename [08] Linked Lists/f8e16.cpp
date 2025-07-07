/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */
 
// Definição do nó da lista
struct CNoLista {
    int valor;
    CNoLista* proximo;
};

// Definição da classe da lista de inteiros
class CListaInteiros {
    private:
        CNoLista* cabeca;

    public:
        // Construtor: cria a lista com valores entre a e b (inclusive)
        CListaInteiros(int a, int b);
        bool temNumeroImpar(void);
        CListaInteiros& operator*=(const CListaInteiros &outra);
};
// a) Colocar por ordem crescente
CListaInteiros::CListaInteiros(int a, int b) {
        cabeca = nullptr;

        int inicio = (a < b) ? a : b;
        int fim = (a > b) ? a : b;

        for (int i = fim; i >= inicio; i--) {
            CNoLista* novo = new CNoLista;
            novo->valor = i;
            novo->proximo = cabeca;
            cabeca = novo;
        }
}
// b) Verifica se a quantidade de elementos é par
bool CListaInteiros::temNumeroImpar(void){
    CNoLista *atual = cabeca;
    int contador = 0;
    
    while (atual != nullptr) {
        contador ++;
        atual=atual->proximo;
        }
    return (contador %2 == 0);
}
// c) Implementação do operador *=
CListaInteiros& CListaInteiros::operator*=(const CListaInteiros &outra){
     if (cabeca == nullptr) return *this; // (*this) Se a lista está vazia (sem elementos), não faz nada, apenas devolve o próprio objeto.
    CNoLista *atual = cabeca;
    CNoLista *atualOutra = outra.cabeca;
    
    while (atual != nullptr && atualOutra != nullptr){
        atual->valor *= atualOutra->valor;
        atual = atual->proximo;
        atualOutra = atualOutra->proximo;
    }
    return *this; // (*this) Se a lista está vazia (sem elementos), não faz nada, apenas devolve o próprio objeto.
}

int main(){}

