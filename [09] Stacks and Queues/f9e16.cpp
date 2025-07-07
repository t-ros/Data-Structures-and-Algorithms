/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */
 
 // Enunciado
class CNoFila { // Nó da Fila
    public:
        char pais[50];
        int ranking; // valor mais baixo indica um país mais desenvolvido
        CNoFila *proximo; // proximo nó;
};

class CFilaRankings { // Fila contendo países ordenados pelo seu ranking
    CNoFila *inicio;
    CNoFila *fim;
    
    public:
        CFilaRankings() { inicio=nullptr; fim=nullptr; }
        ~CFilaRankings();
        void InserePais(char *Pais, int Rating);
};

CFilaRankings::~CFilaRankings(){
    CNoFila *seguinte;
    
    while(inicio != nullptr) {
        seguinte = inicio->proximo;
        delete inicio;
        inicio = seguinte;
    }
    fim = nullptr;
}

void CFilaRankings::InserePais(char *Pais, int Rating){
    CNoFila *novo = new CNoFila;
    novo->ranking = Rating;
    novo->proximo = nullptr;
    
    if (inicio == nullptr || Rating < inicio -> ranking) { 
        novo->proximo = inicio;
        inicio = novo; 
        if (fim == nullptr) fim = novo;
        return;
    }
    
    CNoFila* atual = inicio;
    while (atual->proximo != nullptr && atual->proximo->ranking <= Rating) {
        atual = atual->proximo;
    }
    
    novo->proximo = atual->proximo;
    atual->proximo = novo;
    
    if(novo->proximo == nullptr) fim = novo;
}

int main(){}

