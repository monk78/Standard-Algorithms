#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    ll sum,open,close;
};
node tree[4000005];
string str;
node mergee(node t1,node t2){
    node t;
    ll temp=min(t1.open,t2.close);
    t.sum=t1.sum+t2.sum+2*temp;
    t.open=t1.open+t2.open-temp;
    t.close=t1.close+t2.close-temp;
    return t;
}
void build(ll id,ll l,ll r){
    if(l==r){
        tree[id].sum=0;
        if(str[l-1]=='('){
            tree[id].open=1;
            tree[id].close=0;
           }
           else{
            tree[id].close=1;
            tree[id].open=0;
           }
           return;
    }
    ll m=(l+r)/2;
    build(2*id,l,m);
    build(2*id+1,m+1,r);
    tree[id]=mergee(tree[2*id],tree[2*id+1]);
}
node query(ll id,ll l,ll r,ll L,ll R){
    if(L<=l && R>=r)return tree[id];
    if(R<l || L>r){
        node temp;
        temp.sum=0;
        temp.open=0;
        temp.close=0;
        return temp;
    }
    ll m=(l+r)/2;
    node t1=query(2*id,l,m,L,R);
    node t2=query(2*id+1,m+1,r,L,R);
    return mergee(t1,t2);
}
int main(){
    cin>>str;
    ll n=str.size();
    build(1,1,n);
    ll q;
    cin>>q;
    while(q--){
        ll L,R;
        cin>>L>>R;
        node ans=query(1,1,n,L,R);
        cout<<ans.sum<<endl;
    }

return 0;
}
