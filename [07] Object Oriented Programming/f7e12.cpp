/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */
 
class CAngulo {
    // a)
    protected: // mudança d) 
        int graus, minutos, segundos; 
        
    // b)
    public:
        // Constutor por defeito
        CAngulo(){ 
            graus = 10; 
            minutos = 5; 
            segundos = 15;
        }
        // Construtor por enumeração
        CAngulo(int g, int m, int s) { 
            graus = g;
            minutos = m;
            segundos = s;
        }
        // construtor por cópia
        CAngulo(const CAngulo &a) { 
            graus = a.graus;
            minutos = a.minutos;
            segundos = a.segundos;
        }
        // c)
        bool operator<(const CAngulo& o) const {
            return (graus   * 3600 + minutos * 60 + segundos) < (o.graus   * 3600 + o.minutos * 60 + o.segundos);
        }
        
};
// e)
class CSetor : public CAngulo {
    private:
        int raio; // raio do setor circular
    public:
        CSetor(int g, int m, int s, int r) : CAngulo(g,m,s), raio(r){} 
        bool menorTamanhoQue(const CSetor& o) const {
            return(*this < o) && (raio < o.raio);
        }
};

int main(){
    return 0;
}

