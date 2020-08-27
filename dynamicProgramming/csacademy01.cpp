/**

        Author:Monk_
                                           **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define floop(i,a,b) for(i=a;i<b;i++)

#define rfloop(i,a,b) for(i=a;i>=b;i--)

void fast(){
 std::ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
}
int main(){
    fast();
    ll n,x,i,ai,bi,sum=0;
    vector< pair <ll,ll> >v;
    cin>>n>>x;
    floop(i,0,n){
     cin>>ai>>bi;
     v.push_back(make_pair(ai,bi));
    }
    sort(v.begin(),v.end());
    ll sum2=0;
    floop(i,0,n){
    sum=sum+v[i].second;
    if(v[i].first>x){
        cout<<min(v[i].first-sum,x-sum2)<<endl;
        return 0;
    }
    sum2=sum2+v[i].second;
    }
    cout<<x-bi<<endl;
    return 0;
}
