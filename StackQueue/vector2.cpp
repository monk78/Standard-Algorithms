#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll test,n,num;
    cin>>test;
    while(test--){
        cin>>n;
    int v1[n],v2[n];
        vector<int>v3(n);
        for(ll i=0;i<n;i++){
            cin>>v1[i];
        }
        for(ll i=0;i<n;i++){
                cin>>v2[i];
        }
        sort(v1,v1+n);
        sort(v2,v2+n);
        ll pos1=n;
        ll pos2=n;

        vector < int >::iterator it,ls;
         ls = set_intersection(v1, v1 + n, v2, v2 + n, v3.begin());
      for(it=v3.begin();it!=ls;it++){
            int num=(*it);
        for(ll j=0;j<n;j++){
             if(v1[j]==num){
                 if(pos1>abs(j-n/2))
                    pos1=abs(j-(n/2));
             }
             if(v2[j]==num){
                 if(pos2>abs(j-n/2))
                    pos2=abs(j-(n/2));
             }

            }

      }
      cout<<min(pos1,pos2);
    }
    return 0;
}
