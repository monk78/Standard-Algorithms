#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<char>st;
    int countt=0;
    string str;
    cout<<"enter strings:";
    cin>>str;
    int l=str.length();
    for(int i=0;i<l;i++)
    {
        if(str[i]=='(')
        {
          st.push(str[i]);
        }
        else if(str[i]==')')
        {
            if(st.top()=='(')
               {
                ++countt;
                st.pop();
               }
        }
    }
    cout<<"max valid length::"<<countt;
    return 0;
}
