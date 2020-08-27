#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	map<char,ll>::iterator it;
    ll test;
    cin>>test;
    while(test--){
        map<char,ll>mp;
        ll n,i=0;
        string str;
        cin>>n;
        cin>>str;
        while(str[i]!='\0'){
            mp[str[i]]++;
        }
        for(it=mp.begin();it!=mp.end();it++){
        	cout<<it->first<<" "<<it->second<<endl;
		}
    }
    return 0;
}
