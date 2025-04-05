#include <iostream>

using namespace std;

void decimalToOctal(int num){
    if (num < 0) {
        cout << endl << "A fechar o programa.";
        return; // sai da função se num for negativo
    }

    if (num <= 8) cout << num; // caso base

    // caso geral
    if (num > 8){
        decimalToOctal(num/8);
        cout << num%8;
    }
}

int main(){
    int k = 156;

    cout << endl << "A conversao de " << k << " (base 10) para base 8: ";

    decimalToOctal(k);

    return 0;
}
