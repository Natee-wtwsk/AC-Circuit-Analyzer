#ifndef drawing_h
#define drawing_h

#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<vector>
#include<complex>
#include<sstream>
#include<list>

#include"struct.h"

using namespace std;

void drawing_add(string **canvas,vector<componant_struct> &componants, int high, int wide){
    int count = 1,count1=0;
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){    
            count1 = componants[i].componant_in_connect;
            if(componants[i].componant_type == 1){
                if(componants[i].componant_in_connect == (i*10)+j) canvas[i][j-1]="o--";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]="--";
                            count1++;
                        }
                }
                if(componants[i].componant_out_connect == (i*10)+j)  canvas[i][j-1]="--o"; 
            }
            if(componants[i].componant_type == 2){
                if(componants[i].componant_in_connect== (i*10)+j) canvas[i][j-1]="o-M";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]="MW";
                            count1++;
                        }
                }
                if(componants[i].componant_out_connect== (i*10)+j) canvas[i][j-1]= "W-o";
            }
            if(componants[i].componant_type == 3){
                if(componants[i].componant_in_connect== (i*10)+j)canvas[i][j-1]="o-|";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]="||";
                            count1++;
                        }
                }
                if(componants[i].componant_out_connect== (i*10)+j)canvas[i][j-1]="|-o";
                    
            }
            if(componants[i].componant_type == 4){
                if(componants[i].componant_in_connect== (i*10)+j) canvas[i][j-1]= "o-o";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]="oo";
                            count1++;
                        }
                }
                if(componants[i].componant_out_connect== (i*10)+j)canvas[i][j-1]= "o-o";
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

void drawing(string **canvas, vector<componant_struct> &componants, int high, int wide){
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
/*bool chack_drawing(string **canvas, vector<componant_struct> &componants, int high, int wide){
    int count = 1;
    list<int> componants_connect = {0,0};
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){
          if(componants_connect.empty){
            componants_connect.pop_back(componants[i].componant_in_connect);
            break;
            }

        }
    }
}*/


#endif