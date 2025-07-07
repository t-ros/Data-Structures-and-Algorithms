/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */

class CNumComplexo {
    // a)
    private: 
        double preal;
        double pimag;
    // b ) i) construtor por defeito/omissão (número real 1+0j); 
    CNumComplexo () {
        preal = 1;
        pimag = 0;
    }
    // b) ii) construtor por enumeração (recebe dois números reais com os valores da parte real e parte imaginária);
    CNumComplexo (double re, double im) {
        preal = re;
        pimag = im;
    } 
    // c) iii) o método compara( ) que compara o objeto com outro objeto passado como parâmetro e devolve 
    // um booleano consoante dois números complexos sejam ou não iguais. 
    bool compara (const CNumComplexo &o) const {
        if (preal == o.preal && pimag == o.pimag) return 1;
        else return 0;
    }
};

int main(){}
