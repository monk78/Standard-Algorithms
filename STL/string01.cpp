#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    cout<<"initital string is:"<<str<<endl;
    str.push_back('s');
    cout<<str;
}

