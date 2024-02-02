#include <iostream>

using namespace std;

int main(){
    string pesawat;
    
    while (pesawat!="o"){
        cout<<"Masukkan jenis pesawat (a/b/o): ";
        cin>>pesawat;
        if (pesawat == "a"){
            for(int i=3; i>0; i--){cout<<i<<endl;}
            cout<<"PESAWAT A BERANGKAT"<<endl;
        }else if (pesawat == "b"){
            for(int i=5; i>0; i--){cout<<i<<endl;}
            cout<<"PESAWAT B BERANGKAT"<<endl;
        }else if (pesawat == "o"){
            cout<<"PENERBANGAN DITUTUP"<<endl;
            break;
        }else{cout<<"INPUT TIDAK VALID"<<endl;}
    }return 0;
}