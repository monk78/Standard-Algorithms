//multiple inheritance:
#include<iostream>
using namespace std;
class M{
 public:
     void display(void){
      cout<<"class M"<<endl;
     }
};
class N{
 public:
     void display(){
      cout<<"class N"<<endl;
     }
};
class P:public M,public N{
 public:
     void display(){
        cout<<"class P"<<endl;
     }
};
int main(){
  P p1;
  p1.display();
  p1.M::display();
  p1.N::display();
  return 0;
}
