#include<iostream>
using namespace std;
class student{
public :
    string name;
    int rollno;
    int math;
    int phys;
    int chem;
    int eng;
    int marathi;
    int total;
    float avg;
    string course;
    string college;

    void printInfo(){
        cout<<"Name = ";
        cout<<name<<endl;
        cout<<"Rollno  = ";
        cout<<rollno<<endl;
        cout<<"math = ";
        cout<<math<<endl;
        cout<<"phys = ";
        cout<<phys<<endl;
        cout<<"chem  = ";
        cout<<chem<<endl;
        cout<<"eng = ";
        cout<<eng<<endl;
        cout<<"Marathi = ";
        cout<<marathi<<endl;
        cout<<"Course  = ";
        cout<<course<<endl;
        cout<<"College = ";
        cout<<college<<endl;
        total=math+phys+chem+eng+marathi;
        cout<<total<<endl;
        avg=total/5;
        cout<<avg<<endl;
    }
};
int main(){
    student arr[2];
    cout<<"Enter Student Information ...";
    for(int i=0;i<2;i++){
        cout<<"Name =";
        cin>>arr[i].name;
        cout<<"Rollno =";
        cin>>arr[i].rollno;
        cout<<"Math =";
        cin>>arr[i].math;
        cout<<"Phys =";
        cin>>arr[i].phys;
        cout<<"Chem =";
        cin>>arr[i].chem;
        cout<<"Eng =";
        cin>>arr[i].eng;
        cout<<"Mara =";
        cin>>arr[i].marathi;
        cout<<"Course =";
        cin>>arr[i].course;
        cout<<"College =";
        cin>>arr[i].college;

    }
    cout<<"Student Information is as below...\n";
    for(int i=0;i<2;i++){
        arr[i].printInfo();
    }
    return 0;
}
