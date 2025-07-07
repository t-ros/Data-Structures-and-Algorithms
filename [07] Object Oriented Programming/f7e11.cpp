/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */

#include <string> // a) para usar o std::string nomes;
#include <iostream>
using namespace std;

const int MAX = 100; // a) dimensão máxima das tabelas

class CPessoas {
    // a) Definição dos atributos
    protected: // d) Mudança de private para protected
        int npessoas;
        string nomes[MAX];
        int dataNasc[MAX]; //  datas de nascimento (int) 
        
    public:
    // b) i) um construtor por defeito/omissão (tabelas vazias); 
    CPessoas();
    // b) ii) um construtor por cópia;
    CPessoas(const CPessoas &r);
    // b) iii) um método para inserir uma pessoa (dados o nome e a data de nascimento como parâmetros);
    void inserePessoa(const string &nome, int dataNasc);
    // c) iv) um método ordena( ) que ordena as pessoas por data de nascimento (altera ambas as tabelas). 
    void ordena();
};
// b) i) um construtor por defeito/omissão (tabelas vazias); 
CPessoas::CPessoas(){
    npessoas = 0;
}
// b) ii) um construtor por cópia;
CPessoas::CPessoas(const CPessoas &r) {
    npessoas = r.npessoas;
    for (int i = 0; i < npessoas; i++) {
        nomes[i] = r.nomes[i];
        dataNasc[i] = r.dataNasc[i];
    }
}
// b) iii) um método para inserir uma pessoa (dados o nome e a data de nascimento como parâmetros);
void CPessoas::inserePessoa(const string &nome, int data) {
    if (npessoas < MAX) {
        nomes[npessoas] = nome;
        dataNasc[npessoas] = data;
        npessoas++;
    } else {
        cout << "Limite máximo de pessoas atingido!" << endl;
    }
}
// c) iv) um método ordena( ) que ordena as pessoas por data de nascimento (altera ambas as tabelas).
void CPessoas::ordena(){
    for (int i=0; i < npessoas-1; i++) {
        for (int j=0; j < npessoas-i-1; j++){
            if (dataNasc[j] > dataNasc[j+1]){
                int aux_data = dataNasc[j];
                dataNasc[j] = dataNasc[j+1];
                dataNasc[j+1] = aux_data;
                
                string aux_nomes = nomes[j];
                nomes[j] = nomes[j+1];
                nomes[j+1] = aux_nomes;
            }
        }
    }
}
// e) 
class CAdultos : public CPessoas {
    private:
        int nadultos; // o nº de pessoas com mais de 18 anos
        
    public:
        void atualiza();
        int getNumAdultos();
};

void CAdultos::atualiza(){
    ordena();
    
    nadultos=0;
    // int hoje = 20200125; referencia
    int idade18 = 20020125; // data de hoje - 18 anos
    
    for (int i = 0; i < npessoas; i++) {
        if (dataNasc[i] <= idade18) {
            nadultos++;
        }
    }   
}

int CAdultos::getNumAdultos(){
    return nadultos;
}

int main(){}
