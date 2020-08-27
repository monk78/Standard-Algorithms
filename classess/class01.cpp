#include<bits/stdc++.h>
using namespace std;
class B;
class A{
    int x;
   public:
    void setV(){
        cout<<"enter values:";
        cin>>x;
    }
    friend void sum(A,B);
};
class B{
 int y;
 public:
     void setV(){
      cout<<"enter values:";
      cin>>y;
     }
     friend void sum(A,B);
};
void sum(A a,B b){
 cout<<"ans is:"<<a.x+b.y<<endl;
}
int main(){
    A a;
    B b;
    a.setV();
    b.setV();
    sum(a,b);
return 0;
}
