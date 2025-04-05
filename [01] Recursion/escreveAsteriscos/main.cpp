#include <iostream>

using namespace std;

void escreveAsteriscos(int n){
    if (n > 1)
        escreveAsteriscos(n - 1);
    cout << "*";
}

int main(){
    int n;

    cout << "Digite um numero: ";
    cin >> n;

    if (n <= 0){
        cout << "Invalido! Digite um numero (>0): ";
        cin >> n;
    }
    cout << endl;

    escreveAsteriscos(n);

    return 0;
}
