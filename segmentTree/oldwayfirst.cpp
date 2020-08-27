#include<bits/stdc++.h>
using namespace std;
vector<int>s;
int arr[10000]= {0};
int lazy[10000]= {0};
int n;
void split(int x,int y,int id=1,int l=0,int r=n)
{
    if(x>=r or l>=y)return;
    if(x<=l && r<=y)
    {
        s.push_back(id);
        return;
    }
    int mid=(l+r)/2;
    split(x,y,id*2,l,mid);
    split(x,y,id*2+1,mid,r);
}
void build(int id=1,int l=0,int r=n)
{
    if((r-l)<2)
    {
        s[id]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid,r);

    s[id]=s[id*2]+s[id*2+1];
}
void modify(int p,int x,int id=1,int l=0,int r=n)
{
    //s[id]+=x-arr[p];
    if(r-l<2)
    {
        s[id]=x;
        arr[p]=x;
        return;
    }
    int mid=(l+r)/2;
    if(p<mid)modify(p,x,id*2,l,mid);
    else modify(p,x,id*2+1,mid,r);
}
int sum(int x,int y,int id=1,int l=0,int r=n)
{
    if(x>=r or l>=y)return 0;
    if(x<=l && r<=y)return s[id];
    int mid=(l+r)/2;
    return sum(x,y,id*2,l,mid)+sum(x,y,id*2+1,mid,r);
}


//###############################################################


// lazy propogations:


void upd(int id,int l,int r,int x)
{
    lazy[id]=lazy[id]+x;
    s[id]+=(r-l)*x;
}
void shift(int id,int l,int r)
{
    int mid=(l+r)/2;
    upd(id*2,l,mid,lazy[id]);
    upd(id*2 + 1,mid,r,lazy[id]);
}
void increase(int x,int y,int v,int id=1,int l=0,int r=n)
{
    if(x>=r or l>=y)return;
    if(x<=l && r<=y)
    {
        upd(id,l,r,v);
        return;
    }
    shift(id,l,r);
    int mid=(l+r)/2;
    increase(x,y,id*2,l,mid);
    increase(x,y,v,id*2 + 1,mid,r);
    s[id]=s[id*2]+s[id*2+1];
}


//#######################################################3333
int main()
{
    //arr[]={0,1,2,3,4,5,6,7,8,9};
    for(int i=0; i<10; i++)
    {
        cin>>arr[i];
    }
    n=10;
    split(1,4,1,0,n);
    build(1,0,n);
    cout<<"array:"<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    cout<<"sum is:"<<sum(1,4,1,0,n)<<endl;
    modify(3,12,1,0,n);
    cout<<"sum is:"<<sum(1,4,1,0,n)<<endl;
    cout<<"array:"<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
