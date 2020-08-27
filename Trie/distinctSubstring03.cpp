#include<iostream>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<sstream>
#include<algorithm>
 
using namespace std;
#define read(x) scanf("%d",&x)
#define Read(x,y) scanf("%d%d",&x,&y)
#define sRead(x,y,z)  scanf("%d%d%d",&x,&y,&z)
#define gc(x)  scanf(" %c",&x);
#define mmt(x,y)  memset(x,y,sizeof x)
#define write(x) printf("%d\n",x)
#define ios   ios::sync_with_stdio(false);cin.tie(0);
#define INF 0x3f3f3f3f
#define ll long long
const ll mod = 1e9 + 7;
#define pdd pair<double,double>
const int N = 4e5+5;
const int  M = 1e6 + 5;
char s[1005];
int trie[M][26],child = 1;
void init()
{
    mmt(trie,0);
    child = 1;
}
int main()
{
    int T;
    read(T);
    while(T--){
        init();
        scanf("%s",s);
        int len = strlen(s);
        int sum = 0;
        for(int i = 0;i < len ;++i){
            int parent = 1;
            for(int j = i;j < len;++j){
                int ch = s[j] - 'A';
                if(trie[parent][ch] == 0) {
                    sum ++;
                    trie[parent][ch] = ++child;
                }
                parent = trie[parent][ch];
            }
        }
        cout<<sum<<endl;
    }
 }
