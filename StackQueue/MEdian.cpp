
#include<bits/stdc++.h>
using namespace std;
int median(int a[],int b[],int mid,int n)
{
int count=0,num=0;
while(a[mid-1]!=b[mid-1]&&count<100000)
{
num=a[mid];
a[mid]=b[mid];
b[mid]=num;

sort(a,a+n);
sort(b,b+n);
count++;
}
if(count)
    return count;
else
    return -1;
}
int main()
{

int t,n;
cin>>t;

while(t--)
{
cin>>n;
int a[n]={0};
int b[n]={0};
for(int i=0;i<n;i++)
{
cin>>a[i];

}

for(int i=0;i<n;i++)
{
cin>>b[i];

}

//int temp[n]={0};
int mid=(n/2);
int value=median(a, b, mid,n);
cout<<value<<endl;
}

}

