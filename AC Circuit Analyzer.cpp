#include<iostream>
#include<iomanip>
#include<cmath>
#include<complex>
using namespace std;

double voltage;
double angular_frequency;
double offset;

void input();
void output();

int main(){
    cout << "Please Enter AC voltage function (Sinusoids)";
    cout << "Voltage :";
    cin >> voltage;
    cout << "angular_frequency :";
    cin >> angular_frequency;
    cout << "offset :";
    cin >> offset;
    cout << "Your's function:" << voltage << "con(" << angular_frequency << "t" << offset << ")";

    return 0;
}
