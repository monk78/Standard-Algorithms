#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int>st;
    int n,countt=0;
    string str;
    cout<<"enter string::";
    cin>>str;
    int l=str.length();
    for(int i=0;i<l;i++){
        if(str[i]=='('){
            ++countt;
            st.push(countt);
            cout<<countt<<" ";
           }
           else if(str[i]==')'){
                cout<<st.top()<<" ";
            st.pop();
           }
    }
    return 0;
}
