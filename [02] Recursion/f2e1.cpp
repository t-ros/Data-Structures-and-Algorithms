#include <iostream>

using namespace std;

void imprimeAte(int n) {
    if (n < 0) {
        cout << endl << "A fechar o programa." << endl;
        return; // Sai da função se n for negativo
    }
    if(n == 0){
        cout << "0 ";
    }
    else{
        imprimeAte(n - 1); // Chamada recursiva primeiro (imprime na ordem crescente)
        cout << n << " "; // Exibe o número após a chamada recursiva
    }
}

int main() {
    int n;

    cout << "Digite um numero positivo: ";
    cin >> n;
    cout << endl;

    imprimeAte(n);

    cout << endl;


    return 0;
}
