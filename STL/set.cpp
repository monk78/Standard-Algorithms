//set
#include<iostream>
#include<set>
#include<iterator>
using namespace std;
int main(){
    set<int>s;
    cout<<"enter total  number:";
    int num,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        s.insert(num);
    }
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++)
            cout<<*it<<" ";
    cout<<"total unique number is:"<<s.size();
    cout<<"enter number to be erased:";
    int er;
    cin>>er;
    //s.erase(s.begin(),s.find(er));//removing total number upto er::
    s.erase(er);
     for(it=s.begin();it!=s.end();it++)
            cout<<*it<<" ";
    return 0;
}
