#include <iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<complex>

using namespace std;

int high = 10, wide = 10;
void drawing(string **canvas, vector<string>  componant);
void drawing0(string **canvas, vector<string>  componant);
void drawing_add(string **canvas, char []);
void analysis(string **canvas, char componant[], char componant_rectangular[]);
int main(){
    vector<string> componant;
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
    /*drawing_add(canvas,"1 1:0:1:0:2:0"); 
    drawing_add(canvas,"1 2:0:3:0:4:5");
    drawing_add(canvas,"1 1:0:5:1:5:0");
    drawing_add(canvas,"1 3:2:5:3:5:1"); 
    drawing_add(canvas,"1 1:4:4:4:5:0");
    drawing_add(canvas,"1 1:4:2:4:3:0");
    drawing_add(canvas,"1 1:3:1:4:1:0");
    drawing_add(canvas,"1 1:1:6:1:7:0");
    drawing_add(canvas,"1 3:2:7:3:7:1");
    drawing_add(canvas,"1 1:4:6:4:7:0"); */
    //ทำ array เก็บค่าตำแหน่ง drawing_add แล้วเปลี่ยนให้เป็นค่า 1, else=0 เพื่อหาตำแหน่งวงจรขนาน
    //สายไฟขาด เพราะต้องทำเป็นคู่ ตำแหน่งที่ 21

    cout << "Hi1" << endl;
    analysis(canvas, "1 1:0:1:0:2:0", "100");
    cout << "Hi2" << endl;
    analysis(canvas, "1 2:0:3:0:4:5", "100");
    analysis(canvas, "1 1:0:5:1:5:0", "100");
    analysis(canvas, "1 3:2:5:3:5:1", "100");
    analysis(canvas, "1 1:4:4:4:5:0", "100");
    analysis(canvas, "1 1:4:2:4:3:0", "100");
    analysis(canvas, "1 1:3:1:4:1:0", "100");
    cout << "Hi" << endl;
    analysis(canvas, "1 1:1:6:1:7:0", "100");
    analysis(canvas, "1 3:2:7:3:7:1", "100");
    analysis(canvas, "1 1:4:6:4:7:0", "100");
    analysis(canvas, "1 1:2:1:3:1:0", "100"); //มีจุดซ้ำที่ 31


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


/*
void complex_processing(double real1, double real2, double imag1, double imag2){
    char command;
    complex<double> complex1 = complex<double>(real1, imag1);
    complex<double> complex2 = complex<double>(real2, imag2);
    cout << "command : ";
    cin >> command;
    if(command == '+') cout << complex1 + complex2;
    if(command == '/') cout << complex1/complex2;
}
*/

void analysis(string **canvas, char componant[], char componant_rectangular[]){
    int count = 0,type,x1,y1,x2,y2,value,a,R1=1,R2=1,num=0;
    char format [] = "%d %d:%d:%d:%d:%d:%d";
    sscanf(componant,format,&a,&type,&x1,&y1,&x2,&y2,&value);
    R1=(x1*10)+y1;
    R2=(x2*10)+y2;
    vector<string> comp;

    cout << "position check: " << R1 << " " << R2 << "\n";
    
    canvas[(R1-1)/10][(R1-1)%10] = "1";
    canvas[(R2-1)/10][(R2-1)%10] = "1";
    /*for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){
            //canvas[i][j] = '0';
            canvas[(R1-1)/10][(R1-1)%10] = "1";
            canvas[(R2-1)/10][(R2-1)%10] = "1";
        }
    }*/
    drawing0(canvas, comp);
    
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){ //มีเฉพาะกรณีที่ควรถูกในแคนวาสเท่านั้น
            if(canvas[i][j] == "1"){
                if(canvas[i+1][j] == "1" && canvas[i-1][j] == "1" && canvas[i][j-1] == "0" && canvas[i][j+1] == "1") num++;
                count++;
            }/*
            else if(canvas[(R1-1)/10][(R1-1)%10] == "1"){
                if(canvas[(R2-2)/10][(R2-1)%10] == "1" && canvas[(R2-1)/10][(R2)%10] == "1" && canvas[(R2-1)/10][(R2-2)%10] == "0" && canvas[(R2)/10][(R2-1)%10] == "1") num++;
                count++;
            }*/
        }
    }
    cout << "connect spot = " << num << "\n";
    cout << "ones = " << count << "\n";
    cout << "--------------------------------------------\n";
}

//ยังหาจำนวนจุดเริ่ม-จบของวงจรขนานไม่ได้