#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<complex>
#include<sstream>

#include"struct.h"
#include"analysis.h"
#include"output.h"

using namespace std;

#define SSTR( x ) static_cast< ostringstream & >( \
        ( ostringstream() << dec << x ) ).str()

int high = 10, wide = 20;

componant_voltage_scource voltage_scource;

void to_x_and_y_position(long int position, long int &x_position, long int &y_position);

int main(){
    voltage_scource.voltage = 2;
    voltage_scource.angular_frequency = 10;
    voltage_scource.offset = 0; 
	voltage_scource.voltage_scourc_in_connect = 0;
	voltage_scource.voltage_scourc_out_connect = 0;
    vector<componant_struct> componants;
    componant_struct temp;
    temp.componant_type = 1;
    temp.componant_in_connect = 81;
    temp.componant_out_connect = 85;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 85;
    temp.componant_out_connect = 89;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 89;
    temp.componant_out_connect = 93;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 5;
    temp.componant_out_connect = 9;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 9;
    temp.componant_out_connect = 13;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 1;
    temp.componant_out_connect = 5;
    temp.componant_value_polar = 1;
    temp.componant_value_rectangular = 1;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 13;
    temp.componant_out_connect = 93;
    temp.componant_value_polar = 1;
    temp.componant_value_rectangular = 1;
    componants.push_back(temp);
    temp.componant_type = 3;
    temp.componant_in_connect = 5;
    temp.componant_out_connect = 85;
    temp.componant_value_polar = 1;
    temp.componant_value_rectangular = -0.1;
    componants.push_back(temp);
    temp.componant_type = 4;
    temp.componant_in_connect = 9;
    temp.componant_out_connect = 89;
    temp.componant_value_polar = 1;
    temp.componant_value_rectangular = 10;
    componants.push_back(temp);
    voltage_scource.voltage_scourc_in_connect = 1;
    voltage_scource.voltage_scourc_out_connect = 81;
    cout << analysis(componants, voltage_scource) << endl;
    output(voltage_scource, analysis(componants, voltage_scource));
    cout << endl;
    
    componants.clear();
    temp.componant_type = 1;
    temp.componant_in_connect = 42;
    temp.componant_out_connect = 46;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 46;
    temp.componant_out_connect = 06;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 46;
    temp.componant_out_connect = 86;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 6;
    temp.componant_out_connect = 10;
    temp.componant_value_polar = 31;
    temp.componant_value_rectangular = 31;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 86;
    temp.componant_out_connect = 90;
    temp.componant_value_polar = 19;
    temp.componant_value_rectangular = 19;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 10;
    temp.componant_out_connect = 50;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 90;
    temp.componant_out_connect = 50;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 50;
    temp.componant_out_connect = 54;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    voltage_scource.voltage_scourc_in_connect = 42;
    voltage_scource.voltage_scourc_out_connect = 54;
    cout << analysis(componants, voltage_scource) << endl;
    componants.clear();

    temp.componant_type = 1;
    temp.componant_in_connect = 2;
    temp.componant_out_connect = 6;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 6;
    temp.componant_out_connect = 10;
    temp.componant_value_polar = 27;
    temp.componant_value_rectangular = 27;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 10;
    temp.componant_out_connect = 14;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 14;
    temp.componant_out_connect = 18;
    temp.componant_value_polar = 54;
    temp.componant_value_rectangular = 54;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 18;
    temp.componant_out_connect = 22;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    voltage_scource.voltage_scourc_in_connect = 2;
    voltage_scource.voltage_scourc_out_connect = 22;
    cout << analysis(componants, voltage_scource) << endl;
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
    voltage_scource.voltage_scourc_in_connect = 11;
    voltage_scource.voltage_scourc_out_connect = 16;
    cout << analysis(componants, voltage_scource) << endl;
    componants.clear();

    temp.componant_type = 1;
    temp.componant_in_connect = 51;
    temp.componant_out_connect = 53;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 53;
    temp.componant_out_connect = 33;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 33;
    temp.componant_out_connect = 13;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 33;
    temp.componant_out_connect = 34;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 53;
    temp.componant_out_connect = 54;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 13;
    temp.componant_out_connect = 15;
    temp.componant_value_polar = 3;
    temp.componant_value_rectangular = 3;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 15;
    temp.componant_out_connect = 17;
    temp.componant_value_polar = 5;
    temp.componant_value_rectangular = 5;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 34;
    temp.componant_out_connect = 36;
    temp.componant_value_polar = 7;
    temp.componant_value_rectangular = 7;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 54;
    temp.componant_out_connect = 56;
    temp.componant_value_polar = 9;
    temp.componant_value_rectangular = 9;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 36;
    temp.componant_out_connect = 37;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 56;
    temp.componant_out_connect = 57;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 17;
    temp.componant_out_connect = 37;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 37;
    temp.componant_out_connect = 57;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 57;
    temp.componant_out_connect = 59;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 59;
    temp.componant_out_connect = 79;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 79;
    temp.componant_out_connect = 71;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    voltage_scource.voltage_scourc_in_connect = 51;
    voltage_scource.voltage_scourc_out_connect = 71;
    /*temp.componant_type = 1;
    temp.componant_in_connect = 120;
    temp.componant_out_connect = 135;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;
    componants.push_back(temp);
    temp.componant_type = 2;
    temp.componant_in_connect = 120;
    temp.componant_out_connect = 135;
    temp.componant_value_polar = 7;
    temp.componant_value_rectangular = 7;
    componants.push_back(temp);
    temp.componant_type = 1;
    temp.componant_in_connect = 54;
    temp.componant_out_connect = 71;
    temp.componant_value_polar = 0;
    temp.componant_value_rectangular = 0;*/
    componants.push_back(temp);
    cout << analysis(componants, voltage_scource) << endl;
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