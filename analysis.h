#ifndef analysis_h
#define analysis_h

#include<vector>
#include<string>
#include<complex>
#include<iostream>

#include"struct.h"

using namespace std;

class componant_struct_analysis{
    public:
        int componant_type;
        long int componant_in_connect;
        long int componant_out_connect;
        double componant_value_polar;
        complex<double> componant_value_rectangular;
        int connect_in;
        int connect_out;
        componant_struct_analysis();
        ~componant_struct_analysis();
};

componant_struct_analysis::componant_struct_analysis(){
    componant_type = -1;
    componant_in_connect = -1;
    componant_out_connect = -1;
    componant_value_polar = -1;
    componant_value_rectangular = complex<double>(0, 0);
    connect_in = 0;
    connect_out = 0;
};
componant_struct_analysis::~componant_struct_analysis(){

};

vector<componant_struct_analysis> components_analysis;
void analysis_begin(vector<componant_struct> componants);
void analysis_sorted();
void analysis_connect();
void analysis_parallel();
void analysis_series();
bool analysis_short_circuit();
complex<double> complex_processing_parallel(complex<double> complex1, complex<double> complex2);
complex<double> complex_processing_series(complex<double> complex1, complex<double> complex2);

complex<double> analysis(vector<componant_struct> componants){
    analysis_begin(componants);
    for(int n = 0; n < components_analysis.size(); n++) cout << components_analysis[n].componant_value_rectangular << " ";
    cout << endl;
    analysis_sorted();
    for(int n = 0; n < components_analysis.size(); n++) cout << components_analysis[n].componant_value_rectangular << " ";
    cout << endl;
    for(int n = 0; n < components_analysis.size(); n++) cout << components_analysis[n].connect_in << " ";
    cout << endl;
    for(int n = 0; n < components_analysis.size(); n++) cout << components_analysis[n].connect_out << " ";
    cout << endl;
    while(components_analysis.size() > 1){
        analysis_connect();
        analysis_parallel();
        analysis_series();
        if(analysis_short_circuit() == true) {
            cout << "Short! ";
            return complex<double>(0, 0);
        }
    }
    return components_analysis[0].componant_value_rectangular;
}

void analysis_begin(vector<componant_struct> componants){
    int componant_size = componants.size();
    for(int i = 0; i < componant_size; i++){
        componant_struct_analysis temp;
        temp.componant_type = componants[i].componant_type;
        temp.componant_in_connect = componants[i].componant_in_connect;
        temp.componant_out_connect = componants[i].componant_out_connect;
        temp.componant_value_polar = componants[i].componant_value_polar;
        if(componants[i].componant_type != 2) temp.componant_value_rectangular = complex<double>(0, componants[i].componant_value_rectangular);
        else temp.componant_value_rectangular = complex<double>(componants[i].componant_value_rectangular, 0);
        if(componants[i].componant_type == 1){
            temp.connect_in = i+1;
            temp.connect_out = i+1;
        }
        else{
            temp.connect_in = i+1;
            temp.connect_out = -(i+1);
        }
        
        components_analysis.push_back(temp);
    }
}

void analysis_sorted(){
    componant_struct_analysis temp;
    int components_analysis_size = components_analysis.size();
    int j;
    for(int i = 0; i < components_analysis_size; i++){
		temp = components_analysis[i];
		for(j = i; j > 0 && components_analysis[j-1].componant_type > temp.componant_type; j--) components_analysis[j] = components_analysis[j-1];
		components_analysis[j] = temp;
	}
}

void analysis_connect(){
    int components_analysis_size = components_analysis.size();
    int j;
    for(int i = 0; i < components_analysis_size; i++){
        for(j = i+1; j < components_analysis_size; j++){
            if(components_analysis[i].componant_in_connect == components_analysis[j].componant_in_connect) components_analysis[j].connect_in = components_analysis[i].connect_in;
            if(components_analysis[i].componant_in_connect == components_analysis[j].componant_out_connect) components_analysis[j].connect_out = components_analysis[i].connect_in;
            if(components_analysis[i].componant_out_connect == components_analysis[j].componant_in_connect) components_analysis[j].connect_in = components_analysis[i].connect_out;
            if(components_analysis[i].componant_out_connect == components_analysis[j].componant_out_connect) components_analysis[j].connect_out = components_analysis[i].connect_out;
        }
    }
}

