//multilevel inheritance:
#include<iostream>
using namespace std;
class student{
 protected:
     int roll;
 public:
    void getn(int);
    void putn();
};
void student::getn(int n){
    roll=n;
}
void student::putn(){
 cout<<"roll number is:"<<roll<<endl;
}
class test:public student{
 protected:
     float sub1,sub2;
 public:
    void getm(float f1,float f2){
            sub1=f1;
            sub2=f2;
    }
    void putm(){
      cout<<sub1<<" "<<sub2<<endl;
    }
};
class result:public test{
 float total;
 public:
     void display(void){
       total=sub1+sub2;
       putn();
       putm();
       cout<<"total is:"<<
     }
} ;
int main(){
 result s1;
 s1.getn(22);
 s1.getm(75.0,33);
 s1.display();
 return 0;
}
