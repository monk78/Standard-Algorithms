#include<iostream>
using namespace std;
int size=3;
template<class T>
//const int size=3;
class vect{
 T *v;
 public:
     vect(){
      v=new T[size];
      for(int i=0;i<size;i++)
            v[i]=0;
     }
     vect(T *a){
        for(int i=0;i<size;i++)
                v[i]=a[i];
     }
     T operator*(vect &y){
       T sum=0;
       for(int i=0;i<size;i++){
        sum+=this->v[i]*y.v[i];
       }
       return sum;
     }
    void display(){
      for(int i=0;i<size;i++)
            cout<<v[i]<<" ";
    }
};
int main(){
 int x[3]={1,2,3};
 int y[3]={4,5,6};
 vect<int>v1;
 vect<int>v2;
 v1=x;
 v2=y;
v1.display();
cout<<endl;
v2.display();
cout<<endl;
cout<<v1*v2<<endl;
return 0;
}
