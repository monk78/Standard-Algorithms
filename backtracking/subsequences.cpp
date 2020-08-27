//by varun pandey:this is a program of generating subsequences:
//thanks
#include<bits/stdc++.h>
using namespace std;
void subs(char *in,char *out,int i,int j){
    //it is a base case
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }
    // this is a recursive case:
    out[j]=in[i];
    subs(in,out,i+1,j+1);//include the current char:
    subs(in,out,i+1,j);//exclude the current char:
}
int main(){
    cout<<"enter string:";
    char ch[10],out[10];
    cin>>ch;
    cout<<"generating subsequences => "<<endl;
    subs(ch,out,0,0);
    return 0;
}
