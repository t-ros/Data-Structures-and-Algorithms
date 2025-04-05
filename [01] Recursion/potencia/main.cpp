#include <iostream>
#include <cmath>

using namespace std;

double potencia(double x, int n){    
    if (n == 0) return 1; // caso base

    if (n < 0){x = 1/x; n = -n;}

    return x*potencia(x, n-1); // caso geral
}

int main()
{
    float x; // Real
    int n; // Inteiro

    cout << "Insira uma base qualquer real: ";
    cin >> x;
    cout << "Insira um expoente qualquer inteiro: ";
    cin >> n;
    cout << endl;  

    double p = potencia(x,n);
    cout << "O resultado da operacao x^n: " << p << endl;

    return 0;
}

