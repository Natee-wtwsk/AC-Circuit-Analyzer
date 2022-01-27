#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<complex>
using namespace std;

double voltage;
double angular_frequency;
double offset;
int high = 10, wide = 20;

void input(string **,vector<string>);
void drawing(string **);
void drawing_prossing(string **);
void rectangulartopolar(double,double,double); // convert rectangular function to polar from
void output();

int main(){
    vector<string> componant;
    int voltage_source_position = 1;
    /*cout << "Please Enter AC voltage function (Sinusoids)" << endl;
    cout << "Voltage :";
    cin >> voltage;
    cout << "angular_frequency :";
    cin >> angular_frequency;
    cout << "offset :";
    cin >> offset;
    cout << "Your's function:" << voltage << "cos(" << angular_frequency << "t" << offset << ")";
    cout << "input your built plate(high wide):";
    cin >> high;
    cin >> wide;*/
    
    string **canvas = new string*[high];
    for(int i = 0; i < high; i++) canvas[i] = new string[wide];
    drawing(canvas);
    cout << "Place voltage source at:";
    cin >> voltage_source_position;
    canvas[(voltage_source_position-1)/10][(voltage_source_position-1)%10] = "@";
    cout << "voltage scource reference connent to:";
    cin >> voltage_source_position;
    canvas[(voltage_source_position-1)/10][(voltage_source_position-1)%10] = "R";
    drawing(canvas);
    input(canvas, componant);
    
    for(int i = 0; i < high; i++) delete [] canvas[i];
    delete [] canvas;
    return 0;
}

void drawing(string **canvas){
    int count = 1;
    for(int i = 0; i < high; i++){
        for(int j = 0;j < wide; j++){
            if(canvas[i][j] == "") cout << setw(4) << count;
            else cout << setw(4) << canvas[i][j];
            count++;
        }
        cout << "\n\n";
    }
}

void input(string **canvas, vector<string> componant){
    string componant_type, componant_value, combin;
    string position_x1, position_y1, position_x2, position_y2;
    while(true){
        componant_type = "", componant_value = "", combin = "";
        position_x1 = "", position_y1 = "", position_x2 = "", position_y2 = "";
        for(int i = 0; i < componant.size(); i++) cout << i+1 << " " << componant[i] << endl;
        cout << "pick your componant\n" << "0:finish componant choose\n1:wire (o---o)\n2:resistance (o-w-o)\n3:capacitor (o-||-o)\n4:inductance (o-oo-o)\n5:remove your pick\npick :";
        cin >> componant_type;
        if(componant_type == "0") break;
        if(componant_type != "5"){
            cout << "pick first connect point and the point that it connect to (position x,y and position x,y) :";
            cin >> position_x1 >> position_y1 >> position_x2 >> position_y2;
            cout << "input your componant_value(value follow by unit) :";
            cin >> componant_value;
            combin+=(componant_type+":"+position_y1+":"+position_x1+":"+position_y2+":"+position_x2+":"+componant_value);
            componant.push_back(combin);
        }
        else if(componant_type == "5"){
            unsigned int pick;
            for(int i = 0; i < componant.size(); i++) cout << i+1 << " " << componant[i] << endl;
            cout << "pick componant your like to remove(first number of list) :";
            cin >> pick;
            componant.erase(componant.begin()+pick-1);
        }
        else cout << "invalid choice";
        cout << endl;
    }
    
    
    
    //"capacitor : position y : position x : componant value"
}
//void drawing_prossing(string **canvas)