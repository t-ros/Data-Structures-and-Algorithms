/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */

#include <climits> // para INT_MIN

class CArvoreBinaria;

class CNoArvore {
    int dados;
    CNoArvore *esq;
    CNoArvore *dir;
    friend class CArvoreBinaria;
};

class CArvoreBinaria {
    CNoArvore *raiz;

    void destroi(CNoArvore *pArvore);
    CNoArvore* ponteiroParaPai(CNoArvore* atual, int n) const;

public:
    CArvoreBinaria();
    ~CArvoreBinaria();
    int valorPai(int n) const;
    void destroi();
};

// Construtor
CArvoreBinaria::CArvoreBinaria() {
    raiz = nullptr;
}

// Destrutor
CArvoreBinaria::~CArvoreBinaria() {
    destroi();
}

// Método público de destruição
void CArvoreBinaria::destroi() {
    destroi(raiz);
    raiz = nullptr;
}

// Método recursivo privado de destruição
void CArvoreBinaria::destroi(CNoArvore *pArvore) {
    if (pArvore != nullptr) {
        destroi(pArvore->esq);
        destroi(pArvore->dir);
        delete pArvore;
    }
}

// Método privado que procura o pai de n
CNoArvore* CArvoreBinaria::ponteiroParaPai(CNoArvore* atual, int n) const {
    if (atual == nullptr) return nullptr;

    if ((atual->esq && atual->esq->dados == n) ||
        (atual->dir && atual->dir->dados == n)) {
        return atual;
    }

    CNoArvore* esqPai = ponteiroParaPai(atual->esq, n);
    if (esqPai) return esqPai;

    return ponteiroParaPai(atual->dir, n);
}

// Método público que retorna o valor do pai de n
int CArvoreBinaria::valorPai(int n) const {
    if (raiz == nullptr || raiz->dados == n)
        return INT_MIN;

    CNoArvore* pai = ponteiroParaPai(raiz, n);
    return pai ? pai->dados : INT_MIN;
}

int main(){}
