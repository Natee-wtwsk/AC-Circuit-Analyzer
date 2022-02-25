#ifndef input_h
#define input_h

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<complex>
#include<sstream>
#include<stdlib.h>

#include"struct.h"
#include"drawing.h"

using namespace std;

void input(componant_voltage_scource voltage_scource, string **canvas, vector<componant_struct> &componants, vector<componant_struct> &componants_to_analyze, int high, int wide){
    while(true){
        componant_struct c;
        for(int i = 0; i < componants.size(); i++){
            cout << i+1 << " " << componants[i].componant_in_connect;
            if(componants[i].componant_type == 1) cout << "o----o";
            else if(componants[i].componant_type == 2) cout << "o-MW-o";
            else if(componants[i].componant_type == 3) cout << "o-||-o";
            else if(componants[i].componant_type == 4) cout << "o-oo-o";
            cout << componants[i].componant_out_connect;
            if(componants[i].componant_value_polar > 0) cout << " Value:" << componants[i].componant_value_polar << endl;
            else cout << endl;
        }
        cout << "pick your componant\n" << "0:finish componant choose\n1:wire (o---o)\n2:resistance (o-MW-o)\n3:capacitor (o-||-o)\n4:inductance (o-oo-o)\n5:remove your pick\npick :";
        cin >> c.componant_type;
        if(c.componant_type == 0) return;
        else if(c.componant_type < 5){
            cout << "pick first connect point and the point that it connect to"<<endl;
            cout << "Your In position : ";
            cin >> c.componant_in_connect;
            cout << "Your Out position : ";
            cin >> c.componant_out_connect;

            if(c.componant_in_connect == c.componant_out_connect){
                cout<<"Can't use the same position";
                continue;
            }//กรณีกรอกจุด1กับจุด2เป็นจุดเดียวกัน
            
            if(c.componant_in_connect > high*wide || c.componant_out_connect > high*wide){
                cout << "Error off canvas limit" << endl;
                continue;
            } //กรณีเกินตาราง

            if(c.componant_type == 1){
                c.componant_value_polar = 0;
                c.componant_value_rectangular = 0;
            }
            if(c.componant_type > 1){
                string input_temp;
                cout << "input your componant_value (don't input unit):";
                cin >> input_temp;
                if((int(input_temp.find_first_of("i")) > -1) || (int(input_temp.find_first_of("j")) > -1)){
                    if(int(input_temp.find_first_of("i")) > -1) input_temp.erase(int(input_temp.find_first_of("i")), 1);
                    else input_temp.erase(int(input_temp.find_first_of("j")), 1);
                    (c.componant_value_rectangular) = atof(input_temp.c_str());
                    if((c.componant_type) == 2) (c.componant_value_polar) = (c.componant_value_rectangular);
                    else if((c.componant_type) == 3) (c.componant_value_polar) = -(1/((voltage_scource.angular_frequency)*(c.componant_value_rectangular)));
                    else if((c.componant_type) == 4) (c.componant_value_polar) = (c.componant_value_rectangular)/(voltage_scource.angular_frequency);
                }
                else{
                    (c.componant_value_polar) = atof(input_temp.c_str());
                    if((c.componant_type) == 2) (c.componant_value_rectangular) = (c.componant_value_polar);
                    else if((c.componant_type) == 3) (c.componant_value_rectangular) = -(1/(voltage_scource.angular_frequency*c.componant_value_polar));
                    else if((c.componant_type) == 4) (c.componant_value_rectangular) = (voltage_scource.angular_frequency)*(c.componant_value_polar);
                }
                input_temp.clear();
            } //กำหนดหน่วยเพื่อป้องกัน Error
            componants.push_back(c);
            componants_to_analyze.push_back(c);
            if(system("CLS")) system("clear");
        }
        else if(c.componant_type == 5){
            unsigned int pick;
            for(int i = 0; i < componants.size(); i++){
                cout << i+1 << " " << componants[i].componant_in_connect;
                if(componants[i].componant_type == 1) cout << "o----o";
                else if(componants[i].componant_type == 2) cout << "o-MW-o";
                else if(componants[i].componant_type == 3) cout << "o-||-o";
                else if(componants[i].componant_type == 4) cout << "o-oo-o";
                cout << componants[i].componant_out_connect;
                if(componants[i].componant_value_polar > 0) cout << " Value:" << componants[i].componant_value_polar << endl;
                else cout << endl;
            }
            cout << "pick componant your like to remove(first number of list) :";
            cin >> pick;
            if(pick > componants.size()){
                cout << "Invalid pick" << endl;
                continue;
            }
            drawing_remove(canvas,componants, high, wide,pick);
            componants.erase(componants.begin()+pick-1);
            if(system("CLS")) system("clear");
        }
        
        else{
            cout << "invalid choice";
            continue;
        }
        cout << endl;
        
        drawing_add(canvas, componants, voltage_scource, high, wide);
    }

}

#endif