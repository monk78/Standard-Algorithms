//dsu
#include<bits/stdc++.h>
using namespace std;
#define ll int
int Arr[1000];
int sze[1000];
void intlz(int N){
 for(int i=0;i<N;i++){
    Arr[i]=i;
    sze[i]=1;
 }
}
int root(int Arr[],int i){
    while(Arr[i]!=i){
        Arr[i]=Arr[Arr[i]];
        i=Arr[i];
    }
    return i;
}
void wunion(int A,int B){
    int root_A=root(Arr,A);
    int root_B=root(Arr,B);
    if(root_A==root_B)return;
    if(sze[root_A]<sze[root_B]){
        Arr[root_A]=Arr[root_B];
        sze[root_B]+=sze[root_A];
    }
    else{
        Arr[root_B]=Arr[root_A];
        sze[root_A]+=sze[root_B];

    }

}
int main(){
  ll N,D;
  cin>>N>>D;
  memset(Arr,0,N+1);
  memset(sze,0,N+1);
  intlz(N);
  for(ll i=1;i<=D;i++){
    ll a,b;
    cin>>a>>b;
    wunion(a,b);
  }
  ll ans=INT_MAX;
  for(ll i=0;i<N;i++){
    ll root_Arr=root(Arr,Arr[i]);
    ll s=sze[root_Arr];
    if(ans>s)
        ans=s;
  }
  cout<<ans<<endl;
return 0;
}
