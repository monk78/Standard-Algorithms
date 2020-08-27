#include<bits/stdc++.h>
using namespace std;
void permute(char *in,int i){
    //base case:
    if(in[i]=='\0'){
        cout<<in<<endl;
        return;
    }
    //recursive case:
    for(int j=i;in[j]!='\0';j++)
        {
            cout<<"("<<in[i]<<in[j]<<")"<<endl;
            swap(in[i],in[j]);
            permute(in,i+1);
            swap(in[i],in[j]);//////this is called backt-trackig step:
        }
    }
int main(){
    cout<<"enter string:";
    char in[10];
    cin>>in;
    cout<<"total permutation of string:"<<endl;
    permute(in,0);
return 0;
}
