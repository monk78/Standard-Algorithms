//overloading function in template:
#include<iostream>
using namespace std;
template<class T>
void display(T x){
  cout<<"overload Template function display 1"<<x<<endl;
}
template<class T,class T1>
void display(T x,T1 y){
  cout<<"overload template display 2"<<x<<" "<<y<<endl;
}
void display(int x){
 cout<<"explicit function:"<<endl;
}
int main(){
 display(100);
 display(12.34);
 display(100,12.34);
 display('C');
return 0;
}
