#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    cout<<"all permutation of this are:";
    do{
        for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
        cout<<endl;
    }while(next_permutation(arr,arr+n));

}

