#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<complex>
#include<sstream>

#include"struct.h"
#include"input.h"
#include"drawing.h"
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

componant_voltage_scource voltage_scource;

/*void drawing(string **canvas, vector<componant_struct> componants); // รับข้อมูลเป็น ชนิดอุปกรณ์ ตำแหน่ง(หัวและท้าย(x1 y1 x2 y2))(ชนิดอุปกรณ์:ตำแหน่งy1:ตำแหน่งx1:ตำแหน่งy2:ตำแหน่งx2:ค่าของตัวแปรเช่น 10H(เฮนรี่)) ตัวแปลอุปกรณ์ และวาดออกมาเป็นวงจร
void drawing_add(string **canvas, vector<componant_struct> componants);
void input(string **canvas,vector<componant_struct> componants); // รับข้อมูล ชนิดอุปกรณ์ ตำแหน่ง(หัวและท้าย(x1 y1 x2 y2)) ตัวแปลอุปกรณ์ ลงใน vector<string> componant
//***ไม่ได้ใช้งานแล้ว void polar_to_rectangular(vector<componant_struct> componants); // แปลงค่าของอุปกรณ์ในรูป polar ให้อยู่ในรูป rectangular เช่น 10F เป็น 1/jwF
// วิเคราะห์วงจรโดยอิงค่า Z จาก componant_rectangular และตำแหน่งของอุปกรณ์จาก componant แล้วคืนค่าเป็นค่า Z รวม
//***ไม่ได้ใช้งานแล้ว void complex_processing("ส่งในรูปของ <complex>"); // รับค่า complex จากฟังก์ชัน analysis คำนวน บวก ลบ คูณ หาร และคืนกลับเป็นค่า complex
//void rectangular_to_polar("ส่งในรูปของ <complex>"); // รับค่า complex ในตอนจบของจากฟังก์ชัน analysis แปลงค่าของอุปกรณ์ในรูป rectangular ให้อยู่ในรูป polar (ส่วนกลับของฟังก์ชัน polar_to_rectangular) ดูจากที่ปักหมุดใน Discord
void output(string Z, double angular_frequency_process); // รับค่าความถี่เชิงมุมจากฟังก์ชัน rectangular_to_polar และตัวแปล voltage offset จาก global แล้วนำมาแสดงผลในรูปฟังก์ชัน I = "voltage"cos("angular_frequency"+-"offset") พร้อมทั้งแสดงผลค่าความต้านทานรวมและฟังก์ชันในรูป sinusoid
*/void to_x_and_y_position(long int position, long int &x_position, long int &y_position);

int main(){
    long int x_position, y_position;
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
    //drawing(canvas, componants);

    cout << "Place voltage source at:";
    cin >> voltage_source_position;
    to_x_and_y_position(voltage_source_position, x_position, y_position);
    canvas[y_position-1][x_position-1] = "@";
    cout << "voltage scource reference connent to:";
    cin >> voltage_source_position;
    to_x_and_y_position(voltage_source_position, x_position, y_position);
    canvas[y_position-1][x_position-1] = "R";

    drawing(canvas, componants, high, wide);
    input(voltage_scource, canvas, componants, high, wide);
    cout << analysis(componants);
    
    for(int i = 0; i < high; i++) delete [] canvas[i];
    delete [] canvas;
    return 0;
}

void to_x_and_y_position(long int position, long int &x_position, long int &y_position){
    y_position = ceil((double)position/wide);
    x_position = position-((y_position-1)*wide);

    return;
}

void output(string Z, double angular_frequency_process){

}