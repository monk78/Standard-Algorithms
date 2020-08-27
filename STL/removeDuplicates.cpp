#include<bits/stdc++.h>
#define ll long long
using namespace std;
void rem(vector<ll>v){
  set<ll>::iterator it;
  vector<ll>res;
  set<ll>s;
  for(ll i=0;i<v.size();i++){
    s.insert(v[i]);
  }
  for(it=s.begin();it!=s.end();it++){
    cout<<*it<<" ";
  }
  cout<<endl;
}
int main(){
  ll n,num;
  cin>>n;
  vector<ll>vec,res;
  for(ll i=0;i<n;i++){
    cin>>num;
    vec.push_back(num);
  }
  rem(vec);
  return 0;
}



