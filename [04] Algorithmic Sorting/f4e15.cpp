/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */

#include <string>

// a) Declarar a estrutura
struct rato{
    double pvp; // preço
    std::string marca; 
    char ref[21];
    int stock;
    };

// b) Inserção
void ordenacaoInsercao(rato v[], int n){
    for (int i = 1; i < n; i++) {
        rato aux = v[i];
        int j;
        for (j=i;(j>0) && (aux.pvp > v[j-1].pvp); j--){
            v[j] = v[j-1];
            }
        v[j]=aux;
        }
    }
    
int main(){
    return 0;
}

