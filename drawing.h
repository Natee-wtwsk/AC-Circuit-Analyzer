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
/*int CalMedaim(long int in, long int out){    
    double median;
    vector<long int> hWScores;
    size_t size = hWScores.size();
    for(int i = in ;in == out ;i++){
        hWScores.push_back(in);
        in++;}
    if (size % 2 == 0){
      return (hWScores[size / 2 - 1] + hWScores[size / 2]) / 2;
    }else {
      return hWScores[size / 2];
    }

    return median;

}*/
 
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
    long int x1,y1,x2,y2;
    int count = 1,count1=0,count2 = 0;
    swap(componants, high, wide);
    long int Medaim;
    for(int i = 0; i < high; i++){
        for(int j = 0; j < wide; j++){    
            count1 = componants[i].componant_in_connect;
            count2 = componants[i].componant_out_connect;
            //Medaim = CalMedaim(count1,count2);
            if(componants[i].componant_type == 1){
                to_x_and_y_position(componants[i].componant_in_connect, x1, y1, high, wide);
                to_x_and_y_position(componants[i].componant_out_connect, x2, y2, high, wide);
                if(y1==y2){
                    canvas[y1-1][x1-1]="o--";
                    if(componants[i].componant_out_connect-count1 !=1){
                            while (componants[i].componant_out_connect-count1 > 1){
                                canvas[(count1)/10][(count1)%10]="--";
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
                            }
                        }

                    canvas[y2-1][x2-1]="o"; 
                }
            }
            if(componants[i].componant_type == 2){
                to_x_and_y_position(componants[i].componant_in_connect, x1, y1, high, wide);
                to_x_and_y_position(componants[i].componant_out_connect, x2, y2, high, wide);
                if(y1==y2){
                    canvas[y1-1][x1-1]="o-M";
                    if(componants[i].componant_out_connect-count1 !=1){
                            while (componants[i].componant_out_connect-count1 > 1){
                                canvas[(count1)/10][(count1)%10]="--";
                                count1++;
                            }
                        }

                    canvas[y2-1][x2-1]="W-o"; 
                }else if(x1==x2){
                    canvas[y1-1][x1-1]="o";
                    if(y1-y2 !=1){
                            while (componants[i].componant_out_connect-count1 > 0){
                                count1+=wide;
                                canvas[(count1-1)/10][(count1-1)%10]="MW";
                            }
                        }

                    canvas[y2-1][x2-1]="o"; 
                }
            }
            if(componants[i].componant_type == 3){
                to_x_and_y_position(componants[i].componant_in_connect, x1, y1, high, wide);
                to_x_and_y_position(componants[i].componant_out_connect, x2, y2, high, wide);
                if(y1==y2){
                    canvas[y1-1][x1-1]="o-|";
                    if(componants[i].componant_out_connect-count1 !=1){
                            while (componants[i].componant_out_connect-count1 > 1){
                                canvas[(count1)/10][(count1)%10]="||";
                                count1++;
                            }
                        }

                    canvas[y2-1][x2-1]="|-o"; 
                }else if(x1==x2){
                    canvas[y1-1][x1-1]="o";
                    if(y1-y2 !=1){
                            while (componants[i].componant_out_connect-count1 > 0){
                                count1+=wide;
                                canvas[(count1-1)/10][(count1-1)%10]="||";
                            }
                        }

                    canvas[y2-1][x2-1]="o"; 
                }       
            }
            if(componants[i].componant_type == 4){
                to_x_and_y_position(componants[i].componant_in_connect, x1, y1, high, wide);
                to_x_and_y_position(componants[i].componant_out_connect, x2, y2, high, wide);
                if(y1==y2){
                    canvas[y1-1][x1-1]="o-o";
                    if(componants[i].componant_out_connect-count1 !=1){
                            while (componants[i].componant_out_connect-count1 > 1){
                                canvas[(count1)/10][(count1)%10]="oo";
                                count1++;
                            }
                        }

                    canvas[y2-1][x2-1]="o-o"; 
                }else if(x1==x2){
                    canvas[y1-1][x1-1]="o";
                    if(y1-y2 !=1){
                            while (componants[i].componant_out_connect-count1 > 0){
                                count1+=wide;
                                canvas[(count1-1)/10][(count1-1)%10]="oo";
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
                    if(componants[pick-1].componant_out_connect-count1 !=1){
                            while (componants[pick-1].componant_out_connect-count1 > 1){
                                canvas[(count1)/10][(count1)%10]="";
                                count1++;
                            }
                        }

                    canvas[y2-1][x2-1]=""; 
                }else if(x1==x2){
                    canvas[y1-1][x1-1]="";
                    if(y1-y2 !=1){
                            while (componants[pick-1].componant_out_connect-count1 > 1){
                                count1+=wide;
                                canvas[(count1-1)/10][(count1-1)%10]="";
                            }
                        }

                    canvas[y2-1][x2-1]=""; 
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