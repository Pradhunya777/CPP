#include<iostream>
using namespace std;
class student{
public :
    string name;
    int age;
    string gender;

    void printInfo(){
        cout<<"Name = ";
        cout<<name<<endl;
        cout<<"Age = ";
        cout<<age<<endl;
        cout<<"Gender = ";
        cout<<gender<<endl;
    }
};
int main(){
    student arr[3];
    cout<<"Enter Student Information ...\n";
    for(int i=0;i<3;i++){
        cout<<"Name =";
        cin>>arr[i].name;
        cout<<"Age =";
        cin>>arr[i].age;
        cout<<"Gender =";
        cin>>arr[i].gender;
    }
    cout<<"Student Information is as below...\n";
    for(int i=0;i<3;i++){
        arr[i].printInfo();
    }
    return 0;
}
