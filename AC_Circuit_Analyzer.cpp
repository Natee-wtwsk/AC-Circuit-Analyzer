#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<complex>
#include<sstream>

#include"analysis.h"

using namespace std;

#define SSTR( x ) static_cast< ostringstream & >( \
        ( ostringstream() << dec << x ) ).str()

//drawing : จิบ
//input และ output : ต้น
//polar_to_rectangular และ rectangular_to_polar : เบส
//analysis : หวาย
//complex_processing : นิว

int high = 10, wide = 20; // ค่าเริ่มต้นของขนาดตาราง

struct componant_struct{
	int componant_type;
	long int componant_in_connect;
	long int componant_out_connect;
	double componant_value_polar;
    double componant_value_rectangular;
    
};

struct componant_voltage_scource{
    double voltage;
    double angular_frequency;
    double offset; 
	long int voltage_scourc_in_connect;
	long int voltage_scourc_out_connect;
};
componant_voltage_scource voltage_scource;

void drawing(string **canvas, vector<componant_struct> componants); // รับข้อมูลเป็น ชนิดอุปกรณ์ ตำแหน่ง(หัวและท้าย(x1 y1 x2 y2))(ชนิดอุปกรณ์:ตำแหน่งy1:ตำแหน่งx1:ตำแหน่งy2:ตำแหน่งx2:ค่าของตัวแปรเช่น 10H(เฮนรี่)) ตัวแปลอุปกรณ์ และวาดออกมาเป็นวงจร
void drawing_add(string **canvas, char []);
void input(string **canvas,vector<componant_struct> componants); // รับข้อมูล ชนิดอุปกรณ์ ตำแหน่ง(หัวและท้าย(x1 y1 x2 y2)) ตัวแปลอุปกรณ์ ลงใน vector<string> componant
//***ไม่ได้ใช้งานแล้ว void polar_to_rectangular(vector<componant_struct> componants); // แปลงค่าของอุปกรณ์ในรูป polar ให้อยู่ในรูป rectangular เช่น 10F เป็น 1/jwF
complex<double> analysis(vector<componant_struct> componants); // วิเคราะห์วงจรโดยอิงค่า Z จาก componant_rectangular และตำแหน่งของอุปกรณ์จาก componant แล้วคืนค่าเป็นค่า Z รวม
//***ไม่ได้ใช้งานแล้ว void complex_processing("ส่งในรูปของ <complex>"); // รับค่า complex จากฟังก์ชัน analysis คำนวน บวก ลบ คูณ หาร และคืนกลับเป็นค่า complex
//void rectangular_to_polar("ส่งในรูปของ <complex>"); // รับค่า complex ในตอนจบของจากฟังก์ชัน analysis แปลงค่าของอุปกรณ์ในรูป rectangular ให้อยู่ในรูป polar (ส่วนกลับของฟังก์ชัน polar_to_rectangular) ดูจากที่ปักหมุดใน Discord
void output(string Z, double angular_frequency_process); // รับค่าความถี่เชิงมุมจากฟังก์ชัน rectangular_to_polar และตัวแปล voltage offset จาก global แล้วนำมาแสดงผลในรูปฟังก์ชัน I = "voltage"cos("angular_frequency"+-"offset") พร้อมทั้งแสดงผลค่าความต้านทานรวมและฟังก์ชันในรูป sinusoid
void to_x_and_y_position(long int position, long int &x_position, long int &y_position);

int main(){
    vector<componant_struct> componants;
    string Z;
    int voltage_source_position = 1;
    cout << "Please Enter AC voltage function (Sinusoids)" << endl;
    cout << "Voltage :";
    cin >> voltage_scource.voltage;
    cout << "angular_frequency :";
    cin >> voltage_scource.angular_frequency;
    cout << "offset :";
    cin >> voltage_scource.offset;
    cout << "Your's function:" << voltage_scource.voltage << "cos(" << voltage_scource.angular_frequency << "t" << voltage_scource.offset << ")" << endl;
    cout << "input your built plate(high wide):";
    cin >> high;
    cin >> wide;
    
    string **canvas = new string*[high];
    for(int i = 0; i < high; i++) canvas[i] = new string[wide];
    drawing(canvas, componants);
    cout << "Place voltage source at:";
    cin >> voltage_source_position;
    canvas[(voltage_source_position-1)/10][(voltage_source_position-1)%10] = "@";
    cout << "voltage scource reference connent to:";
    cin >> voltage_source_position;
    canvas[(voltage_source_position-1)/10][(voltage_source_position-1)%10] = "R";
    drawing(canvas, componants);
    input(canvas, componants);
    
    for(int i = 0; i < high; i++) delete [] canvas[i];
    delete [] canvas;
    return 0;
}

