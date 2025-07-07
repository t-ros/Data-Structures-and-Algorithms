#include <iostream>

using namespace std;

int main()
{
    int num;

    cout << "Digite um numero inteiro:" << endl;
    cin >> num;
    cout << "Digitou o numero: "<< num << endl;
    cout << "Aqui tem um diamante desse tamanho:" << endl;

    for(int i = 0;i<num;i++) {
        cout << " ";
            for(int j=i+1;j<num;j++){
            cout << "*";
        }
            cout << endl;

    }
    return 0;
}

