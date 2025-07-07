/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */

class CArvoreBinaria; // “declarada” aqui para poder ser designada como amiga
                        // antes de ser definitivamente declarada mais à frente
class CNoArvore {
    int dados;
    CNoArvore *esq; // ponteiro para subárvore esquerda
    CNoArvore *dir; // ponteiro para subárvore direita
    friend class CArvoreBinaria; // esta classe pode aceder a atributos private
};

class CArvoreBinaria {
    CNoArvore *raiz;
 
    // Métodos privados auxiliares
    void destroi(CNoArvore *pArvore);
    int contaNos1Filho(CNoArvore *p) const;
    void insere(int item, CNoArvore *raiz);
    void emOrdem(CNoArvore* no, int* &vetor, int &index);
    
    public:
        CArvoreBinaria();
        ~CArvoreBinaria();
    
        void destroi();
        int contaNos1Filho() const;
        void insere(int item);
        void ordenaVetor(int v[], int N);
};

// Construtor
CArvoreBinaria::CArvoreBinaria() {
 raiz = nullptr;
}

// Destrutor
CArvoreBinaria::~CArvoreBinaria() {
    destroi(); // método que elimina todos os nós
}

// Método public para destruir a árvore completa
void CArvoreBinaria::destroi() {
    destroi(raiz);
    raiz = nullptr;
}

void CArvoreBinaria::destroi(CNoArvore *pArvore) {
    if(pArvore != nullptr) {
        destroi(pArvore->esq);
        destroi(pArvore->dir);
        delete pArvore;
    }
}

int CArvoreBinaria::contaNos1Filho(CNoArvore *p) const {
    if (p == nullptr)
        return 0;

    int contador = 0;

    if ((p->esq == nullptr && p->dir != nullptr) ||
        (p->esq != nullptr && p->dir == nullptr)) {
        contador = 1;
    }

    return contador + contaNos1Filho(p->esq) + contaNos1Filho(p->dir);
}

void CArvoreBinaria::insere(int item) {
 if (raiz != nullptr) insere(item, raiz); // chama o metodo private
 else { // cria o primeiro no da árvore
 raiz = new CNoArvore;
 raiz->dados = item;
 raiz->esq = raiz->dir = nullptr;
 }
}
//--------------------------------------------------------------------
// Método private que “faz o trabalho”
void CArvoreBinaria::insere(int item, CNoArvore *raiz) {
 if (item < raiz->dados) {
 if (raiz->esq != nullptr) insere(item, raiz->esq);
 else { // novo nó é o primeiro nó da subárvore esquerda
 raiz->esq = new CNoArvore;
 raiz->esq->dados = item;
 raiz->esq->esq = raiz->esq->dir = nullptr;
 }
 }
 else if (item > raiz->dados) {
 if (raiz->dir != nullptr) insere(item, raiz->dir);
 else { // novo nó é o primeiro nó da subárvore direita
 raiz->dir = new CNoArvore;
 raiz->dir->dados = item;
 raiz->dir->esq = raiz->dir->dir = nullptr;
 }
 }
}


void CArvoreBinaria::emOrdem(CNoArvore* no, int* &vetor, int &index) {
    if (no == nullptr) return;

    emOrdem(no->esq, vetor, index);
    vetor[index++] = no->dados;
    emOrdem(no->dir, vetor, index);
}

void CArvoreBinaria::ordenaVetor(int v[], int N) {
    CArvoreBinaria arvore;

    // Inserir todos os elementos na árvore
    for (int i = 0; i < N; i++) {
        arvore.insere(v[i]); // Este método tem de existir
    }

    // Recolher em ordem
    int index = 0;
    emOrdem(arvore.raiz, v, index); // acesso direto pois friend class
}


int main(){}
