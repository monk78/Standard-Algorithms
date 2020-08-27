#include<iostream>
using namespace std;
void test(int x){
   if(x==0)throw x;
   if(x==-1)throw 'x';
   if(x==1)throw 1.0;
}
int main(){
 //cout<<"testing generic catch";
 try{
 test(-1);
 test(0);
 test(1);
 }
 catch(...){
   cout<<"caught an exceptioon:"<<endl;
 }
 return 0;
}
