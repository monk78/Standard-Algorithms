#include<bits/stdc++.h>
using namespace std;
int main(){
multiset< int,int > m;
multiset<int,int>::iterator it;
m.insert(make_pair(4,7));
for(it=m.begin();it!=m.end();it++)
        cout<<it->first;







return 0;
}
