#include<bits/stdc++.h>
using namespace std;
void removeX(char s[]){
 if(s[0]=='\0')
    return;
 else{
    if(s[0]!='x')
        removeX(s+1);
    else{
            int i=1;
        for(;s[i]!='\0';i++){
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        removeX(s);
    }
 }
}
int main(){
 cout<<"enter String:";
 char str[100];
 cin>>str;
 int l=strlen(str);
 removeX(str);
 cout<<str<<endl;
 return 0;
}
