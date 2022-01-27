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

void drawing(string **canvas, vector<string>  componant); // รับข้อมูลเป็น ชนิดอุปกรณ์ ตำแหน่ง(หัวและท้าย(x1 y1 x2 y2))(ชนิดอุปกรณ์:ตำแหน่งy1:ตำแหน่งx1:ตำแหน่งy2:ตำแหน่งx2:ค่าของตัวแปรเช่น 10H(เฮนรี่)) ตัวแปลอุปกรณ์ และวาดออกมาเป็นวงจร
void input(string **canvas,vector<string> componant); // รับข้อมูล ชนิดอุปกรณ์ ตำแหน่ง(หัวและท้าย(x1 y1 x2 y2)) ตัวแปลอุปกรณ์ ลงใน vector<string> componant
void polar_to_rectangular(vector<string> componant, vector<string> componant_rectangular); // แปลงค่าของอุปกรณ์ในรูป polar ให้อยู่ในรูป rectangular เช่น 10F เป็น 1/jwF
void analysis(vector<string> componant, vector<string> componant_rectangular); // วิเคราะห์วงจรโดยอิงค่า Z จาก componant_rectangular และตำแหน่งของอุปกรณ์จาก componant แล้วคืนค่าเป็นค่า Z รวม
//void complex_processing("ส่งในรูปของ <complex>"); // รับค่า complex จากฟังก์ชัน analysis คำนวน บวก ลบ คูณ หาร และคืนกลับเป็นค่า complex
//void rectangular_to_polar("ส่งในรูปของ <complex>"); // รับค่า complex ในตอนจบของจากฟังก์ชัน analysis แปลงค่าของอุปกรณ์ในรูป rectangular ให้อยู่ในรูป polar (ส่วนกลับของฟังก์ชัน polar_to_rectangular) ดูจากที่ปักหมุดใน Discord
void output(string Z, double angular_frequency_process); // รับค่าความถี่เชิงมุมจากฟังก์ชัน rectangular_to_polar และตัวแปล voltage offset จาก global แล้วนำมาแสดงผลในรูปฟังก์ชัน I = "voltage"cos("angular_frequency"+-"offset") พร้อมทั้งแสดงผลค่าความต้านทานรวมและฟังก์ชันในรูป sinusoid

int main(){
    vector<string> componant;
    vector<string> componant_rectangular;
    string Z;
    int voltage_source_position = 1;
    cout << "Please Enter AC voltage function (Sinusoids)" << endl;
    cout << "Voltage :";
    cin >> voltage;
    cout << "angular_frequency :";
    cin >> angular_frequency;
    cout << "offset :";
    cin >> offset;
    cout << "Your's function:" << voltage << "cos(" << angular_frequency << "t" << offset << ")" << endl;
    cout << "input your built plate(high wide):";
    cin >> high;
    cin >> wide;
    
    string **canvas = new string*[high];
    for(int i = 0; i < high; i++) canvas[i] = new string[wide];
    drawing(canvas, componant);
    cout << "Place voltage source at:";
    cin >> voltage_source_position;
    canvas[(voltage_source_position-1)/10][(voltage_source_position-1)%10] = "@";
    cout << "voltage scource reference connent to:";
    cin >> voltage_source_position;
    canvas[(voltage_source_position-1)/10][(voltage_source_position-1)%10] = "R";
    drawing(canvas, componant);
    input(canvas, componant);
    
    for(int i = 0; i < high; i++) delete [] canvas[i];
    delete [] canvas;
    return 0;
}

void drawing(string **canvas, vector<string>  componant){
    int count = 1;
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){
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
            if(atof(position_x1.c_str())*atof(position_y1.c_str()) > high*wide || atof(position_x2.c_str())*atof(position_y2.c_str()) > high*wide){
                cout << "Error off canvas limit" << endl;
                continue;
            }
            cout << "input your componant_value(value follow by unit) :";
            cin >> componant_value;
            componant.push_back(componant_type+":"+position_x1+":"+position_y1+":"+position_x2+":"+position_y2+":"+componant_value);
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
    
    //ชนิดอุปกรณ์:ตำแหน่งx1:ตำแหน่งy1:ตำแหน่งx2:ตำแหน่งy2:ค่าของตัวแปรเช่น 10H(เฮนรี่)
}
//void drawing_prossing(string **canvas)