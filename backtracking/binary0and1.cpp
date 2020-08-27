//generatign all substring such that no two are consequitive 1:
#include<bits/stdc++.h>
using namespace std;
void subutil(int k,char str[],int i){
    if(i==k){
        str[i]='\0';
        cout<<str<<endl;
        return;
    }
    //if it is 1 then add 0;
    if(str[i-1]=='1'){
        str[i]='0';
        subutil(k,str,i+1);
    }
    if(str[i-1]=='0'){
        //either we can put 0 or 1:
        str[i]='0';//putting 0;
        subutil(k,str,i+1);
        str[i]='1';//putting 1;
        subutil(k,str,i+1);
    }

}
void generateall(int k){
    if(k<=0)
        return;
    char str[k];
    //generating all substring with 0
    str[0]='0';
    subutil(k,str,1);
    //generating all substrig with 1
    str[0]='1';
    subutil(k,str,1);
}
int main(){
    int k;
cout<<"enter length:";
cin>>k;
cout<<"generating all substrings such that no two are consequitive:"<<endl;
generateall(k);
return 0;
}
