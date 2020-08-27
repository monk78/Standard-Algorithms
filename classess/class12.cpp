//constructoR
#include<iostream>
using namespace std;
class alpha{
 int x;
 public:
     alpha(int i){
       x=i;
       cout<<"alpha initialised:";
     }
     void show_a(){
       cout<<x<<endl;
     }
};
class beta{
    int y;
    public:
   beta(int j){
      y=j;
      cout<<"beta initialised:"<<endl;
   }
   void show_b(){
    cout<<y<<endl;
   }
};
class gamma:public beta,public alpha{
  int m,n;
  public:
      gamma(int a,int b,int c,int d):alpha(a),beta(b){
        m=c;
        n=d;
        cout<<"gamma initilaised:"<<endl;
      }
      void show_g(){
        cout<<m<<" "<<n<<endl;
      }
};

int main(){
    gamma g1(4,6,7,8);
    g1.show_a();
    g1.show_b();
    g1.show_g();
return 0;
}
