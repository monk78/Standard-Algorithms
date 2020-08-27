#include<bits/stdc++.h>
using namespace std;
class Complex{
 float x,y;
 public:
     Complex(){}
     Complex(float real,float imag){
       x=real;
       y=imag;
     }
    /* Complex operator +(Complex c){
          Complex temp;
          temp.x=x+c.x;
          temp.y=y+c.y;
          return temp;
     }*/
friend Complex operator +(Complex,Complex);
     void display(){
      cout<<x<<"  "<<y<<endl;
     }
};
  Complex operator +(Complex c1,Complex c2){
      //cout<<c2.x<<" "<<c2.y<<" }";
    Complex temp;
    temp.x=c1.x+c2.x;
    temp.y=c1.y+c2.y;
    return temp;
  }
int main(){
    Complex c1,c2,c3;
    c1=Complex(2.5,3.5);
    c2=Complex(1.6,4.9);
    c3=c2+c1;
    //cout<<c3.x;
    c3.display();
return 0;
}
