/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */

#include <string>
#include <iostream>

// Enunciados vindo do problema anterior
class CPecaVestuario {
    protected: 
        std::string tipo; 
        unsigned int quantidade; 
        float custoCompra; 
        float PercentagemLucro; 
        
    public:
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
// Problema 3
// a) Declaração da classe e todos os seus membros
class CCasacos : public CPecaVestuario{
    protected:
        unsigned int ref; // referência
        unsigned int stock; // número de peças de vestuario em stock
        
    public:
        // construtor
        CCasacos(unsigned int r, unsigned int s); // construtor por enumeração
        // métodos
        void vendeCasaco();
        void mostra();
};
// b) Definições dos construtores e métodos
CCasacos::CCasacos(unsigned int r, unsigned int s){
    stock = s;
    quantidade = stock;
    ref = r;
}

void CCasacos::vendeCasaco(){
    if (stock > 1) {
        stock--;
    } else if (stock == 1){
        stock--;
        std::cout << "Aviso: Só há 1 casaco em stock" << std::endl;
    } else {
        std::cout << "Aviso: Não há casaco disponíveis" << std::endl;
    }
}

void CCasacos::mostra(){
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Quantidade: " << quantidade << std::endl;
    std::cout << "Referência: " << ref << std::endl;
    std::cout << "Lucro Estimado: " << lucroEstimado() << std::endl;
}

int main(){}
