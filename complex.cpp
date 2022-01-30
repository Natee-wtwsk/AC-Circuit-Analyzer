#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<complex>
using namespace std;

void complex_processing(double real1, double real2, double imag1, double imag2){
    char command;
    complex<double> complex1 = complex<double>(real1, imag1);
    complex<double> complex2 = complex<double>(real2, imag2);
    cout << "command : ";
    cin >> command;
    if(command == '+') cout << complex1 + complex2;
    if(command == '-') cout << complex1 - complex2;
    if(command == '*') cout << complex1*complex2;
    if(command == '/') cout << complex1/complex2;
}

int main(){
    complex_processing(1,2,3,4);
    return 0;
}