void analysis_parallel(){
    int components_analysis_size = components_analysis.size();
    int j;
    for(int i = 0; i < components_analysis_size; i++){
        for(j = i+1; j < components_analysis_size; j++){
            if(((components_analysis[i].connect_in == components_analysis[j].connect_in) && (components_analysis[i].connect_out == components_analysis[j].connect_out)) || ((components_analysis[i].connect_in == components_analysis[j].connect_out) || (components_analysis[i].connect_out == components_analysis[j].connect_in))){
                componant_struct_analysis temp;
                temp.componant_type = 99;
                temp.componant_in_connect = -1;
                temp.componant_out_connect = -1;
                temp.componant_value_polar = -1;
                if((components_analysis[i].componant_value_rectangular.real() == 0) && (components_analysis[i].componant_value_rectangular.imag() == 0)) temp.componant_value_rectangular = components_analysis[j].componant_value_rectangular;
                else temp.componant_value_rectangular = (components_analysis[i].componant_value_rectangular*components_analysis[j].componant_value_rectangular)/(components_analysis[i].componant_value_rectangular+components_analysis[j].componant_value_rectangular);
                temp.connect_in = components_analysis[i].connect_in;
                temp.connect_out = components_analysis[i].connect_out;

                components_analysis.push_back(temp);
                components_analysis.erase(components_analysis.begin()+i);
                components_analysis.erase(components_analysis.begin()+j-1);

                components_analysis_size-=2;
                i--;
            }
        }
    }
}

void analysis_series(){
    int components_analysis_size = components_analysis.size();
    int j;
    for(int i = 0; i < components_analysis_size; i++){
        for(j = i+1; j < components_analysis_size; j++){
            if((components_analysis[i].connect_out == components_analysis[j].connect_in) || (components_analysis[i].connect_in == components_analysis[j].connect_out)){
                componant_struct_analysis temp;
                temp.componant_type = 99;
                temp.componant_in_connect = -1;
                temp.componant_out_connect = -1;
                temp.componant_value_polar = -1;
                if((components_analysis[i].componant_value_rectangular.real() == 0) && (components_analysis[i].componant_value_rectangular.imag() == 0)) temp.componant_value_rectangular = components_analysis[j].componant_value_rectangular;
                else temp.componant_value_rectangular = complex_processing_series(components_analysis[i].componant_value_rectangular, components_analysis[j].componant_value_rectangular);
                if(components_analysis[i].connect_out == components_analysis[j].connect_in){
                    temp.connect_in = components_analysis[i].connect_in;
                    temp.connect_out = components_analysis[j].connect_out;
                }
                else if(components_analysis[i].connect_in == components_analysis[j].connect_out){
                    temp.connect_in = components_analysis[j].connect_in;
                    temp.connect_out = components_analysis[i].connect_out;
                }

                components_analysis.push_back(temp);
                components_analysis.erase(components_analysis.begin()+i);
                components_analysis.erase(components_analysis.begin()+j-1);

                components_analysis_size-=2;
                i--;
            }
        }
    }
}

bool analysis_short_circuit(){
    int components_analysis_size = components_analysis.size();
    for(int i = 1; i < components_analysis_size; i++){
        if((components_analysis[i].connect_in == components_analysis[i].connect_out) && (components_analysis[i].componant_value_rectangular.real() != 0) && (components_analysis[i].componant_value_rectangular.imag() != 0)) return true;
    }

    return false;
}

complex<double> complex_processing_parallel(complex<double> complex1, complex<double> complex2){
    return (complex1*complex2)/(complex1+complex2);
}

complex<double> complex_processing_series(complex<double> complex1, complex<double> complex2){
    return complex1+complex2;
}

#endif