/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */
 
// Enunciado:
class CNoPilha {
    public:
        double dados;
        CNoPilha *proximo;
};
// Enunciado:
class CPilha {
    CNoPilha *topo; // ponteiro para o topo da pilha
    
    public:
        CPilha();
        ~CPilha();
        void push(double dado);
        bool pop(double &dado);
        int ContaNeg();
        int ContaNeg2();
};

CPilha::~CPilha() {
    double lixo;
    while (this->pop(lixo)) {
        // Vai desalocar os nós
    }
}
// Construtor
CPilha::CPilha() {
    topo = nullptr;
}
// 
void CPilha::push(double dado){
    CNoPilha *novo = new CNoPilha;
    
    novo -> dados = dado;
    novo -> proximo = topo;
    
    topo = novo;
}
// 
bool CPilha::pop(double &dado){
    if (topo == nullptr) return false; // pilha vazia
    
    CNoPilha *aux = topo;
    topo = topo->proximo;
    dado = aux->dados;
    delete aux;
    return true;
}
// a)
int CPilha::ContaNeg(){
    CPilha auxiliar; // pilha auxiliar temporária
    int contador = 0;
    double valor;
    
    while (pop(valor)) { // enquanto a pilha original tiver elementos
        if (valor <0){
            contador++; // conta os negativos
        }
        auxiliar.push(valor); // guarda na auxiliar (inverte a ordem)
    }
    while (auxiliar.pop(valor)) {
        push(valor); // repõe os elementos na pilha original (restaura a ordem)
    }
    return contador;
}
// b) Maneira sem pop e push
int CPilha::ContaNeg2(){
    int contador = 0;
    CNoPilha *atual = topo;
    
    while (atual != nullptr){
        if (atual->dados < 0) {
            contador++;
        }
    atual=atual->proximo;
    }
    return contador;
}

int main(){}

