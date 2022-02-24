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
#include <algorithm>

#include"struct.h"

using namespace std;

void swap(vector<componant_struct> &componants, int high, int wide){
    long int  A;
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){ 
            if(componants[i].componant_in_connect>componants[i].componant_out_connect){
                A = componants[i].componant_in_connect;
                componants[i].componant_in_connect = componants[i].componant_out_connect;
                componants[i].componant_out_connect = A;
            }
        } 
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

void to_x_and_y_position(long int position, long int &x_position, long int &y_position,int high, int wide){
    y_position = ceil((double)position/wide);
    x_position = position-((y_position-1)*wide);
}
void calMedaim(long int x1,long int y1,long int x2,long int y2,long int &M1,long int &M2){
    if((x2-x1)%2==0||((y2-y1)%2==0)){
                    M1 = (x2-x1)/2;
                    M2 = (y2-y1)/2;
                }else{
                    M1 = ((x2-x1)+1)/2;
                    M2 = ((y2-y1)+1/2);}

}
void RunE1(string **canvas,int type,long int &x1,long int &y1,long int &x2,long int &y2,long int M1){
        canvas[y1-1][x1-1]="o";
        for(long int i = x1 ;x1 < x2;i++){
            canvas[y1-1][x1]="--";
                if(x2-x1 == M1){
                    if(type == 2)canvas[y1-1][x1-1]="MW";
                    if(type == 3)canvas[y1-1][x1-1]="||";
                    if(type == 4)canvas[y1-1][x1-1]="oo";
            }

        x1++;
        }
        canvas[y2-1][x2-1]="o";

}
void RunE2(string **canvas,int type,long int &x1,long int &y1,long int &x2,long int &y2,long int M2){
          canvas[y1-1][x1-1]="o";
                for(long int i = y1 ;y1 < y2;i++){
                    canvas[y1][x1-1]="|";
                    if(y2-y1 == M2){
                        if(type == 2)canvas[y1-1][x1-1]="MW";
                        if(type == 3)canvas[y1-1][x1-1]="||";
                        if(type == 4)canvas[y1-1][x1-1]="oo";
                    }
                    y1++;
            }
        canvas[y2-1][x2-1]="o"; 
}

void drawing_add(string **canvas,vector<componant_struct> &componants, int high, int wide){
    long int x1,y1,x2,y2,count = 1,count1=0,Medaim1,Medaim2;
    int type;
    swap(componants, high, wide);
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){    
            to_x_and_y_position(componants[i].componant_in_connect, x1, y1, high, wide);
            to_x_and_y_position(componants[i].componant_out_connect, x2, y2, high, wide);
            count1 = componants[i].componant_in_connect;
            calMedaim(x1,y1,x2,y2,Medaim1,Medaim2);
            type = componants[i].componant_type;
            if(componants[i].componant_type == 1){
                if(y1==y2){
                    canvas[y1-1][x1-1]="o";
                            for(long int i = x1 ;x1 < x2;i++){
                                canvas[y1-1][x1]="--";
                                x1++;
                            }

                    canvas[y2-1][x2-1]="o"; 
                }else if(x1==x2){
                    canvas[y1-1][x1-1]="o";
                            for(long int i = y1 ;y1 < y2;i++){
                                canvas[y1][x1-1]="|";
                                y1++;
                            }
                    canvas[y2-1][x2-1]="o"; 
                }
            }
            if(componants[i].componant_type == 2){
                if(y1==y2){
                    canvas[y1-1][x1-1]="o-M";
                    canvas[y2-1][x2-1]="W-o";
                    if(x2-x1 !=1){
                        RunE1(canvas,type,x1,y1,x2,y2,Medaim1);
                    }
                }else if(x1==x2){
                        RunE2(canvas,type,x1,y1,x2,y2,Medaim2); 
                }
            }
            if(componants[i].componant_type == 3){
                if(y1==y2){
                    canvas[y1-1][x1-1]="o-|";
                    canvas[y2-1][x2-1]="|-o"; 
                    if(x2-x1 !=1){
                        RunE1(canvas,type,x1,y1,x2,y2,Medaim1);
                        }
                }else if(x1==x2){
                        RunE2(canvas,type,x1,y1,x2,y2,Medaim2); 
                }

            } 
            if(componants[i].componant_type == 4){
                if(y1==y2){
                    canvas[y1-1][x1-1]="o-o";
                    canvas[y2-1][x2-1]="o-o"; 
                    if(x2-x1 !=1){  
                        RunE1(canvas,type,x1,y1,x2,y2,Medaim1);
                    }
                }else if(x1==x2){
                        RunE2(canvas,type,x1,y1,x2,y2,Medaim2); 
                }
            }   
           
        }
            
    }
    
   drawing(canvas, componants, high, wide);
}

void drawing_remove(string **canvas,vector<componant_struct> &componants, int high, int wide,int pick){
    int count = 1,count1=0;
    long int x1,y1,x2,y2;
                to_x_and_y_position(componants[pick-1].componant_in_connect, x1, y1, high, wide);
                to_x_and_y_position(componants[pick-1].componant_out_connect, x2, y2, high, wide);
                if(y1==y2){
                           for(long int i = x1 ;x1 <=x2;i++){
                                canvas[y1-1][x1]="";
                                x1++;
                            }
                }else if(x1==x2){
                            for(long int i = y1 ;y1 <= y2;i++){
                                canvas[y1][x1-1]="";
                                y1++;
                            }
                        }
                drawing(canvas, componants, high, wide);
    }
    



#endif