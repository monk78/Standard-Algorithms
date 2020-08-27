#include<iostream>
using namespace std;
void print(int m,int n){
    if(m==0||n==0)
        return;
    cout<<m<<n<<endl;
    print(m-1,n);
    print(m,n-1);
}
int main(){
 int m,n;
 cin>>m>>n;
 print(m,n);
return 0;
}
