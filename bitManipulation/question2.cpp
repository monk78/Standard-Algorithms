#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test,D,A,M,B,X;
    cin>>test;
    while(test--){
        ll step=0;
        cin>>D>>A>>M>>B>>X;
        X=X-D;
        ll fer=X/(A*M+B);
        X=X-(A*M+B)*fer;
        step=step+(M+1)*fer;
        fer=X/(A*M);
        X=X-(A*M*fer);
        step=step+(M)*fer;
        ll k1=X/A;
        step=step+k1;
        if(X%A!=0)
            step=step+1;
        cout<<step<<endl;
    }
    return 0;
}
