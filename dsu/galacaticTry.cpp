#include<bits/stdc++.h>
using namespace std;
#define NMAX 100100
#define INF 1000000000
int parent[NMAX],cmin[NMAX],sze[NMAX];
int N,M,C,ncc,i,j,k,sum,Cmin,a,b;
 int Find(int x) {
	int tx, rx;
	tx = x;
	while (parent[tx] > 0)
		tx = parent[tx];

	while (x != tx) {
		rx = parent[x];
		parent[x] = tx;
		x = rx;
	}

	return tx;
}
void Union(int i,int j){
    int ti=Find(i),tj=Find(j);
    if(ti==tj)return;
    ncc--;
    if(sze[ti]>=sze[tj]){
        parent[tj]=ti;
        sze[ti]+=sze[tj];
    }
    else{
        parent[ti]=tj;
        sze[tj]+=sze[ti];

    }
}
int main(){
    cin>>N>>M;
    ncc=N;
    for(i=1;i<=N;i++){
        cmin[i]=-1;
        parent[i]=0;
        sze[i]=1;
    }
    for(k=1;k<=M;i++){
       cin>>a>>b;
       Union(a,b);
    }
    if(ncc==1){
        cout<<"0"<<endl;
        return 0;
    }
    for(i=1;i<=N;i++){
        cin>>C;
        if(C<0)continue;
        j=Find(i);
        if(cmin[j]<0 || C<cmin[j])cmin[j]=C;
    }
    sum=0;
    Cmin=INF;
    for(int i=1;i<=N;i++){
        if(parent[i]>0)continue;
        if(cmin[i]<0){
            cout<<"-1"<<endl;
            return 0;
        }
        sum+=cmin[i];
        if(cmin[i]<Cmin)Cmin=cmin[i];
    }
    cout<<sum+(ncc-2)*Cmin<<endl;
    return 0;

}
