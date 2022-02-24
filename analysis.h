#ifndef analysis_h
#define analysis_h

#include <algorithm>
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

class componant_voltage_source_analysis{
    public:
        double voltage;
        double angular_frequency;
        double offset; 
	    long int voltage_source_in_connect;
	    long int voltage_source_out_connect;
        int connect_in;
        int connect_out;
        componant_voltage_source_analysis();
        ~componant_voltage_source_analysis();
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

componant_voltage_source_analysis::componant_voltage_source_analysis(){
    voltage = 220;
    angular_frequency = 50;
    offset = 0; 
	voltage_source_in_connect = 0;
	voltage_source_out_connect = 0;
    connect_in = 0;
    connect_out = 0;
}
componant_voltage_source_analysis::~componant_voltage_source_analysis(){

}

componant_voltage_source_analysis voltage_source_analysis;
vector<componant_struct_analysis> components_analysis;
void analysis_begin(vector<componant_struct> componants, componant_voltage_scource voltage_scource);
void analysis_sorted();
void analysis_connect();
void analysis_wire_connect();
void analysis_wire_and_components_connect();
void analysis_parallel();
void analysis_series();
bool analysis_short_circuit();
complex<double> complex_processing_parallel(complex<double> complex1, complex<double> complex2);
complex<double> complex_processing_series(complex<double> complex1, complex<double> complex2);
complex<double> connect_circuit();

complex<double> analysis(vector<componant_struct> componants, componant_voltage_scource voltage_scource){
    components_analysis.clear();
    analysis_begin(componants, voltage_scource);
    analysis_sorted();
    //analysis_connect();
    analysis_wire_connect();
    analysis_wire_and_components_connect();
    //for(int i = 0; i < components_analysis.size(); i++) cout << components_analysis[i].componant_type << " " << components_analysis[i].componant_value_rectangular << " " << components_analysis[i].componant_in_connect << " " << components_analysis[i].componant_out_connect << " " << components_analysis[i].connect_in << " " << components_analysis[i].connect_out << endl;
    //cout << voltage_source_analysis.connect_in << " " << voltage_source_analysis.connect_out << endl;
    int cycles = 0;
    while(components_analysis.size() > 1){
        analysis_parallel();
        analysis_series();
        if(analysis_short_circuit() == true) return complex<double>(0, 0);
        if(cycles > 200){
            cout << "Out of 200 cycles" << endl;
            break;
        }
        cycles++;
    }
    //for(int i = 0; i < components_analysis.size(); i++) cout << components_analysis[i].componant_type << " " << components_analysis[i].componant_value_rectangular << " " << components_analysis[i].componant_in_connect << " " << components_analysis[i].componant_out_connect << " " << components_analysis[i].connect_in << " " << components_analysis[i].connect_out << endl;
    //cout << voltage_source_analysis.connect_in << " " << voltage_source_analysis.connect_out << endl;
    return connect_circuit();
}

void analysis_begin(vector<componant_struct> componants, componant_voltage_scource voltage_scource){
    int componant_size = componants.size();
    voltage_source_analysis.voltage = voltage_scource.voltage;
    voltage_source_analysis.angular_frequency = voltage_scource.angular_frequency;
    voltage_source_analysis.offset = voltage_scource.offset;
    voltage_source_analysis.voltage_source_in_connect = voltage_scource.voltage_scourc_in_connect;
    voltage_source_analysis.voltage_source_out_connect = voltage_scource.voltage_scourc_out_connect;
    voltage_source_analysis.connect_in = componant_size+10;
    voltage_source_analysis.connect_out = -(componant_size+10);
    for(int i = 0; i < componant_size; i++){
        componant_struct_analysis temp;
        temp.componant_type = componants[i].componant_type;
        temp.componant_in_connect = componants[i].componant_in_connect;
        temp.componant_out_connect = componants[i].componant_out_connect;
        temp.componant_value_polar = componants[i].componant_value_polar;
        if(componants[i].componant_type == 1) temp.componant_value_rectangular = complex<double>(0, 0);
        else if(componants[i].componant_type == 2) temp.componant_value_rectangular = complex<double>(componants[i].componant_value_rectangular, 0);
        else if(componants[i].componant_type <= 4) temp.componant_value_rectangular = complex<double>(0, componants[i].componant_value_rectangular);
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
        if(components_analysis[i].componant_type != 1) continue;
		temp = components_analysis[i];
		for(j = i; j > 0 && components_analysis[j-1].componant_type > temp.componant_type; j--) components_analysis[j] = components_analysis[j-1];
		components_analysis[j] = temp;
	}
}

void analysis_connect(){
    int components_analysis_size = components_analysis.size();
    int j;
    for(int i = 0; i < components_analysis_size; i++){
        //cout << "LOOP" << i+1 << " " << "I :" << components_analysis[i].connect_in << " " << components_analysis[i].connect_out << endl;
        for(j = 0; j < components_analysis_size; j++){
            if(i == j) continue;
            if(components_analysis[i].componant_in_connect == components_analysis[j].componant_in_connect) components_analysis[i].connect_in = components_analysis[j].connect_in;
            if(components_analysis[i].componant_in_connect == components_analysis[j].componant_out_connect) components_analysis[i].connect_in = components_analysis[j].connect_out;
            if(components_analysis[i].componant_out_connect == components_analysis[j].componant_in_connect) components_analysis[i].connect_out = components_analysis[j].connect_in;
            if(components_analysis[i].componant_out_connect == components_analysis[j].componant_out_connect) components_analysis[i].connect_out = components_analysis[j].connect_out;
            //cout << "J :" << components_analysis[j].connect_in << " " << components_analysis[j].connect_out << endl;
        }
        //cout << endl;
    }
}

void analysis_wire_connect(){
    int components_analysis_size = components_analysis.size();
    int numbers_of_wire = 0;
    while(components_analysis[numbers_of_wire].componant_type == 1) numbers_of_wire++;
    //cout << "number_of_wire :" << number_of_wire << endl;
    int j;
    for(int i = 0; i < numbers_of_wire; i++){
        for(j = numbers_of_wire-1; j >= 0; j--){
            if(i == j) continue;
            if(components_analysis[i].componant_in_connect == components_analysis[j].componant_in_connect){
                components_analysis[j].connect_in = components_analysis[i].connect_in;
                components_analysis[j].connect_out = components_analysis[i].connect_out;
            }
            if(components_analysis[i].componant_in_connect == components_analysis[j].componant_out_connect){
                components_analysis[j].connect_in = components_analysis[i].connect_in;
                components_analysis[j].connect_out = components_analysis[i].connect_out;
            }
            if(components_analysis[i].componant_out_connect == components_analysis[j].componant_in_connect){
                components_analysis[j].connect_in = components_analysis[i].connect_in;
                components_analysis[j].connect_out = components_analysis[i].connect_out;
            }
            if(components_analysis[i].componant_out_connect == components_analysis[j].componant_out_connect){
                components_analysis[j].connect_in = components_analysis[i].connect_in;
                components_analysis[j].connect_out = components_analysis[i].connect_out;
            }       
        }
    }
}

void analysis_wire_and_components_connect(){
    int components_analysis_size = components_analysis.size();
    int j;
    for(int i = components_analysis_size-1; (i >= 0) && (components_analysis[i].componant_type != 1); i--){
        for(j = components_analysis_size-1; j >=0; j--){
            if(components_analysis[i].componant_in_connect == components_analysis[j].componant_in_connect) components_analysis[i].connect_in = components_analysis[j].connect_in;
            if(components_analysis[i].componant_in_connect == components_analysis[j].componant_out_connect) components_analysis[i].connect_in = components_analysis[j].connect_out;
            if(components_analysis[i].componant_out_connect == components_analysis[j].componant_in_connect) components_analysis[i].connect_out = components_analysis[j].connect_in;
            if(components_analysis[i].componant_out_connect == components_analysis[j].componant_out_connect) components_analysis[i].connect_out = components_analysis[j].connect_out;
        }
    }
    for(int i = 0; i < components_analysis_size; i++){
        if(voltage_source_analysis.voltage_source_in_connect == components_analysis[i].componant_in_connect) voltage_source_analysis.connect_in = components_analysis[i].connect_in;
        if(voltage_source_analysis.voltage_source_in_connect == components_analysis[i].componant_out_connect) voltage_source_analysis.connect_in = components_analysis[i].connect_out;
        if(voltage_source_analysis.voltage_source_out_connect == components_analysis[i].componant_in_connect) voltage_source_analysis.connect_out = components_analysis[i].connect_in;
        if(voltage_source_analysis.voltage_source_out_connect == components_analysis[i].componant_out_connect) voltage_source_analysis.connect_out = components_analysis[i].connect_out;
    }
}

void analysis_parallel(){
    int components_analysis_size = components_analysis.size();
    int j;
    for(int i = 0; i < components_analysis_size; i++){
        for(j = 0; j < components_analysis_size; j++){
            if(i == j) continue;
            if(((components_analysis[i].connect_in == components_analysis[j].connect_in) && (components_analysis[i].connect_out == components_analysis[j].connect_out)) || ((components_analysis[i].connect_in == components_analysis[j].connect_out) && (components_analysis[i].connect_out == components_analysis[j].connect_in))){
                componant_struct_analysis temp;
                temp.componant_type = 99;
                temp.componant_in_connect = components_analysis[i].componant_in_connect;
                temp.componant_out_connect = components_analysis[j].componant_out_connect;
                temp.componant_value_polar = -1;
                temp.componant_value_rectangular = complex_processing_parallel(components_analysis[i].componant_value_rectangular, components_analysis[j].componant_value_rectangular);
                temp.connect_in = components_analysis[i].connect_in;
                temp.connect_out = components_analysis[i].connect_out;

                components_analysis[i] = temp;
                components_analysis.erase(components_analysis.begin()+j);
                if(i < j) i++;
                j--;
                components_analysis_size--;
                /*for(int n = 0; n < components_analysis.size(); n++) cout << components_analysis[n].componant_value_rectangular << " ";
                cout << endl;*/
            }
        }
    }
}

void analysis_series(){
    int components_analysis_size = components_analysis.size();
    int j;
    for(int i = 0; i < components_analysis_size; i++){
        for(j = 0; j < components_analysis_size; j++){
            if(i == j) continue;
            if((components_analysis[i].connect_out == components_analysis[j].connect_in) || (components_analysis[i].connect_in == components_analysis[j].connect_out)){
                if(((components_analysis[i].connect_in == components_analysis[j].connect_in) && (components_analysis[i].connect_out == components_analysis[j].connect_out)) || ((components_analysis[i].connect_in == components_analysis[j].connect_out) && (components_analysis[i].connect_out == components_analysis[j].connect_in))){
                    continue;
                }
                componant_struct_analysis temp;
                temp.componant_type = 99;
                temp.componant_in_connect = components_analysis[i].componant_in_connect;
                temp.componant_out_connect = components_analysis[j].componant_out_connect;
                temp.componant_value_polar = -1;
                temp.componant_value_rectangular = complex_processing_series(components_analysis[i].componant_value_rectangular, components_analysis[j].componant_value_rectangular);
                if(components_analysis[i].connect_out == components_analysis[j].connect_in){
                    temp.connect_in = components_analysis[i].connect_in;
                    temp.connect_out = components_analysis[j].connect_out;
                }
                else if(components_analysis[i].connect_in == components_analysis[j].connect_out){
                    temp.connect_in = components_analysis[j].connect_in;
                    temp.connect_out = components_analysis[i].connect_out;
                }

                components_analysis[i] = temp;
                components_analysis.erase(components_analysis.begin()+j);
                return;
                /*if(i < j) i++;
                j--;
                components_analysis_size--;*/
                /*for(int n = 0; n < components_analysis.size(); n++) cout << components_analysis[n].componant_value_rectangular << " ";
                cout << endl;*/
            }
        }
    }
}

bool analysis_short_circuit(){
    bool short_flag;
    int components_analysis_size = components_analysis.size();
    for(int i = 0; i < components_analysis_size; i++){
        if((components_analysis[i].connect_in == components_analysis[i].connect_out) && (components_analysis[i].componant_value_rectangular != complex<double>(0, 0))){
            cout << "Short Circuit at Node " << components_analysis[i].connect_in << ", componant_value_rectangular is " << components_analysis[i].componant_value_rectangular << endl;
            short_flag = true;
            break;
        }
    }
    if(voltage_source_analysis.connect_in == voltage_source_analysis.connect_out){
        cout << "Voltage Source is Short" << endl;
        short_flag = true;
    }
    if(short_flag == true) return true;
    else return false;
}

complex<double> complex_processing_parallel(complex<double> complex1, complex<double> complex2){
    if((complex1.real() == 0) && (complex1.imag() == 0)) return complex2;
    else return (complex1*complex2)/(complex1+complex2);
}

complex<double> complex_processing_series(complex<double> complex1, complex<double> complex2){
    return complex1+complex2;
}

complex<double> connect_circuit(){
    //cout << voltage_source_analysis.connect_in << "  " << components_analysis[0].connect_in << "  " << voltage_source_analysis.connect_out << "  " << components_analysis[0].connect_out;
    //cout << components_analysis[0].componant_value_rectangular << endl;
    if(((voltage_source_analysis.connect_in == components_analysis[0].connect_in) && (voltage_source_analysis.connect_out == components_analysis[0].connect_out)) || ((voltage_source_analysis.connect_in == components_analysis[0].connect_out) && (voltage_source_analysis.connect_out == components_analysis[0].connect_in))){
        return components_analysis[0].componant_value_rectangular;
    }
    else{
            cout << "Unconnect Voltage Source";
            return complex<double>(0, 0);
    }
}

#endif