/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */

class CFilaInteiros;

class CNoFila{
    int dados;
    CNoFila *proximo;
    friend class CFilaInteiros; // esta classe acede aos membros private
};

class CFilaInteiros {
    CNoFila *inicio; // ponteiro para o início da Fila
    CNoFila *fim; // ponteiro para o fim da Fila
    
    public:
        CFilaInteiros(void);
        ~CFilaInteiros(void);
        CNoFila* penultimo(void) const;
        void passaPrimeiroParaPenultimo(void);
};

CFilaInteiros::CFilaInteiros() {
    inicio = nullptr;
    fim = nullptr;
}

CFilaInteiros::~CFilaInteiros (){
    CNoFila *seguinte;
    
    while (inicio != nullptr){
        seguinte = inicio->proximo;
        delete inicio;
        inicio = seguinte;
    }
    fim = nullptr;
}

CNoFila* CFilaInteiros::penultimo(void) const {
    if (inicio == nullptr || inicio == fim) {
        return nullptr; // menos de 2 elementos
    }

    CNoFila* atual = inicio;

    // Percorre até o nó anterior ao último (fim)
    while (atual->proximo != fim) {
        atual = atual->proximo;
    }

    return atual;
}

void CFilaInteiros::passaPrimeiroParaPenultimo(void) {
    // Se a fila tiver menos de 3 elementos, não faz nada
    if (inicio == nullptr || inicio->proximo == nullptr || inicio->proximo->proximo == nullptr) {
        return;
    }

    // Chama o método penultimo()
    CNoFila* pen = penultimo();

    if (pen == nullptr) return; // segurança adicional

    // Guarda o primeiro nó e avança o início da fila
    CNoFila* primeiro = inicio;
    inicio = inicio->proximo;

    // Insere o primeiro nó depois do penúltimo
    primeiro->proximo = pen->proximo;
    pen->proximo = primeiro;
}


int main(){}
