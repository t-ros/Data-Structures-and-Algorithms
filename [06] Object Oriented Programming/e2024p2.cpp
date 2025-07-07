/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */

#include <string>

// a) Todos os membros de CPecaVestuario sem definições inline
class CPecaVestuario {
    protected: // visivel para os métodos das classes e para os métodos das classes derivadas
        std::string tipo; // tipo de peça
        unsigned int quantidade; // número de unidades adquiridas de uma peça
        float custoCompra; // preço unitário em euros e cêntimos %.2f
        float PercentagemLucro; // percentagem do custo de cada peça que vai ser o lucro da loja
        
    private:
        CPecaVestuario();
        CPecaVestuario(std::string t, unsigned int q, float cc, float pl);
        float lucroEstimado();
};

CPecaVestuario::CPecaVestuario(){
    tipo = "casacos";
    quantidade = 50;
    custoCompra = 100;
    PercentagemLucro = 80;
}

CPecaVestuario::CPecaVestuario(std::string t, unsigned int q, float cc, float pl){
    tipo = t; 
    quantidade = q; 
    custoCompra = cc; 
    PercentagemLucro = pl;
}

float CPecaVestuario::lucroEstimado(){
    return (quantidade * custoCompra * (PercentagemLucro/100));
}

int main(){}
