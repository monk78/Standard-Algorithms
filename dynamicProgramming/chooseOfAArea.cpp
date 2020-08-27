/**                    Author:Monk_
 *                     Topic:Choose_Of_Area                                                         **/
#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define _for(i,a,b) for(i=a;i<b;i=i++)

#define _rfor(i,a,b) for(i=a;i>=b;i--)

#define mp(a,b) make_pair(a,b)

void fast(){
 std::ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
}
struct area{
    int a,b;
    area(int a,int b):a(a),b(b){};

};
int maxv(int a,int b,int c){
    return max(a,max(b,c));
}
int maxsur(int A,int B,area X,area Y,area Z,int last,map<pair<int,int>,int>&memo)
{
    if(A<=0||B<=0) return 0;
    pair<int,int>curr=mp(A,B);
    if(memo.find(curr)!=memo.end()) return memo[curr];
    int temp;
    switch(last){
     case 1: temp=1+max(maxsur(A+Y.a,B+Y.b,X,Y,Z,2,memo),maxsur(A+Z.a,B+Z.b,X,Y,Z,3,memo));
                break;
     case 2:temp=1+max(maxsur(A+X.a,B+X.b,X,Y,Z,1,memo),maxsur(A+Z.a,B+Z.b,X,Y,Z,3,memo));
            break;
    case 3:temp=1+max(maxsur(A+X.a,B+X.b,X,Y,Z,1,memo),maxsur(A+Y.a,B+Y.b,X,Y,Z,2,memo));
            break;
    }
    return memo[curr]=temp;
}
int getmaxsur(int A,int B,area X,area Y,area Z){

map< pair< int, int >, int> memo;

if(A<=0||B<=0) return 0;

return maxv(maxsur(A+X.a,B+X.b,X,Y,Z,1,memo),maxsur(A+Y.a,B+Y.b,X,Y,Z,2,memo),maxsur(A+Z.a,B+Z.b,X,Y,Z,3,memo));
}
int main(){
    fast();
    area X(3,2);
    area Y(-5,-10);
    area Z(-20,5);
    int A=20;
    int B=8;
    cout<<"maximum survival time is:"<<getmaxsur(A,B,X,Y,Z);
    return 0;
}
