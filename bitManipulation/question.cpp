#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
 ll t,n,s,e;
 cin>>t;
 while(t--){
        ll value=0;
     multimap<int,int>mp;
     multimap<int,int>::iterator it1;
     multimap<int,int>::iterator it2;
     cin>>n;
     for(ll i=0;i<n;i++)
        {
            cin>>s>>e;
            mp.insert(pair<int,int>(s,e));
        }
        ll count=0;
     //ll value=0,max=0,index=0;
ll max=0,index=0;
     for(it1=mp.begin();it1!=mp.end();it1++){
         count=1;
         value=0;
            for(it2=it1;it2!=mp.end();it2++){
                            if((it1->second < it2->first)&&(it2->second < it1->first)&&(it1!=it2)){
                                    value=(it1->first)+(it2->first);
                                    count=count+1;
                            }
            }

      if(max<value)
         {
          max=value;
          index=count;

          }
     }



        cout<<index<<endl<<max;
 }

    return 0;
}
