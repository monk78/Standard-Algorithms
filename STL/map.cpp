//Key value and mapped value:no two key value can have same mapped value::
#include<iostream>
#include<map>
#include<iterator>
using namespace std;
int main()
{
    map<int,int>m;
    int key,element,n;
    cout<<"enter total number:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"key:";
        cin>>key;
        cout<<"element";
        cin>>element;
        m.insert(pair<int,int>(key,element));
    }
    map<int,int>::iterator it;
    cout<<"key\telement"<<endl;
    for(it=m.begin();it!=m.end();++it){
     cout<<it->first<<"\t"<< it->second;
     cout<<endl;
    }
    return 0;
}

