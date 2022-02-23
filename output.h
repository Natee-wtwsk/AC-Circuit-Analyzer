#ifndef output_h
#define output_h

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<complex>
#include<sstream>

#include"struct.h"

using namespace std;

void output(componant_voltage_scource voltage_scource, complex<double> Z){
    cout << Z.real() << " " << Z.imag();
}

#endif