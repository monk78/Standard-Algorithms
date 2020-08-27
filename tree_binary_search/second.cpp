/**                    Author:Monk_
 *                     Topic:                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

void fast(){
 std::ios_base::sync_with_stdio(false);
 cout.tie(NULL);
}
int main(){
    fast();
    deque <ll> st,op;
   ll n,i,num;
   cin>>n;
   _for(i,0,n){
    cin>>num;
    st.push_back(num);
   }
  _for(i,0,n){
    cin>>num;
    op.push_back(num);
  }
  while(!op.empty()){
    ll value=op.front();
    //cout<<"{"<<value<<"}";
    op.pop_front();
    ll pos=-1;
    _for(i,0,st.size()){
        if(st[i]==value)
                pos=i;
    }
   // cout<<"{"<<pos<<"}";
    ll count=0,j;
    if(pos==-1)count=0;
    else{
        count=pos+1;
    st.erase(st.begin(),st.begin()+pos+1);
   }
    //cout<<"{"<<st.size()<<"}";
   cout<<count<<" ";
  }
    return 0;
}
