/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */
 
#include <iostream>
#include <cmath>

// Enunciado
class CPiramide {
    protected:
        int numLadosBase;
        double altura, lado;
        double apotema;
    public:
        CPiramide(){ numLadosBase=3;altura=1.0;lado=1.0;setApotema(); }
        CPiramide(int n, double a, double l) { numLadosBase=3;altura=1.0;lado=1.0;setApotema();}
        void mostra()const{ std::cout << "Pirâmide regular de altura" << altura << "e base de lado " << lado << std::endl;}
        void setApotema(){apotema=lado/(2.0*tan(3.14159265/numLadosBase));}
        double areaBase() const { return(0.5*apotema*numLadosBase*lado);}
        virtual double volume()=0; 
};

// a)
class CPiramideHexagonal : public CPiramide {
    public:
        CPiramideHexagonal(double a, double l) : CPiramide(6,a,l) {} // 6 para inicializacao (hexagonal)
            // setApotema() ja foi chamada no construtor
        // b)
        double volume() { return(areaBase()*altura/3.0); }
};

int main(){
    return 0;
}

