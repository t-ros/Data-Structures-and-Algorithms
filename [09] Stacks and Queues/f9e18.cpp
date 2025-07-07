/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */
 
class CNoPilha{
    int dados;
    CNoPilha *proximo;
    friend class CPilhaInteiros; // esta classe acede aos membros private
};

class CPilhaInteiros{
    CNoPilha *topo; // ponteiro para o elemento no topo da pilha
    
    private:
        CNoPilha* ponteiroPara(int i) const;
        
    public:
        CPilhaInteiros(void);
        ~CPilhaInteiros(void);
        CPilhaInteiros& operator << (int i);
        void push(const int item);
        bool pop(int &item);
        void escrevePilha(void) const;
        bool pilhaVazia() const { return (topo==nullptr);}
};
// a) Devolve o ponteiro para o nó de índice i (topo = índice 0)
 CNoPilha* CPilhaInteiros::ponteiroPara(int i) const{
    if (i < 0) return nullptr;
    
    CNoPilha *atual = topo;
    int contador = 0;
    
    while (atual != nullptr && contador < i) {
        atual = atual->proximo;
        contador++;
    }
    return atual;
}
// b) Remove todos os nós da pilha a partir do índice i (inclusive)
CPilhaInteiros& CPilhaInteiros::operator << (int i) {
    if (i < 0) return *this;
    
    if (i == 0) {
        while (topo != nullptr) {
            CNoPilha* apagar = topo;
            topo = topo->proximo;
            delete apagar;
        }
        return *this;
    }
    
    // obter nó anterior ao indice i
    CNoPilha* anterior = ponteiroPara(i-1);
    if (anterior == nullptr || anterior->proximo == nullptr)
        return *this;
    // Apagar todos os nós a partir do i
    CNoPilha* atual = anterior->proximo;
    anterior->proximo = nullptr;
    
    while (atual != nullptr) {
        CNoPilha* apagar = atual;
        atual = atual->proximo;
        delete apagar;
    }
    return *this;
}

int main(){}
