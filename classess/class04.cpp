#include<bits/stdc++.h>
using namespace std;
class matrix{
 private:
    int **p;
    int d1,d2;
 public:
    matrix(int r,int c){
        d1=r;
        d2=c;
     p=new int*[d1];
     for(int i=0;i<d1;i++)
            p[i]=new int[d2];
    }
    void get(int i,int j,int value){
     p[i][j]=value;
    }
    void show(int i,int j){
      cout<<p[i][j]<<endl;
    }
};
int main(){
  cout<<"enter matrix:";
  int r=2,c=2;
  matrix m(r,c);
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        int value;
        cin>>value;
      m.get(i,j,value);
    }

  }
m.show(1,1);
return 0;
}
