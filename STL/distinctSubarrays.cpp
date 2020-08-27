#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,num,i;
    cin>>n;
    ll arr[n];
    set<ll>s;
    for(i=0;i<n;i++){
        cin>>arr[i];
        s.insert(arr[i]);
    }
     ll nn=s.size();
     ll ans[100000]={0};
     for (int startPoint = 0; startPoint <n ; startPoint++) {
            //group sizes
            for (int grps = startPoint; grps <=n ; grps++) {

                set<ll>temp;
                for (int j = startPoint ; j < grps ; j++){
                    //cout<<arr[j]<<" ";
                    temp.insert(arr[j]);
                }
                ans[temp.size()]++;
                //cout<<"\n";
            }

     }
     i=1;
   while(ans[i]!=0){
            cout<<ans[i]<<endl;
            i++;
     }
    return 0;
}
