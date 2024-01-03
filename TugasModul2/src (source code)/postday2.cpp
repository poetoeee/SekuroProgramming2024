#include <iostream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

void lokasi(float x, float y){
    cout<<fixed<<setprecision(2)<<"("<<x<<", "<<y<<")"<<endl;
}

void gerak(float &x, float &y, float a, float b, vector<pair<float, float>> &simpan){
    simpan.push_back(make_pair(x, y));
    x+=a;
    y+=b;
}

void gerak_2(float &x, float &y, float v,float t, float theta, vector<pair<float, float>> &simpan){
    simpan.push_back(make_pair(x, y));
    x+=(cos(theta*M_PI/180)*v*t);
    y+=(sin(theta*M_PI/180)*v*t);
}

void undo(float &x, float &y, vector<pair<float, float>>&simpan, vector<pair<float, float>> &simpan2){
    if (simpan.empty()){cout<<"Tidak dapat undo!"<<endl;}
    else {
        simpan2.push_back(make_pair(x, y));
        pair<float, float> sebelum=simpan.back();
        x=sebelum.first;
        y=sebelum.second;
        simpan.pop_back();
        cout<<"Undo berhasil"<<endl;
    }
}

void redo(float &x, float &y, vector<pair<float, float>>&simpan, vector<pair<float, float>> &simpan2){
    if (simpan2.empty()){cout<<"Tidak dapat redo!"<<endl;}
    else {
        simpan.push_back(make_pair(x, y));
        pair<float, float> setelah=simpan2.back();
        x=setelah.first;
        y=setelah.second;
        simpan2.pop_back();
        cout<<"Redo berhasil"<<endl;
    }
}

int main(){
    float x=0.00, y=0.00;
    char pilih;
    vector<pair<float, float>> simpan;
    vector<pair<float, float>> simpan2;

    cout<<"Lokasi Drone Awal => (0, 0)"<<endl;
    while (pilih!='5'){
        cout<<"==========================================================="<<endl;
        cout<<"                     PROGRAM SIMULASI                     "<<endl;
        cout<<"==========================================================="<<endl;
        cout<<"  1. Menggerakkan Drone dengan Koordinat (x, y)"<<endl;
        cout<<"  2. Menggerakkan Drone dengan Kecepatan, Arah, dan Waktu"<<endl;
        cout<<"  3. Undo"<<endl;
        cout<<"  4. Redo"<<endl;
        cout<<"  5. Exit"<<endl<<endl;
        cout<<"Pilih: ";
        cin>>pilih;

        switch (pilih){
            case '1':
                float a, b;
                cout<<"Masukkan pergerakan drone (x, y)"<<endl;
                cout<<"Masukkan x: ";
                cin>>a;
                cout<<"Masukkan y: ";
                cin>>b;
                gerak(x, y, a, b,  simpan);
                cout<<"Lokasi Drone => ";
                lokasi(x, y);
                cout<<endl;
                break;
            case '2':
                float v, t, theta;
                cout<<"Masukkan kecepatan (v): ";
                cin>>v;
                cout<<"Masukkan waktu (t): ";
                cin>>t;
                cout<<"Masukkan sudut theta: ";
                cin>>theta;
                gerak_2(x, y, v, t, theta, simpan);
                cout<<"Lokasi Drone => ";
                lokasi(x, y);
                cout<<endl;
                break;
            case '3':
                undo(x, y, simpan, simpan2);
                cout<<"Lokasi Drone => ";
                lokasi(x, y);
                cout<<endl;
                break;
            case '4':
                redo(x, y, simpan, simpan2);
                cout<<"Lokasi Drone => ";
                lokasi(x, y);
                cout<<endl;
                break;
            case '5':
                cout<<"Keluar program, Terima kasih.";
                break;
            default:
                cout<<"Input tidak valid. Input ulang!"<<endl;
        }
    }return 0;
}