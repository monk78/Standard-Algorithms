#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int k=m/n;
    char str[m],str2[k][n];
    cin>>str;
    int j=0;
    for(int i=0;i<k;i++){
        for(int x=0;x<n;x++)
        {
            str2[i][x]=str[j++];
        }
    }
    for(int i=k-1;i>=1;i--)
        {
            if(i%2!=0){
                for(int x=0;x<n;x++)
                    cout<<str2[i][x];
                }
        }
       for(int i=0;i<k;i++)
        {
            if(i%2==0){
                for(int x=0;x<n;x++)
                    cout<<str2[i][x];}
            }

return 0;

}
