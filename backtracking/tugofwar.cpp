#include<bits/stdc++.h>
using namespace std;
void Towutil(int *arr,int n,bool *curr_elem,int selected,bool *sol,int *min_diff,int sum,int curr_sum,int curr_pos){
 if(curr_pos==n)
        return;
 //checking number left should not be less than required number to form the solution:
 if(((n/2)-selected)>(n-curr_pos))
        return;
 selected++;
 curr_sum=curr_sum+arr[curr_pos];
 curr_elem[curr_pos]=true;
 if(selected==n/2){

    if(abs(sum/2-curr_sum)<*min_diff)
    {
       *min_diff=abs(sum/2-curr_sum);
       for(int i=0;i<n;i++){
        sol[i]=curr_elem[i];
       }

    }
 }
    else{
        Towutil(arr,n,curr_elem,selected,sol,min_diff,sum,curr_sum,curr_pos+1);
    }
    curr_elem[curr_pos]=false;
 }
void tugOfWar(int arr[],int n){
  bool *curr_elem = new bool[n];
  bool *sol=new bool[n];
  int min_diff=INT_MAX;
  int sum=0;
  for(int i=0;i<n;i++){
     sum+=arr[i];
     curr_elem[i]=sol[i]=false;
  }
 //finding solution using recursive solution:
  Towutil(arr,n,curr_elem,0,sol,&min_diff,sum,0,0);
  //printing solution:
  cout<<"first subset:-"<<endl;
  for(int i=0;i<n;i++){
    if(sol[i]==true)
            cout<<arr[i]<<" ";
  }
  cout<<endl<<"second subset:-"<<endl;
  for(int i=0;i<n;i++){
    if(sol[i]==false)
            cout<<arr[i]<<" ";

  }
  cout<<endl;
}
int main(){
    int n;
    cout<<"enter total elements:";
    cin>>n;
    int arr[n]={0};
    cout<<"enter arrays:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int s=sizeof(arr)/sizeof(arr[0]);
    tugOfWar(arr,s);

return 0;
}
