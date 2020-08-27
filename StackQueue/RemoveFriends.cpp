#include<bits/stdc++.h>
using namespace std;
#define ll long long
void show(stack<int>st){

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        stack<int>st1,st2;
        ll n,k,num;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>num;
            st1.push(num);
        }
        st2.push(st1.top());
        st1.pop();
        ll count=0;
        for(ll i=0;i<k;i++){
            bool check=true;
            while(check==true&&!st1.empty()){
            if(st2.top()>st1.top()){
                st1.pop();
                check=false;
            }
            else{

                st2.push(st1.top());
                st1.pop();
            }

        }


    }
    show(st2);
    }
    return 0;
}
