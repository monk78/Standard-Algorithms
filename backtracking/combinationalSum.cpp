//{by xx--combinational--sum}
#include<bits/stdc++.h>
using namespace std;
void findnumber(vector<int>&ar,int sum,vector<vector<int> >&res,vector<int>&r,int i){
 if(sum<0)
        return;
    if(sum==0){

        res.push_back(r);
        return;
    }
    while(i<ar.size()&&sum-ar[i]>=0){
        //add the element which can contribute to the list:-
        r.push_back(ar[i]);
        findnumber(ar,sum-ar[i],res,r,i);
        i++;
        //backtracking rermove number from list:
        r.pop_back();
    }
}
//return all combination that has given sum:
vector < vector < int > >combinationSum(vector < int >&ar,int sum){
//sort input array:
sort(ar.begin(),ar.end());
ar.erase(unique(ar.begin(),ar.end()),ar.end());
vector<int>r;
vector<vector< int> >res;
findnumber(ar,sum,res,r,0);
return res;
}
int main(){
vector<int>v;
int n,num,sum=0;
cout<<"total elements:";
cin>>n;
for(int i=0;i<n;i++){
    cin>>num;
    v.push_back(num);
}
cout<<"finding sum:";
cin>>sum;
//printing all combination stored in res
vector< vector < int > >res=combinationSum(v,sum);
for(int i=0;i<res.size();i++){
        if(res[i].size()>0){
            cout<<" ( ";
            for(int j=0;j<res[i].size();j++)
                cout<<res[i][j]<<" ";

            cout<<" ) ";
        }
}
return 0;
}

