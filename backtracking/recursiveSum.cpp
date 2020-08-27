#include<bits/stdc++.h>
using namespace std;
void super(string p){
if(p.length()==1){
        cout<<p<<endl;
        return;
  }
    stringstream geek(p);

  int k=0;
  geek>>k;
  int total=0;
  while(k){
    total=total+(k%10);
    k=k/10;
   }
   p=to_string(total);
   super(p);
   return;
}
int main(){
    string n,p="";
    int k;
    cin>>n>>k;
    while(k--){
        p=p+n;
    }
        int l=p.length();
    int index=0,sum=0;
    super(p);
    return 0;
}
