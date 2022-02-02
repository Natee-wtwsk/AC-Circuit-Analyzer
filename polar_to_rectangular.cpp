#include<vector>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

//double angular_frequency = 50;

int main(/*int argc, double angular_frequency, vector<string> componant, vector<string> componant_rectangular*/){
    ostringstream send_back;
    //vector<string> componant;
    //vector<string> componant_rectangular;
    char format[] = "%lf%s";
    double value;
    char type;
    //componant.push_back("1:1:1:1:1:10C");
    int start = 0, end = 0;
    for(int i = 0; i < componant.size(); i++){
        end = componant[i].find_first_of(":");
        for(int j = 0; j < 4; j++){
            start = end+1;
            end = componant[i].find_first_of(":", start);
        }
        const char *text = componant[i].substr(end+1, componant[i].size()).c_str();
        sscanf(text, format, &value, &type);
        if(type == 'H'){
            send_back << angular_frequency*value;
            string send = send_back.str();
            componant_rectangular.push_back(send);
        } 
        if(type == 'C'){
            send_back << 1/(angular_frequency*value);
            string send = send_back.str();
            componant_rectangular.push_back(send);
        } 
        cout << componant_rectangular[i] << " ";
    }

    return 0;
}