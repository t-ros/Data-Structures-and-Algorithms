#include <iostream>

using namespace std;

int fibonacciRec(int n) {
    if (n < 1) {
        cout << endl;
        cout << "ERRO! O numero tem de ser positivo." << endl;
        return 0;
    }
    if (n == 1) return 0; // Para os primeiros numeros da séries
    if (n == 2) return 1;
    return fibonacciRec(n - 1) + fibonacciRec(n - 2); // A sequência de Fibonnaci
}

void fibonacci(int n) {
    cout << endl;
    cout << "Sequencia de Fibonacci ate " << n << ": " << endl;

    for (int i = 1; i <= n; i++) {
        cout << i << " -> " << fibonacciRec(i) << endl;
    }
    cout << endl;
}

int main() {
    int n;

    cout << "Insira um numero inteiro: ";
    cin >> n;

    fibonacci(n);

    return 0;
}
