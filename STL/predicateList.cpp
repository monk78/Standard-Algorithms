#include<iostream>
#include<iterator>
#include<list>
using namespace std;
bool checkprime(const int&value){
    int i;
    for(i=2;i<value;i++){
        if(value%i==0)
                return false;

    }
    return true;
}
int main(){
list<int>l;
int n,num;
cout<<"enter total number:";
cin>>n;
for(int i=0;i<n;i++){
    cin>>num;
    l.push_back(num);
}
list<int>::iterator it;
l.remove_if(checkprime);

return 0;
}
