#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char str[]="geeksforgeeks";
    memset(str,'v',sizeof(str));
    cout<<str;
    return 0;
}
