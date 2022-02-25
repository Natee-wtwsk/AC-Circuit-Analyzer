#ifndef output_h
#define output_h

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<complex>
#include<sstream>
#include<cmath>
#include<cstdlib>

#include"struct.h"
#include"analysis.h"



struct componant_Z{
    double r;
    double Theta;
	double x_real;
	double y_image;
};
struct componant_I{
    double current;
    double angular_frequency;
    double offset; 
};

#define _USE_MATH_DEFINES
using namespace std;
void output(componant_voltage_scource voltage_scource,complex<double> Z){
    componant_Z z_result;
    componant_I I;

    z_result.x_real = Z.real();
    z_result.y_image = Z.imag();
    /*cout<<"z: ";
    cin>>z_result.x_real>>z_result.y_image;
    cout<<"v: ";
    cin>>voltage_scource.voltage>>voltage_scource.angular_frequency>>voltage_scource.offset;*/

    if(z_result.x_real == 0&&z_result.y_image<0){z_result.Theta = -90;
    }else if(z_result.x_real == 0&&z_result.y_image>0){z_result.Theta = 90;
    }else if(z_result.y_image == 0){z_result.Theta = 0;
    }else if(z_result.y_image == 0&&z_result.x_real == 0){z_result.Theta = 0;
    }else{ z_result.Theta = atan2(z_result.y_image,z_result.x_real)*180/M_PI;}

    z_result.r = sqrt(pow(z_result.x_real,2)+pow(z_result.y_image,2));

    I.current = (voltage_scource.voltage/z_result.r);
    I.offset = voltage_scource.offset-z_result.Theta;

    if(I.offset>0){
    cout << "Your's function: " << I.current<< "cos( " << voltage_scource.angular_frequency << "t +" << I.offset << ")" << endl;
    }else cout << "Your's function: " << I.current<< "cos( " << voltage_scource.angular_frequency << "t " << I.offset << ")" << endl;
    cout<< "Your's impedance: "<< z_result.r <<"and Theta is: "<<z_result.Theta;
    
}

#endif