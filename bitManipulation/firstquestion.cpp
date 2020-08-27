#include<bits/stdc++.h>
using namespace std;
#define A 256
#define ll long long
ll max(char *str)
{
    ll count[A] = {0};
    ll len = strlen(str);
    for (int i=0; i<len; i++)
        count[str[i]]++;

    ll max = -1;
    char result;
    for (ll i = 0; i < len; i++) {
        if (max < count[str[i]]) {
            max = count[str[i]];
            result = str[i];
        }
    }

    return max;
}
int main(){
    ll num;
    cin>>num;
    char ch[100000];
    cin>>ch;
    ll mm=max(ch);
    if(mm==-1)
        cout<<num-1<<endl;
    else
    cout<<num-mm<<endl;
    return 0;
}
