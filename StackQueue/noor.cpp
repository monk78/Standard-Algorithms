#include<bits/stdc++.h>
#define ll long long

using namespace std;
struct pond{
    int szee;
    int eate;
};
bool compare(pond a, pond b)
{
    if (a.szee != b.szee )
        return a.szee < b.szee;
}
void sortt(pond a[], int n)
{
    sort(a, a+n, compare);
}
int main()
{
    ll test,sze,eat,n;
    cin>>test;
    while(test--){
            cin>>n;
    pond fish[n];
    for(int i=0;i<n;i++){
        cin>>sze>>eat;
        fish[i].szee=sze;
        fish[i].eate=eat;
    }
    cout<<endl;
    ll countt=0,index=0;
    sortt(fish,n);
    for(int i=0;i<n;i++){
            countt=1;
        for(int j=i;j<n;j++){
            if((fish[i].eate < fish[j].szee)&&(fish[j].eate < fish[i].szee)&&(i!=j))
                                    countt=countt+1;

        }
         if(countt>index)
         {
          index=countt;
          }

    }

    cout<<index<<endl;
    }
    return 0;
}

