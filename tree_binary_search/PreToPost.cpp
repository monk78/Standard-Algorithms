#include<bits/stdc++.h>
using namespace std;
void postO(int pre[],int n,int *preindex,int mn,int mx)
{
  if((*preindex)==n)return;
  if(pre[*preindex]< mn || pre[*preindex]>mx)return;
    int value=pre[(*preindex)++];
    postO(pre,n,preindex,mn,value);
    postO(pre,n,preindex,value,mx);
    cout<<value<<" ";
}
//Sorted Array to PreOrder
void PreO(int arr[],int index,int n){
  if((index)>n)return;
  int mid=index+(n-index)/2;
 cout<<arr[mid]<<" ";
  PreO(arr,index,mid-1);

  PreO(arr,mid+1,n);

}

int main()
{
    int test,n;
    cin>>test;
    while(test--)
        {
        cin>>n;
        int pre[n];
        for(int i=0;i<n;i++) cin>>pre[i];
        int preindex=0;
        int mn=INT_MIN,mx=INT_MAX;
        postO(pre,n,&preindex,mn,mx);
        cout<<endl;
    }
return 0;
}
