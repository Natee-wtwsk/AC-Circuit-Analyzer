#include<iostream>
#include<complex>
using namespace std;

int main(){
    double real1 = 1, real2 = 2,imag1 = 3, imag2 = 4;
    char command;
    complex<double> complex1 = complex<double>(real1,imag1);
    complex<double> complex2 = complex<double>(real2,imag2);
    cout << "command : ";
    cin >> command;
    if(command == '+') cout << complex1+complex2;
    if(command == '|') cout << (complex1*complex2)/(complex1+complex2);
    return 0;
}