#include<bits/stdc++.h>
using namespace std;
static int cnt=0;
class test{
 public:
     test(){
      ++cnt;
      cout<<"cons:object number "<<cnt<<" created";
     }
     ~test(){
      cout<<"dest:object number "<<cnt<<" destroyed";
      cnt--;
     }
};
int main(){
    cout<<"\ninside main"<<endl;
    test t1;
    t1.~test();
    {
        cout<<"\ninside block:"<<endl;
        test t2,t3;
        cout<<"{"<<cnt<<"}"<<endl;
        cout<<"\n leaving block:"<<endl;

    }
    cout<<"\n back in main:"<<endl;
    cout<<cnt<<endl;
    cout<<"bosdk gaand:"<<endl;
return 0;
}

