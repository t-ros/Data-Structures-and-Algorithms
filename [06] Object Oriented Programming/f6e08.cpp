/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */

#include <iostream>

class CDiametro{
    private:
    int pes; // diametro em pés
    int polegadas; // polegadas
    
    // a)
    public:
    // Construtor por omissão (por defeito)
    CDiametro(){
        pes = 10; // em pés
        polegadas = 0;
    }
    // Construtor por enumeração (recebe o comprimento em pés e polegadas) 
    CDiametro(int p, int pol = 0){ // polegadas (facultativas), tendo o valor 0 por omissão
        pes = p;
        polegadas = pol;
    }
        
    void corrige_polegadas(){
        if (polegadas>=12){
            pes+=polegadas/12;
            polegadas=polegadas%12;
        }
    }
};

int main() {
    CDiametro d(5, 14);
    d.corrige_polegadas();
    return 0;
}


