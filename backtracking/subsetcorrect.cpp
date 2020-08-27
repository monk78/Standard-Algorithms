#include<bits/stdc++.h>
using namespace std;
void subsetutil(vector<int>&ar,vector< vector<int> >&res,vector<int>&subset,int index){

//base-case:-
    if(index==ar.size())
            return;
//recursive-case:-
    for(int i=index;i<ar.size();i++){
        subset.push_back(ar[i]);
        res.push_back(subset);
        subsetutil(ar,res,subset,i+1);
        subset.pop_back();
    }
}
vector< vector <int> >subsets(vector<int>&ar){
   vector<int>subset;
   vector< vector <int> > res;
   res.push_back(subset);
   int index=0;
   subsetutil(ar,res,subset,index);
   return res;
}
int main(){
    int n,num;
    cout<<"enter total numbers:";
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>num;
        v.push_back(num);
    }
    vector< vector <int> >res=subsets(v);
    //printing all subsets:
    cout<<"printing all subsets:-"<<endl;
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
