//upper bound and lower bound
#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={7,8,3,4,5};
    sort(arr,arr+5);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<lower_bound(arr,arr+5,7)-arr<<endl;
    cout<<lower_bound(arr,arr+5,6)-arr<<endl;
    cout<<upper_bound(arr,arr+5,7)-arr<<endl;
return 0;
}
