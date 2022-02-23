#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<complex>
#include<sstream>

#include"struct.h"
#include"analysis.h"

using namespace std;

#define SSTR( x ) static_cast< ostringstream & >( \
        ( ostringstream() << dec << x ) ).str()

int high = 10, wide = 20;

componant_voltage_scource voltage_scource;

void to_x_and_y_position(long int position, long int &x_position, long int &y_position);

int main(){
    vector<componant_struct> componants;
    componant_struct temp;
    temp.componant_type = 1;
    temp.componant_in_connect = 10;
    temp.componant_out_connect = 11;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 11;
    temp.componant_out_connect = 1;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 11;
    temp.componant_out_connect = 21;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 1;
    temp.componant_out_connect = 2;
    temp.componant_value_polar = 31;
    temp.componant_value_rectangular = 31;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 21;
    temp.componant_out_connect = 22;
    temp.componant_value_polar = 19;
    temp.componant_value_rectangular = 19;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 2;
    temp.componant_out_connect = 12;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 22;
    temp.componant_out_connect = 12;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 12;
    temp.componant_out_connect = 13;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    //cout << analysis(componants);
    componants.clear();

    temp.componant_type = 1;
    temp.componant_in_connect = 1;
    temp.componant_out_connect = 2;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 2;
    temp.componant_out_connect = 3;
    temp.componant_value_polar = 27;
    temp.componant_value_rectangular = 27;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 4;
    temp.componant_out_connect = 5;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 6;
    temp.componant_out_connect = 7;
    temp.componant_value_polar = 54;
    temp.componant_value_rectangular = 54;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 8;
    temp.componant_out_connect = 9;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    cout << analysis(componants);
    componants.clear();

    temp.componant_type = 1;
    temp.componant_in_connect = 11;
    temp.componant_out_connect = 12;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 12;
    temp.componant_out_connect = 13;
    temp.componant_value_polar = 6;
    temp.componant_value_rectangular = 6;
    componants.push_back(temp);
     temp.componant_type = 1;
    temp.componant_in_connect = 13;
    temp.componant_out_connect = 3;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 13;
    temp.componant_out_connect = 23;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 3;
    temp.componant_out_connect = 4;
    temp.componant_value_polar = 11;
    temp.componant_value_rectangular = 11;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 23;
    temp.componant_out_connect = 24;
    temp.componant_value_polar = 23;
    temp.componant_value_rectangular = 23;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 4;
    temp.componant_out_connect = 14;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 24;
    temp.componant_out_connect = 14;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 14;
    temp.componant_out_connect = 15;
    temp.componant_value_polar = 45;
    temp.componant_value_rectangular = 45;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 15;
    temp.componant_out_connect = 16;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    //cout << analysis(componants);
    componants.clear();

    return 0;
}

void to_x_and_y_position(long int position, long int &x_position, long int &y_position){
    y_position = ceil((double)position/wide);
    x_position = position-((y_position-1)*wide);

    return;
}

void output(string Z, double angular_frequency_process){

}