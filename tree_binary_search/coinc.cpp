#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,n;int countt=0,x;

    int a[200006]={0};

    cin>>n;
    int b[n+5];


    for(i=1;i<=n;i++)
    {
        cin>>x;
        a[x]=i;
    }

    for(i=1;i<=n;i++)
    cin>>b[i];

    for(i=1;i<=n;i++)
    {   if(a[b[i]]>countt)
        {
            cout<<a[b[i]]-countt<<" ";
            countt=a[b[i]];
        }
        else
        cout<<"0 ";
    }
}
