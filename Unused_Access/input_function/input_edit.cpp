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
int high = 10, wide = 20; // ค่าเริ่มต้นของขนาดตาราง

void input(string **canvas, vector<string> componant){
    string componant_type, componant_value,componant_value_unit, combin;
    string position_x1, position_y1, position_x2, position_y2;
    while(true){
        componant_type = "", componant_value = "", combin = "";
        position_x1 = "", position_y1 = "", position_x2 = "", position_y2 = "";
        for(int i = 0; i < componant.size(); i++) cout << i+1 << " " << componant[i] << endl;
        cout << "pick your componant\n" << "0:finish componant choose\n1:wire (o---o)\n2:resistance (o-w-o)\n3:capacitor (o-||-o)\n4:inductance (o-oo-o)\n5:remove your pick\npick :";
        cin >> componant_type;
        if(componant_type == "0") break;
        if(componant_type != "5"){
            cout << "pick first connect point and the point that it connect to (position x1,y1 and position x2,y2)"<<endl;
            cout << "Your x1 position : ";
            cin >> position_x1;
            cout << "Your y1 position : ";
            cin >> position_y1;
            cout << "Your x2 position : ";
            cin >> position_x2;
            cout << "Your y2 position : ";
            cin >> position_y2;
            //แยกให้กรอก x,y ทีละค่าเพื่อป้องกันเกิดการสับสน

            if(position_x1 == position_x2 & position_y1 == position_y2){
                cout<<"Can't use the same position";
                continue;
            }//กรณีกรอกจุด1กับจุด2เป็นจุดเดียวกัน
            
            if(atof(position_x1.c_str())*atof(position_y1.c_str()) > high*wide || atof(position_x2.c_str())*atof(position_y2.c_str()) > high*wide){
                cout << "Error off canvas limit" << endl;
                continue;
            } //กรณีเกินตาราง

            if(componant_type > "1" & componant_type < "5"){
                cout << "input your componant_value (don't input unit):";
                cin >> componant_value;

                if(componant_type == "2"){
                    componant_value_unit = "OHM";
                }
                else if(componant_type == "3"){
                    componant_value_unit = "F";
                }
                else if(componant_type == "4"){
                    componant_value_unit = "H";
                }
            } //กำหนดหน่วยเพื่อป้องกัน Error

            if(componant_type == "1"){
                componant.push_back(componant_type+":"+position_x1+":"+position_y1+":"+position_x2+":"+position_y2);//กรณีเป็น wire ไม่มีvalue+uinit
            }else
                componant.push_back(componant_type+":"+position_x1+":"+position_y1+":"+position_x2+":"+position_y2+": "+componant_value+componant_value_unit);     
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

}//ชนิดอุปกรณ์:ตำแหน่งx1:ตำแหน่งy1:ตำแหน่งx2:ตำแหน่งy2:ค่าของตัวแปรเช่น 10H(เฮนรี่)

int main(){


    return 0 ;
}