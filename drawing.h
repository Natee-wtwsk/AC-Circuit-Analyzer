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

void drawing_add(string **canvas,vector<componant_struct> &componants, int high, int wide){
    long int x1,y1,x2,y2,count = 1,count1=0,Medaim1,Medaim2;
    swap(componants, high, wide);
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){    
            to_x_and_y_position(componants[i].componant_in_connect, x1, y1, high, wide);
                to_x_and_y_position(componants[i].componant_out_connect, x2, y2, high, wide);
            count1 = componants[i].componant_in_connect;
                if((x2-x1)%2==0||((y2-y1)%2==0)){
                    Medaim1 = (x2-x1)/2;
                    Medaim2 = (y2-y1)/2;
                }else{
                    Medaim1 = ((x2-x1)+1)/2;
                    Medaim2 = ((y2-y1)+1/2);}

            if(componants[i].componant_type == 1){
                if(y1==y2){
                    canvas[y1-1][x1-1]="o";
                    if(x2-x1 !=1){
                            for(long int i = x1 ;x1 < x2;i++){
                                canvas[y1-1][x1]="--";
                                x1++;
                            }
                        }

                    canvas[y2-1][x2-1]="o"; 
                }else if(x1==x2){
                    canvas[y1-1][x1-1]="o";
                    if(y2-y1 !=1){
                            for(long int i = y1 ;y1 < y2;i++){
                                canvas[y1][x1-1]="|";
                                y1++;
                            }
                        }

                    canvas[y2-1][x2-1]="o"; 
                }
            }
            if(componants[i].componant_type == 2){
                cout<<y1<<" "<<x1<<" "<<y2<<" "<<x2<<" "<<'\n';
                if(y1==y2){
                    canvas[y1-1][x1-1]="o-M";
                    canvas[y2-1][x2-1]="W-o";
                    if(x2-x1 !=1){
                            canvas[y1-1][x1-1]="o";
                            for(long int i = x1 ;x1 < x2;i++){
                                canvas[y1-1][x1]="--";
                                if(x2-x1 == Medaim1)canvas[y1-1][x1-1]="MW";
                                x1++;
                            }
                            canvas[y2-1][x2-1]="o";
                        }

                }else if(x1==x2){
                    canvas[y1-1][x1-1]="o";
                    if(y1-y2 !=1){
                           for(long int i = y1 ;y1 < y2;i++){
                                canvas[y1][x1-1]="|";
                                if(y2-y1 == Medaim2)canvas[y1-1][x1-1]="MW";
                                y1++;
                            }
                        }

                    canvas[y2-1][x2-1]="o"; 
                }
            }
            if(componants[i].componant_type == 3){
                if(y1==y2){
                    canvas[y1-1][x1-1]="o-|";
                    canvas[y2-1][x2-1]="|-o"; 
                    if(x2-x1 !=1){
                        canvas[y1-1][x1-1]="o";
                            for(long int i = x1 ;x1 < x2;i++){
                                canvas[y1-1][x1]="--";
                                if(x2-x1 == Medaim1)canvas[y1-1][x1]="||";
                                x1++;
                            }
                        canvas[y2-1][x2-1]="o"; 
                        }
                }else if(x1==x2){
                    canvas[y1-1][x1-1]="o";
                    if(y1-y2 !=1){
                             for(long int i = y1 ;y1 < y2;i++){
                                canvas[y1][x1-1]="|";
                                 if(y2-y1 == Medaim2)canvas[y1][x1-1]="||";
                                y1++;
                        }

                    canvas[y2-1][x2-1]="o"; 
                    }
                }

            } 
            if(componants[i].componant_type == 4){
                if(y1==y2){
                    canvas[y1-1][x1-1]="o-o";
                    canvas[y2-1][x2-1]="o-o"; 
                    if(x2-x1 !=1){
                        canvas[y1-1][x1-1]="o";
                           for(long int i = x1 ;x1 < x2;i++){
                                canvas[y1-1][x1]="--";
                                if(x2-x1 == Medaim1)canvas[y1-1][x1]="oo";
                                x1++;
                            }
                        canvas[y2-1][x2-1]="o"; 
                        }
                }else if(x1==x2){
                    canvas[y1-1][x1-1]="o";
                    if(y1-y2 !=1){
                           for(long int i = y1 ;y1 < y2;i++){
                                canvas[y1][x1-1]="|";
                                 if(y2-y1 == Medaim2)canvas[y1][x1-1]="oo";
                                y1++;
                            }
                        }
                    canvas[y2-1][x2-1]="o"; 
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
                    canvas[y1-1][x1-1]="";
                    if(x2-x1 !=1){
                           for(long int i = x1 ;x1 < x2;i++){
                                canvas[y1-1][x1]="";
                                x1++;
                            }
                        }

                    canvas[y2-1][x2-1]=""; 
                }else if(x1==x2){
                    canvas[y1-1][x1-1]="";
                    if(y1-y2 !=1){
                            for(long int i = y1 ;y1 < y2;i++){
                                canvas[y1][x1-1]="";
                                y1++;
                            }
                        }

                    canvas[y2-1][x2-1]=""; 
                }
}    



#endif


/*if(componants[i].componant_type > 1){
                to_x_and_y_position(componants[i].componant_in_connect, x1, y1, high, wide);
                to_x_and_y_position(componants[i].componant_out_connect, x2, y2, high, wide);
                if(y1==y2){
                    canvas[y1-1][x1-1]="o--";
                    if(componants[i].componant_out_connect-count1 !=1){
                            while (componants[i].componant_out_connect-count1 > 1){
                                canvas[(count1)/10][(count1)%10]="--";
                                   if(componants[i].componant_type == 2){
                                    if(count1-(componants[i].componant_in_connect-1) == Medaim){canvas[(count1)/10][(count1)%10]="MW";}
                                }
                                 if(componants[i].componant_type == 3){
                                    if(count1-(componants[i].componant_in_connect-1) == Medaim){canvas[(count1)/10][(count1)%10]="||";}
                                }
                                 if(componants[i].componant_type == 4){
                                    if(count1-(componants[i].componant_in_connect-1) == Medaim){canvas[(count1)/10][(count1)%10]="oo";}
                                }
                                count1++;
                            }
                        }

                    canvas[y2-1][x2-1]="--o"; 
                }else if(x1==x2){
                    canvas[y1-1][x1-1]="o";
                    if(y1-y2 !=1){
                            while (componants[i].componant_out_connect-count1 > 0){
                                count1+=wide;
                                canvas[(count1-1)/10][(count1-1)%10]="|";
                                if(componants[i].componant_type == 2){
                                    if(count1-componants[i].componant_in_connect == Medaim){canvas[(count1-1)/10][(count1-1)%10]="MW";}}
                                if(componants[i].componant_type == 3){
                                    if(count1-componants[i].componant_in_connect == Medaim){canvas[(count1-1)/10][(count1-1)%10]="||";}}
                                 if(componants[i].componant_type == 4){
                                    if(count1-componants[i].componant_in_connect == Medaim){canvas[(count1-1)/10][(count1-1)%10]="oo";}}
                            }
                        }

                    canvas[y2-1][x2-1]="o"; 
                }
            }*/