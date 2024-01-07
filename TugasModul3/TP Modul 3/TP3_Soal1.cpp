#include <iostream> 

using namespace std;
 
class LinearLine 
{ 
private:
    float x1, y1, x2, y2;
 
public: 
    LinearLine (float x1, float y1, float x2, float y2) { 
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    } 
    float gradient() { 
        return (y2-y1)/(x2-x1);
    } 
    float y_intercept() { 
        return y1-(gradient())*(x1);
    } 
    void operator+(float a) { 
        x1+=a;
        x2+=a;
    } 
    void printEquation() {  
        cout<<"y = "<<gradient()<<" x + "<<y_intercept()<<endl;
    }
     void printPoints() { 
        cout<<"(x1, y1) = ("<<x1<<", "<<y1<<")"<<endl; 
        cout<<"(x2, y2) = ("<<x2<<", "<<y2<<")"<<endl; 
    }  
}; 
 
int main() 
{ 
    LinearLine line(1.0f, 8.0f, 2.0f, 3.0f); 
    int a = 3; 
/* 
lengkapilah fungsi main sehingga output program seperti pada contoh di bawah 
 
(x1, y1) = (1, 8) 
(x2, y2) = (2, 3) 
Sehingga didapatkan 
gradient = -5 
y_intercept = 13 
y = -5 x + 13 
 
Setelah digeser sejauh a, didapatkan persamaan baru: 
y = -5 x + 28 
*/ 
    line.printPoints();
    cout<<"Sehingga didapatkan"<<endl;
    cout<<"gradient = "<<line.gradient()<<endl;
    cout<<"y_intercept = "<<line.y_intercept()<<endl;
    line.printEquation();
    cout<<"\nSetelah digeser sejauh "<<a<<", didapatkan persamaan baru:"<<endl;
    line+a;
    line.printEquation();

    return 0;
}