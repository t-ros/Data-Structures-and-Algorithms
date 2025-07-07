/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */

int ordenacao(double vetor[], unsigned int N) { // N é o numero de elementos do vetor
    bool crescente = true;
    bool decrescente = true;
    
    for (unsigned int i = 0; i < N-1; i++){ // i unsigned assim como N
        if(vetor[i] < vetor [i-1]) { // ex se vetor[10] < vetor[9] -> decrescente
            crescente = false;
        } 
        if(vetor[i] > vetor [i-1]) { // ex se vetor[10] > vetor[9] -> crescente
            decrescente = false;
        } 
    }
    if (crescente) return 1; // return's têm de estar fora do ciclo for
    if(decrescente) return -1;
    return 0;
}

int main(){}
