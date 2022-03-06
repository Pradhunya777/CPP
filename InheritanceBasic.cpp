#include<iostream>
using namespace std;

class base{
public:
    int x,y;
    void display(){
        x=9;
        y=6;
        cout<<x<<"  "<<y<<endl;
    }
};

class derived :public base{
public :
    int z;
    void display1(){
        z=10;
        cout<<x<<"  "<<y<<"  "<<z<<endl;
    }
};

int main(){
    derived d1;
  //  d1.display();
    d1.display1();
    return 0;
}
