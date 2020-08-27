#include<bits/stdc++.h>
using namespace std;
void printresult(vector<string>res){
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    cout<<endl;
}
int main(){
    string num;
    int target;
    cout<<"enter number:";
    cin>>num;
    cout<<"enter target:";
    cin>>target;
    vector<string>res=getexpr(input,target);
    printresult(res);
    return 0;
}
