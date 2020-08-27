#include<bits/stdc++.h>
using namespace std;
class vec{
    int k;
public:
    vec(int x){
     k=x;
    }
     operator int(){
       return k;
     }
};
int main(){
    vec v1(4);
    int l=v1;
    cout<<l<<endl;
return 0;
}
