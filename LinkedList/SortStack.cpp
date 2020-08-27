#include<iostream>
#include<stack>
using namespace std;
stack<int>sortt(stack<int>st1){
    stack<int>st2;
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }
    return st2;
}
void showStack(stack<int>st){
while(!st.empty()){
    cout<<st.top()<<" ";
    st.pop();
}
}
int main()
{
    stack<int>st;
    int n,num;
    cout<<"enter total elements-\n";
    cin>>n;
    while(n--){
        cin>>num;
        st.push(num);
    }
    cout<<"before sorting stack-is-\n";
    showStack(st);
    st=sortt(st);
    cout<<"\nafter-sortig-stack-i-\n:";
    showStack(st);
    return 0;
}
