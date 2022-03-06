#include<iostream>
//#include<sham.h>
using namespace std;
class Student_info{
	      public:
		      int roll_no;
			  char name[10];
			   void Input_Student_info(){
				        cout<<endl<<"\t Enter a Roll mo :- ";
						cin>>roll_no;
						cout<<endl<<"\t Enter Name      :- ";
						cin>>name;
			   }
};
class Internal_Marks:public virtual Student_info{
	      public:
		      int im1,im2,im3;
			  void Input_Internal_Marks(){
				       cout<<endl<<"\t Enter 3 sub marks of internal :- ";
					   cin>>im1>>im2>>im3;
			  }
};
class External_Marks:virtual public Student_info{
	      public:
		      int em1,em2,em3;
			  void Input_External_Marks(){
				       cout<<endl<<"\t Enter 3 sub External_Marks :- ";
					   cin>>em1>>em2>>em3;
			  }
};
class Result:public Internal_Marks,public External_Marks{
	      public:
		      int total;
			  float per;

			  void Display(){
				       cout<<endl<<"\t ROLL NO :- "<<roll_no;
					   cout<<endl<<"\t NAME    :- "<<name;
					   cout<<endl<<endl<<"\t External_Marks :- ";
					   cout<<im1<<" "<<im2<<" "<<im3;
					   cout<<endl<<endl<<"\t External_Marks :- ";
					   cout<<em1<<" "<<em2<<" "<<em3;
					   total=im1+im2+im3+em1+em2+em3;
					   per=(float)total/3;
					   cout<<endl<<"\t TOTAL      :- "<<total;
					   cout<<endl<<"\t PERSENTAGE :- "<<per;
			  }
};
int main(){
//	      pass_word();
	      Result x;
		  x.Input_Student_info();
		  x.Input_Internal_Marks();
		  x.Input_External_Marks();
		  x.Display();
		cin.get();
		return(0);
}
