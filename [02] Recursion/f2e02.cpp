#include <iostream>

double T(int n) { // double porque os valores de T vão ser fracionados
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return (T(n - 1) + T(n - 2)) / 2;
    }
}

int main() {
    for(int i=0;i<=10;i++){
        std::cout << "T[" << i << "]" << T(i) << std::endl;
    }
    return 0;
}
