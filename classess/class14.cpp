#include<iostream>
using namespace std;
template<class T1,class T2>
class Test{
 T1 a;
 T2 b;
 public:
     Test(T1 x,T2 y){
       a=x,b=y;
     }
     void show(){
       cout<<a<<" "<<b<<endl;
     }
};
int main(){
Test<int,float>t1(23.5,34.6);
Test<char,string>t2('g',"hello");
t1.show();
t2.show();
return 0;
}
