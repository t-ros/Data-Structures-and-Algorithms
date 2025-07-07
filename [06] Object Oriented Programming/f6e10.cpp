/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */
// a) Declaração da classe

#include <iostream>
using namespace std;

class CDuracao { 
    // a) Atributos da classe
    private:
        int horas, minutos;
        
    public:
    // b) i) construtor por defeito/omissão (objeto com uma duração por defeito igual a 1h30m)
    CDuracao() { 
        horas = 1;
        minutos = 30;
    }
    // b) ii) um construtor por enumeração (recebe dois inteiros com uma duração qualquer em horas e minutos)
    CDuracao(int h, int m){ 
        horas = h;
        minutos = m;
    }
    // b) iii) um construtor por cópia
    CDuracao(const CDuracao &r) {
        horas = r.horas;
        minutos = r.minutos;
    }
    // c) iv) o método compara( )
    int compara(const CDuracao &o) const{
        int total1 = 60 * horas + minutos;
        int total2 = 60 * o.horas + o.minutos;
        return total1-total2;
    }
    
    // Método auxiliar para imprimir a duração
    void mostrar() const {
        cout << horas << "h" << minutos << "m" << endl;
    }
    
};

// Função main para testar
int main() {
    CDuracao d1;        // Por defeito (1h30m)
    CDuracao d2(2, 15); // Por enumeração
    CDuracao d3(d2);    // Por cópia

    cout << "Duracoes:\n";
    cout << "d1 = "; d1.mostrar();
    cout << "d2 = "; d2.mostrar();
    cout << "d3 = "; d3.mostrar();

    cout << "\nComparando d1 com d2: " << d1.compara(d2) << endl;
    cout << "Comparando d2 com d1: " << d2.compara(d1) << endl;
    cout << "Comparando d2 com d3: " << d2.compara(d3) << endl;

    return 0;
}
