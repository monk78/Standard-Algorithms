//unlike map,,the pair of this should be unique:
#include<iostream>
#include<map>
#include<iterator>
using namespace std;
int main(){
    multimap<int,int>mp;
    int n,key,element,er;
    cout<<"enter total element:";
    cin>>n;
    cout<<"key\telement:";
    int k=n;
    while(n--){
    cin>>key>>element;
    mp.insert(pair<int,int>(key,element));
    }
    map<int,int>::iterator it;
    cout<<"key\telement:";
    for(it=mp.begin();it!=mp.end();++it)
    {
        cout<<it->first<<"\t"<<it->second;
        cout<<endl;

    }
    cout<<"enter the key u want to delete:";
    cin>>er;
    mp.erase(er);
     for(it=mp.begin();it!=mp.end();++it){
        cout<<it->first<<"\t"<<it->second;
        cout<<endl;
    }
    return 0;
}

