#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int,int>ipair;
int main(){
    //set<>
    int n,a,b,c,ans=0;
    cout<<"enter number of triangle:";
    cin>>n;
       set < pair < ipair,int > > s;
    for(int i=0;i<n;i++){
            cout<<"enter "<<i+1<<"sides:";
        cin>>a>>b>>c;
        int arr[3]={a,b,c};
        sort(arr,arr+3);
        s.insert({{arr[0],arr[1]},arr[2]});
    cout<<endl;
    }
    cout<<"total unique element is:"<<s.size();
    return 0;
}
