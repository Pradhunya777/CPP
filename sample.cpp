#include <iostream>
using namespace std;

class Student{
    private:
        int roll, marks[5], total = 0;
        char name[10], collage[10], course[10];
    public:
        void getStudent(){
            cout<<"Enter Roll No :\t";
            cin>>roll;
            cout<<endl<<"Enter Name :\t";
            cin>>name;
            cout<<endl<<"Enter Collage :\t";
            cin>>collage;
            cout<<endl<<"Enter Course :\t";
            cin>>course;
            cout<<endl<<"Enter Marks of 5 subject \n";
            for(int i = 0; i < 5; i++)
                cin>>marks[i];


        }
        void displayStudent(){
            cout<<endl<<"Roll No : "<<roll;
            cout<<endl<<"Name : "<<name;
            cout<<endl<<"Collage : "<<collage;
            cout<<endl<<"Course : "<<course;
            cout<<endl<<"Marks : ";
            for(int i = 0; i < 5; i++)
                cout<<marks[i]<<" ";

        }

        void calculateAvarage(){
            for(int i = 0; i < 5; i++)
                total += marks[i];
        }

        void displayAvarage(){
            cout<<endl<<"Avarage : "<<(total/5);
            cout<<endl<<"------------------------";
        }
};
int main() {
    Student obj[5];
    for(int i = 0; i < 2; i++){
        obj[i].getStudent();
        obj[i].calculateAvarage();
    }
    //display info
    cout<<endl<<"~~~ Students Info ~~~";
    for(int i = 0; i < 2; i++){
        obj[i].displayStudent();
        obj[i].displayAvarage();
    }

  return 0;

}

