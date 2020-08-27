/**                    Author:Monk_
 *                     Topic:                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

ll gmin=INT_MAX;

//ll dpTable[gmin];
/* class BSTree{
public:
    int sum,dgsum;
    BSTree *left,*right;
    BSTree(int sum){
        dgsum=dgtSum(sum);
        left=NULL;
        right=NULL;
    }
};*/
void fast(){
 std::ios_base::sync_with_stdio(false);
 cout.tie(NULL);
}
ll dgtRoot(ll n){
  if(n==0)return 0;
     return (n%10)+dgtRoot(n/10);
}
ll dgtSum(ll n){
    if (n == 0)
        return 0;
    return (n % 9 == 0) ? 9 : (n % 9);
}
ll stepC(ll n, ll b, ll d, ll dep)
{
	if(dep>15) return gmin;
	if(n==b) return 0;
	return(1+min(stepC(dgtRoot(n),b,d,dep+1),stepC(n+d,b,d,dep+1)));
}
int main(){
    fast();
    //memset(dpTable,-1,sizeof(dpTable));
    ll test,n,d,i;
    cin>>test;
    while(test--){
        cin>>n>>d;
        ll b=dgtSum(n);
        _for(i,1,11){
            if(dgtSum(n+i*d)<b)
                    b=dgtSum(n+i*d);
        }
        ll step=stepC(n,b,d,0);
        cout<<b<<" "<<step<<endl;
  }
    return 0;
}
