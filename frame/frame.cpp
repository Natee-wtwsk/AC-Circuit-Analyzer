void drawing(string **canvas, vector<componant_struct> &componants, int high, int wide){
    int count = 1;  

    for(int i = 0;i < (wide*2)+6;i++){
        cout << "=*";
    } cout << endl;  

    for(int i = 0; i < high; i++){
        cout<<"|   ";
        for(int j = 0; j < wide; j++){          
            if(canvas[i][j] == "") cout << setw(4) << count;
            else cout << setw(4) << canvas[i][j];
            count++;
        }
        cout << "      |\n\n";
    }

    for(int i = 0;i < (wide*2)+6;i++){
        cout << "=*";
    } cout << endl<<endl;
}