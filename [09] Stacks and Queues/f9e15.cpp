/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */

#include <iostream>
#include <cstring>

class CNoLista{
    public:
        char ref[6]; // código da pergunta máx. 5 char
        char  resposta[301]; // Máximo 300 chars por resposta
        int num; // número de vezes que a pergunta foi feita
        CNoLista *proximo;
};

class CListaHelpDesk{
    CNoLista *cabeca;
    
    public:
        CListaHelpDesk(void); // Declaração
        std::string pesquisaLista(const char* codigo);
};
// Definição fora da classe (vazia)
CListaHelpDesk::CListaHelpDesk(){
    cabeca = nullptr;
}

std::string CListaHelpDesk::pesquisaLista(const char* codigo){
    CNoLista *atual  = cabeca;
    CNoLista *anterior = nullptr;
    // Percorre a lista
    while (atual != nullptr) {
        if (strcmp(atual->ref, codigo) == 0) {
        atual->num++; // Incrementar contador
        // Se não está no inicio, move-o p/ o inicio
        if (anterior != nullptr) {
            anterior->proximo = atual->proximo;
            atual->proximo = cabeca;
            cabeca = atual;
            }
        return atual -> resposta;
        }
    anterior = atual;
    atual = atual->proximo;
    }
    return "";
}

int main(){
    return 0;
}
