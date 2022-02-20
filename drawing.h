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

long int x_position, y_position;

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

void to_x_and_y_position(long int position, long int &x_position, long int &y_position,int high, int wide){
    y_position = ceil((double)position/wide);
    x_position = position-((y_position-1)*wide);
}

void drawing_add(string **canvas,vector<componant_struct> &componants, int high, int wide){
    int count = 1,count1=0;
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){    
            count1 = componants[i].componant_in_connect;
            if(componants[i].componant_type == 1){
                to_x_and_y_position(componants[i].componant_in_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]="o--";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]="--";
                            count1++;
                        }
                }
                to_x_and_y_position(componants[i].componant_out_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]="--o"; 
            }
            if(componants[i].componant_type == 2){
                to_x_and_y_position(componants[i].componant_in_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]="o-M";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]="MW";
                            count1++;
                        }
                }
                to_x_and_y_position(componants[i].componant_out_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]= "W-o";
            }
            if(componants[i].componant_type == 3){
                to_x_and_y_position(componants[i].componant_in_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]="o-|";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]="||";
                            count1++;
                        }
                }
                to_x_and_y_position(componants[i].componant_out_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]="|-o";
                    
            }
            if(componants[i].componant_type == 4){
                to_x_and_y_position(componants[i].componant_in_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]= "o-o";
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]= "oo";
                            count1++;
                        }
                }
                to_x_and_y_position(componants[i].componant_out_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]= "o-o";
            }
            if(componants[i].componant_type == 5){
                to_x_and_y_position(componants[i].componant_in_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]=componants[i].componant_in_connect ;
                if(componants[i].componant_out_connect-count1 !=1){
                        while (componants[i].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]= count1 ;
                            count1++;
                        }
                }
                to_x_and_y_position(componants[i].componant_out_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]= componants[i].componant_out_connect;
            }
        }
    }
   drawing(canvas, componants, high, wide);
}

void drawing_remove(string **canvas,vector<componant_struct> &componants, int high, int wide,int pick){
    int count = 1,count1=0;
    cout<<componants[pick].componant_type<<" "<<componants[pick].componant_in_connect<<" "<<componants[pick].componant_out_connect<<'\n';
            if(componants[pick].componant_type == 5){
                to_x_and_y_position(componants[pick].componant_in_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]=componants[pick].componant_in_connect ;
                if(componants[pick].componant_out_connect-count1 !=1){
                        while (componants[pick].componant_out_connect-count1 > 1){
                            canvas[(count1)/10][(count1)%10]= count1 ;
                            count1++;
                        }
                }
                to_x_and_y_position(componants[pick].componant_out_connect, x_position, y_position, high, wide);
                canvas[y_position-1][x_position-1]= componants[pick].componant_out_connect;
            }
        
    
     drawing(canvas, componants, high, wide);
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