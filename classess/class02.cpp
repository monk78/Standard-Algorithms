//dereferencing operators:
#include<bits/stdc++.h>
using namespace std;
class M{
  int x,y;
 public:
     void set_x(int a,int b){
      x=a;
      y=b;
     }
     friend int sum(M m);
};
int sum(M m){
  int M :: *px = &M::x;
  int M :: *py = &M::y;
  M *pm=&m;
  int s=(pm->*px)+(m.*py);
  return s;
 }
int main(){
  M m;
  m.set_x(3,4);
  cout<<sum(m)<<endl;
return 0;
}
