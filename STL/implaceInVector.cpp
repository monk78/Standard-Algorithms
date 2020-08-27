#include<bits/stdc++.h>
#include<vector>
#include<iterator>
using namespace std;
int main(){
    vector<int>vec;
    vector<int>::iterator it;
    int num;
    for(int i=0;i<6;i++)
    {
        cin>>num;
        vec.push_back(num);
    }
    it=vec.emplace(vec.begin(),15);
    for(it=vec.begin();it!=vec.end();++it){
        cout<<*it;
    }
    return 0;
}
