/*
 * @ 2025 by Diogo "Teros" Monteiro 
 */
 
 #include <iostream>
 // a) 
const int MAX_FICHAS=200; // A tabela pode conter até 200 fichas

struct filial{ // Cada ficha representa uma filial por isso usamos o singular
    char nome[56]; // 55 caracteres úteis
    int trabalhadores; // nº de trabalhadores
    double volume; // volume de negócios
    };

filial filiais[MAX_FICHAS];

// b) Função que conta quantas filiais têm valorInf < volume < valorSup
int contaFiliais(const filial v[], int n, double valorInf, double valorSup) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].volume < valorInf || v[i].volume > valorSup) {
            contador++;
        }
    }
    return contador;
}

// c) main() de teste
int main() {
    // 1) Tabela com 4 filiais
    filial filiais[4] = {
        { "Porto Central",    120, 150000.0 },
        { "Lisboa Expo",      200, 320000.0 },
        { "Coimbra Shopping",  80,  75000.0 },
        { "Faro Algarve",      50, 200000.0 }
    };
    int nfiliais = 4;

    // Limites 
    double valorInf = 100000.0;
    double valorSup = 300000.0;

    // Chama contaFiliais e obtém o resultado
    int resultado = contaFiliais(filiais, nfiliais, valorInf, valorSup);

    // Resultado no ecrã
    std::cout << "Numero de filiais com volume de negocios entre " << valorInf << " euros e " << valorSup << " euros: " << resultado << std::endl;

    return 0;
}

