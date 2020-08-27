#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr1={1,2,3,5};
    vector<int>arr2={4,7,6,9};
    sort(arr1.begin(),arr1.end());
      sort(arr2.begin(),arr2.end());
    vector<int>arr3(8);
    merge(arr1.begin(),arr1.end(),arr2.begin(),arr2.end(),arr3.begin());

    for(int i=0;i<8;i++){
        cout<<arr3[i]<<" ";
    }

return 0;
}
