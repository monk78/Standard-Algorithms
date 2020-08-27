#include<bits/stdc++.h>
using namespace std;
void printcomb(char *input,char *output,int index,int outl){
    if(input[index]=='\0'){
            output[outl]='\0';
        cout<<output<<endl;
    return;
    }
    //copy current index to output string:
    output[outl]=input[index];
    output[outl+1] = ',';
    printcomb(input,output,index+1,outl+2);
    //
    if(input[index+1]!='\0'){
            printcomb(input,output,index+1,outl+1);
    }
}
int main(){
    char input[100];
    cout<<"enter the string-number:";
    for(int i=0;i<5;i++)
         cin>>input[i];
    input[5]='\0';
    char *output=new char[100];
    output[0]='\0';
    printcomb(input,output,0,0);
    return 0;
}
