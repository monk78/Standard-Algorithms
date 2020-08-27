 #include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int si,int ei){
 int mid=(si+ei)/2;
 int size=ei-si+1;
 int *out=new int[size];
 int i=si,k=0,j=mid+1;
 while(i<=mid && j<=ei){
    if(arr[i]<arr[j]){
       out[k]=arr[i];
       i++,k++;
    }
    else{
        out[k]=arr[j];
        k++;
        j++;
    }
 }
 while(i<=mid){
    out[k++]=arr[i++];
 }
 while(j<=ei){
    out[k++]=arr[j++];
 }
 int m=0;
 for(int i=si;i<=ei;i++){
    arr[i]=out[m];
    m++;
 }
}
void merge_sort(int arr[],int si,int ei){
 if(si>=ei)
    return;
 int mid=(si+ei)/2;
 merge_sort(arr,si+1,mid);
 merge_sort(arr,mid+1,ei);
 merge(arr,si,ei);
}
int main(){
  int n;
  cout<<"enter total numbers:";
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)cin>>arr[i];
  merge_sort(arr,0,n);
  for(int i=0;i<n;i++)cout<<arr[i]<<" ";
  return 0;
}
