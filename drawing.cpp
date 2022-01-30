#include <iostream>
#include<vector>
#include<string>
#include<iomanip>

using namespace std;

int high = 10, wide = 10;
void drawing(string **canvas, vector<string>  componant);
void drawing_add(string **canvas, char []);
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
    drawing_add(canvas,"1 2:2:3:2:4:12");
    drawing_add(canvas,"1 3:4:5:4:6:12");
    drawing_add(canvas,"1 4:3:7:3:8:12");
    drawing_add(canvas,"1 1:2:8:2:9:12");

    for(int i = 0; i < high; i++) delete [] canvas[i];
    delete [] canvas;

    return 0;
}

void drawing(string **canvas, vector<string>  componant ){
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
void drawing_add(string **canvas,char componant[]){
    int count = 1,type,x1,y1,x2,y2,value,a,R1=1,R2=1;
    char format [] = "%d %d:%d:%d:%d:%d:%d";
    sscanf(componant,format,&a,&type,&x1,&y1,&x2,&y2,&value);
    R1=(x1*10)+y1;
    R2=(x2*10)+y2;
    cout<<R1<<" "<<R2;
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
                /*canvas[(x1-1)/10][(y1-1)%10] = "o-o";
                canvas[(x2-1)/10][(y2-1)%10] = "o-o";
                if(canvas[i][j] == "") cout << setw(4) << count;
                else if(canvas[i][j] ==canvas[x1][y1]) cout << canvas[i][j];
                else cout << setw(4) << canvas[i][j];*/
               /* canvas[x1][y1-1] = "o--";
                canvas[x2][y2-1] = "--o";
                if(canvas[i][j] ==canvas[x1][0]||canvas[i][j] ==canvas[x2][0]) {
                    canvas[x1][y1] = "o--";
                    canvas[x2][y2] = "--o";}
                if(canvas[i][j] == "") cout << setw(4) << count;
                else if(canvas[i][j] ==canvas[x1][y1]) cout << canvas[i][j];
                else cout << setw(4) << canvas[i][j];*/