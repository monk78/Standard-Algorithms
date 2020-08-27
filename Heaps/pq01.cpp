#include<bits/stdc++.h>
using namespace std;
#define ll int
int main(){
  priority_queue<int,vector<int>,greater<int>>pq;
  int a[6]={12,14,11,3,4,2};
  for(ll i=0;i<6;i++){
    pq.push(a[i]);
  }
  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }
return 0;
}
