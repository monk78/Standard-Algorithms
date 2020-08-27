#include<iostream>
#include<stack>
using namespace std;
void printlist(stack<int>str){
    stack<int>st=str;
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

}
stack<int>middleD(stack<int>&st,int n){
    int val=n/2+1;
    int current=0,countt=0;
    stack<int>s;
    while(!st.empty()){
            ++countt;
            current=st.top();
            st.pop();
            if(countt!=val)
                s.push(current);
    }
    while(!s.empty()){
        st.push(s.top());
        s.pop();
    }
    return st;
}
int main()
{
    int n,num;
    stack<int>st;
    cout<<"enter number of elements you want to enter:";
    cin>>n;
    int k=n;
    while(n--)
        {
        cin>>num;
        st.push(num);
    }
    cout<<"entered-elements-are:";
    printlist(st);
    cout<<"after deleting middle elements are:";
    stack<int>ss=middleD(st,k-1);
    cout<<endl<<st.size()<<endl;
    printlist(ss);
    return 0;
}
