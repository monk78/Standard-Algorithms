#include<iostream>
using namespace std;
class time{
  int hrs;
  int m;
 public:
   operator=(int t){
     hrs=t/60;
     m=t%60;
   }
   display(){
    cout<<hrs<<" "<<m<<endl;
   }
   operator int(){
      return hrs;
      return hrs;
   }
} ;
int main(){
 time t;
 t=230;
 t.display();
 int p=t;
 cout<<p<<endl;
return 0;
}