void drawing(string **canvas, vector<componant_struct> componants){
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
void drawing_add(string **canvas,vector<componant_struct> componants){
    int count = 1,sum=1,count1=0;
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){
            sum=(i*10)+j;    
            count1 = componants[i].componant_in_connect;
            if(componants[i].componant_type == 1){
                if(componants[i].componant_in_connect == sum) canvas[i][j-1]="o--";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]="--";
                            count1++;
                        }
                }
                if(componants[i].componant_out_connect == sum)  canvas[i][j-1]="--o"; 
            }
            if(componants[i].componant_type == 2){
                if(componants[i].componant_in_connect== sum) canvas[i][j-1]="o-M";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]="MW";
                            count1++;
                        }
                }
                if(componants[i].componant_out_connect== sum) canvas[i][j-1]= "W-o";
            }
            if(componants[i].componant_type == 3){
                if(componants[i].componant_in_connect== sum)canvas[i][j-1]="o-|";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]="||";
                            count1++;
                        }
                }
                if(componants[i].componant_out_connect== sum)canvas[i][j-1]="|-o";
                    
            }
            if(componants[i].componant_type == 4){
                if(componants[i].componant_in_connect== sum) canvas[i][j-1]= "o-o";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]="oo";
                            count1++;
                        }
                }
                if(componants[i].componant_out_connect== sum)canvas[i][j-1]= "o-o";
            }
        }
    }
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){
            if(canvas[i][j] == "") cout << setw(4) << count;
            else cout << setw(4) << canvas[i][j];
            count++;
        }
        cout << "\n\n";
    }
}

void input(string **canvas, vector<componant_struct> componants){
    while(true){
        componant_struct c;
        for(int i = 0; i < componants.size(); i++){
            cout << i+1 << " " << componants[i].componant_in_connect;
            if(componants[i].componant_type == 1) cout << "o----o";
            if(componants[i].componant_type == 2) cout << "o-MW-o";
            if(componants[i].componant_type == 3) cout << "o-||-o";
            if(componants[i].componant_type == 4) cout << "o-oo-o";
            cout << componants[i].componant_out_connect;
            if(componants[i].componant_value_polar > 0) cout << " Value:" << componants[i].componant_value_polar << endl;
            else cout << endl;
        }
        cout << "pick your componant\n" << "0:finish componant choose\n1:wire (o---o)\n2:resistance (o-MW-o)\n3:capacitor (o-||-o)\n4:inductance (o-oo-o)\n5:remove your pick\npick :";
        cin >> c.componant_type;
        if(c.componant_type == 0) break;
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

            if(c.componant_type == 1) c.componant_value_polar = 0;

            if(c.componant_type > 1){
                cout << "input your componant_value (don't input unit):";
                cin >> c.componant_value_polar;
                if(c.componant_type == 3) c.componant_value_rectangular = voltage_scource.angular_frequency*c.componant_value_polar;
                else if(c.componant_type == 4) c.componant_value_rectangular = 1/(voltage_scource.angular_frequency*c.componant_value_polar);            
            } //กำหนดหน่วยเพื่อป้องกัน Error
            componants.push_back(c);
        }
        else if(c.componant_type == 5){
            unsigned int pick;
            for(int i = 0; i < componants.size(); i++){
                cout << i+1 << " " << componants[i].componant_in_connect;
                if(componants[i].componant_type == 1) cout << "o----o";
                if(componants[i].componant_type == 2) cout << "o-MW-o";
                if(componants[i].componant_type == 3) cout << "o-||-o";
                if(componants[i].componant_type == 4) cout << "o-oo-o";
                cout << componants[i].componant_out_connect;
                if(componants[i].componant_value_polar > 0) cout << " Value:" << componants[i].componant_value_polar << endl;
                else cout << endl;
            }
            cout << "pick componant your like to remove(first number of list) :";
            cin >> pick;
            componants.erase(componants.begin()+pick-1);
        }
        
        else cout << "invalid choice";
        cout << endl;
        drawing_add(canvas, componants);
    }

}//ชนิดอุปกรณ์:ตำแหน่งx1:ตำแหน่งy1:ตำแหน่งx2:ตำแหน่งy2:ค่าของตัวแปรเช่น 10H(เฮนรี่)

void polar_to_rectangular(vector<componant_struct> componants){

}

/*void rectangular_to_polar("ส่งในรูปของ <complex>"){

}*/

void to_x_and_y_position(long int position, long int &x_position, long int &y_position){
    y_position = ceil((double)position/wide);
    x_position = position-((y_position-1)*wide);

    return;
}

void output(string Z, double angular_frequency_process){

}