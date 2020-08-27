#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{

  ll i,j,l,value3,value1,value2,n,t,x,y;

   cin>>t;
   for(i=0;i<t;i++)
   {
    value1=0,value2=0,value3=0;
     cin>>n;
     for(j=0;j<=n;j++)
     {

     if(pow(2,j)>n)
     {
	 x=j-1;
	 break;
     }}
     if(pow(2,x)==n)
     x=x-1;
     l=n-pow(2,x);
     for(j=0;j<=l;j++)
     {
	 if(pow(2,j)>l)
	 {
	     y=j-1;
	     break;

	 }
     }

     value1=n-pow(2,x)-pow(2,y);
     value2=pow(2,x+1)+1-n;
     value3=pow(2,x)+pow(2,y+1)-n;

     if(n==1)
     {
         cout<<"2";
     continue;
     }
     if(x==y)
     cout<<"1";
     else
     {
       if(value1<=value2&&value1<=value3)
        {
        cout<<value1<<endl;
        continue;        //continue;
        }
    if(value2<=value1&&value2<=value1)
    {
    cout<<value2<<endl ;
    continue;
     }
     if(value3<=value2&&value3<=value1)
     {
      if(x==y+1)
     {
      cout<<value2<<endl ;
      continue;

     }
      else
     {
	cout<<value3<<endl;
	continue;
	}}
     }
}

   return 0;
}
