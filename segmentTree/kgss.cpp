#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) printf("%lld",n)
const int mod=1e9+7;
const int sze=1e5+2;
int N;
pii Tree[4*sze];
int arr[sze];

void build(int arr[],int index,int s,int e){
	if(s>e)return;
	if(s==e){
		Tree[index]={arr[s],s};
		return;
	}
	int mid=(s+e)/2;
	build(arr,2*index,s,mid);
	build(arr,2*index+1,mid+1,e);
	pii left=Tree[2*index];
	pii right=Tree[2*index+1];
	Tree[index]=max(left,right);
	return;
}

pii query(int index,int qs,int qe,int s,int e){
	if(qs>e || qe<s)return {INT_MIN,INT_MIN};
	if(s>=qs && e<=qe)return Tree[index];
	int mid=(s+e)/2;
	pii left=query(2*index,qs,qe,s,mid);
	pii right=query(2*index+1,qs,qe,mid+1,e);
	return max(left,right);
}
void update(int index,int s,int e,int pos,int value){
	if(s==e && s==pos){
		Tree[index].first=value;
		
		arr[s]=value;
		return;
	 }
	 
	int mid=(s+e)/2;
	if(mid>=pos)
	update(2*index,s,mid,pos,value);
	else
	update(2*index+1,mid+1,e,pos,value);
	
	Tree[index]=max(Tree[2*index],Tree[2*index+1]);
}


signed main(){
	Fast;
	sl(N);	
	for(int i=0;i<N;i++)sl(arr[i]);
	build(arr,1,0,N-1);
	int Q,qs,qe;
	sl(Q);
	while(Q--){
		char choice;
		 sl(choice); 
         sl(qs);sl(qe);
         qs--,qe--;
         if(choice=='Q'){
            int fmx=query(1,qs,qe,0,N-1).second;
            int smx1=INT_MIN,smx2=INT_MIN;
            if(fmx!=qs){
				smx1=query(1,qs,fmx-1,0,N-1).first;
			}
			if(fmx!=qe){
				smx2=query(1,fmx+1,qe,0,N-1).first;
			}
         cout<<arr[fmx]+max(smx1,smx2)<<endl;
	  }
         else update(1,0,N-1,qs,qe+1);	
	}
  return 0;
}
