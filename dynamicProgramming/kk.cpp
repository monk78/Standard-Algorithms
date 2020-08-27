//sushil code:
    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    int main()
    {
       ll i,max,j, n,temp,countt[100000],limit=0;
       cin>>n;
       ll md[n];
       for(i=0;i<n;i++)
       {
           cin>>md[i];
           countt[md[i]]=countt[md[i]]+1;
           if(limit<md[i])
                limit=md[i];
       }
       ll maxv=0,index=0;
       for(i=1;i<=limit;i++){
            if(maxv<countt[i]){
                maxv=countt[i];
                index=i;
            }
            else if(maxv==countt[i]&&i<index){
                index=i;
            }
       }
     cout<<index<<endl;
       return 0;
    }
