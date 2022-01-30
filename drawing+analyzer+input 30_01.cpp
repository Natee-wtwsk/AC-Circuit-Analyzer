#include<iostream>
#include<cmath>
#include<vector>
#include<string>
#include<iomanip>
#include<complex>
#include<sstream>

using namespace std;

#define SSTR( x ) static_cast< ostringstream & >( \
        ( ostringstream() << dec << x ) ).str()

double voltage;
double angular_frequency;
double offset; 
int high = 10, wide = 10;

void input(string **canvas, vector<string> componant);
void drawing(string **canvas, vector<string>  componant);
void drawing0(string **canvas, vector<string>  componant);
void drawing_add(string **canvas, char []);
void analysis(string **canvas, vector<string> componant, vector<string> componant_rectangular);

int main(){
    vector<string> componant;
    vector<string> componant_rectangular;
    int voltage_source_position = 1;

    string **canvas = new string*[high];
    for(int i = 0; i < high; i++) canvas[i] = new string[wide];
    drawing(canvas, componant);

    cout << "Place voltage source at:";
    cin >> voltage_source_position;
    canvas[(voltage_source_position-1)/10][(voltage_source_position-1)%10] = "@";
    cout << "voltage scource reference connent to:";
    cin >> voltage_source_position;
    canvas[(voltage_source_position-1)/10][(voltage_source_position-1)%10] = "G";
    drawing(canvas, componant);
    input(canvas, componant);

    /*cout << "Hi1" << endl;
    componant.push_back("1:0:1:0:2:0");
    cout << "Hi2" << endl;
    componant.push_back("2:0:3:0:4:5");
    componant.push_back("1:0:5:1:5:0");
    componant.push_back("3:2:5:3:5:1");
    componant.push_back("1:4:4:4:5:0");
    componant.push_back("1:4:2:4:3:0");
    componant.push_back("1:3:1:4:1:0");
    componant.push_back("1:1:6:1:7:0");
    componant.push_back("3:2:7:3:7:1");
    componant.push_back("1:4:6:4:7:0");
    componant.push_back("1:2:1:3:1:0");*/
    analysis(canvas, componant, componant_rectangular);
    cout << "Hi" << endl;

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

void drawing0(string **canvas, vector<string>  componant ){
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){
            if(canvas[i][j] == "") cout << setw(4) << "0";
            else cout << setw(4) << canvas[i][j];
        }
        cout << "\n\n";
    }
}

void drawing_add(string **canvas,char componant[]){
    int count = 1,type,x1,y1,x2,y2,value,a,R1=1,R2=1;
    char format [] = "%d %d:%d:%d:%d:%d:%d";
    sscanf(componant,format,&a,&type,&x1,&y1,&x2,&y2,&value);
    R1=(x1*10)+y1;
    R2=(x2*10)+y2;
    cout <<"new circuit :"<<"\n";
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){
            if(type == 1){
                canvas[(R1-1)/10][(R1-1)%10] = "o--";
                canvas[(R2-1)/10][(R2-1)%10] = "--o";
                if(canvas[i][j] == "") cout << setw(4) << count;
                else cout << setw(4) << canvas[i][j];
            }
            if(type == 2){
                canvas[(R1-1)/10][(R1-1)%10] = "o-w";
                canvas[(R2-1)/10][(R2-1)%10] = "w-o";
                if(canvas[i][j] == "") cout << setw(4) << count;
                else cout << setw(4) << canvas[i][j];
            }
            if(type == 3){
                canvas[(R1-1)/10][(R1-1)%10] = "o-|";
                canvas[(R2-1)/10][(R2-1)%10] = "|-o";
                if(canvas[i][j] == "") cout << setw(4) << count;
                else cout << setw(4) << canvas[i][j];
            }
             if(type == 4){
                canvas[(R1-1)/10][(R1-1)%10] = "o-o";
                canvas[(R2-1)/10][(R2-1)%10] = "o-o";
                if(canvas[i][j] == "") cout << setw(4) << count;
                else cout << setw(4) << canvas[i][j];
            }
            count++;
        }

        cout << "\n\n";
    }
}


void analysis(string **canvas, vector<string> componant, vector<string> componant_rectangular){
    int count = 0, num = 0, type, x1,y1,x2,y2;
    double value;
    char format[] = "%d:%d:%d:%d:%d:%lf";
    for(int i = 0; i < componant.size(); i++){
        const char *text = componant[i].c_str();
        sscanf(text, format, &type, &x1, &y1, &x2, &y2, &value);
        canvas[y1][x1] = SSTR(type).c_str();
        canvas[y2][x2] = SSTR(type).c_str();
    }

    drawing0(canvas, componant_rectangular);
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){ //มีเฉพาะกรณีที่ควรถูกในแคนวาสเท่านั้น
            if(canvas[i][j] != "\0") count++;
        }
    }
    cout << "connect spot = " << num << "\n";
    cout << "ones = " << count << "\n";
    cout << "--------------------------------------------\n";

    return;
}

void input(string **canvas, vector<string> componant){
    int position1, position2;
    string componant_type, componant_value,componant_value_unit, combin;
    int position_x1, position_y1, position_x2, position_y2;
    while(true){
        componant_type = "", componant_value = "", combin = "";
        position_x1 = 0, position_y1 = 0, position_x2 = 0, position_y2 = 0;
        for(int i = 0; i < componant.size(); i++) cout << i+1 << " " << componant[i] << endl;
        cout << "pick your componant\n" << "0:finish componant choose\n1:wire (o---o)\n2:resistance (o-w-o)\n3:capacitor (o-||-o)\n4:inductance (o-oo-o)\n5:remove your pick\npick :";
        cin >> componant_type;
        if(componant_type == "0") break;
        if(componant_type != "5"){
            /*
            cout << "pick first connect point and the point that it connect to (position x1,y1 and position x2,y2)"<<endl;
            cout << "Your x1 position : ";
            cin >> position_x1;
            cout << "Your y1 position : ";
            cin >> position_y1;
            cout << "Your x2 position : ";
            cin >> position_x2;
            cout << "Your y2 position : ";
            cin >> position_y2;
            */
            //แยกให้กรอก x,y ทีละค่าเพื่อป้องกันเกิดการสับสน
            cout << "pick first connect point and the point that it connect to"<<endl;
            cout << "Your In position : ";
            cin >> position1;
            cout << "Your Out position : ";
            cin >> position2;
            position_y1 = position1/wide, position_y2 = position2/wide;
            position_x1 = position1%position_y1, position_x2 = position2%position_y2;
            cout << position_x1 << " " << position_y1 << " " << position_x2 << " " << position_y2 << endl;

            if(position_x1 == position_x2 & position_y1 == position_y2){
                cout<<"Can't use the same position";
                continue;
            }//กรณีกรอกจุด1กับจุด2เป็นจุดเดียวกัน
            
            if(position1 > high*wide || position2 > high*wide){
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
            /*
            if(componant_type == "1"){
                componant.push_back(componant_type+":"+position_x1+":"+position_y1+":"+position_x2+":"+position_y2);//กรณีเป็น wire ไม่มีvalue+uinit
            }else
                componant.push_back(componant_type+":"+position_x1+":"+position_y1+":"+position_x2+":"+position_y2+": "+componant_value+componant_value_unit);    */ 
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