#include<bits/stdc++.h>
using namespace std;
void showq(deque < pair<int,int> > q){
while(!q.empty()){
    pair< int, int >p=q.front();
    cout<<"("<<p.first<<" "<<p.second<<")";
    q.pop_front();
}
}
int main(){
deque < pair <int,int> > q;
int t;
cout<<"enter total number:";
cin>>t;
while(t--){
    int n1,n2;
    cin>>n1>>n2;
    q.push_back(make_pair(n1,n2));
}
showq(q);
cout<<endl;
q.pop_front();
//pair<int,int>p=q.front();
//q.push_front(p);
showq(q);
return 0;
}
