//virtual base class:
#include<iostream>
using namespace std;
class student{
 protected:
     int roll;
 public:
    void getr(int a){
     roll=a;
    }
    void putr(){
     cout<<"roll number is:"<<roll;
    }
};
class test:virtual public student{
 protected:
     float sub1,sub2;
 public:
    void getm(float x,float y){
     sub1=x;
     sub2=y;
    }
    void putm(){
     cout<<"marks obtained:"<<sub1<<" "<<sub2<<endl;
    }
};
class sport:virtual public student{
 protected:
     float score;
 public:
    void gets(float x){
     score=x;
    }
    void puts(){
     cout<<"score secured in sports:"<<score<<endl;
    }
};
class result:public test,public sport{
  public:
    display(){
      putr();
      putm();
      puts();
      cout<<"total is:"<<sub1+sub2+score<<endl;
    }

} ;
int main(){
  result s1;
  s1.getr(22);
  s1.gets(33);
  s1.getm(22,55);
  s1.display();
return 0;
}
