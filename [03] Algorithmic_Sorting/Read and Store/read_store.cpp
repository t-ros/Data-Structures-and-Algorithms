#include <iostream>
#include <fstream>  // a) to work with files
#include <iomanip>  // a) for precision
#include <vector>   // b) to store in the vector

using namespace std;

int main()
{
     // Open the file and check
    ifstream file(num_file.txt);
    if(!file){
        cerr  Error opening the file!  endl;
        return 1;
    }
    cout  Opening the file  endl  ...  endl;

    double num;
    int count = 0;

    cout  a) The file contains the following data   endl;

    while(file  num){  Read num while there is data
        cout                      fixed  setprecision(3)  num  endl;
        count++;
    }

    cout  Total   count   numbers, rounded to 3 decimal places  endl;
    file.close();
    cout  -------------------------------------------------------------  endl;
    file.open(num_file.txt);

    vectordouble numbers;  Create vector
     Read and store the numbers in the vector
    while(file  num){
        numbers.push_back(num);
    }

    cout  endl  b) Total numbers stored in the vector   numbers.size() = count endl;
    cout  -------------------------------------------------------------  endl;

    ofstream binaryFile(num_file.bin,iosbinary);  Create binary file
    if(!binaryFile){
        cerr  Error creating the binary file!  endl;
        return 1;
    }

    binaryFile.write(reinterpret_castchar(numbers.data()), numbers.size()  sizeof(double));

    binaryFile.close();

    cout  c) Binary file 'num_file.bin' successfully created!  endl;

    return 0;
}
