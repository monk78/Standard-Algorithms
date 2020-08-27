#include<iostream>
using namespace std;
template<typename T>
T sortt(T a[],int n){
for(int i=0;i<n-1;i++){
    for(int j=n-1;i<j;j--){

        if(a[j]<a[j-1]){

            T temp=a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
        }
    }

}
}
int main(){
            int arr[5]={2,5,1,0,9};
            sortt<int>(arr,5);
            for(int i=0;i<5;i++)
                    cout<<arr[i];
            cout<<endl;
            float farr[5]={4.9,4.2,5.1,6.3,1.5};
            sortt<float>(farr,5);
             for(int i=0;i<5;i++)
                    cout<<farr[i]<<" ";


    return 0;
}
