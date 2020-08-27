#include<bits/stdc++.h>
using namespace std;
bool check;
class node{
 public:
     int data;
     node *left,*right;
     node(int d){
        data=d;
        left=NULL;
        right=NULL;
     }
};
int searchh(int arr[],int start,int endd,int value){
    int i;
    for(i=start;i<endd;i++){
        if(arr[i]==value)return i;
    }
}
node *build(int in[],int pre[],int instrt,int inend){
    static int preind=0;
    if(instrt>inend)return NULL;
    node *tnode=new node(pre[preind++]);
    if(instrt==inend)return tnode;
    int inindex=searchh(in,instrt,inend,tnode->data);
    tnode->left=build(in,pre,instrt,inindex-1);
    tnode->right=build(in,pre,inindex+1,inend);
    return tnode;
}
void fxn(node *root,int post[],int N){
    static int i=0;
    if(root==NULL)return;
    fxn(root->left,post,N);
    fxn(root->right,post,N);
    if(post[i++]!=root->data)check=false;


}
int main(){
    int N;
    cin>>N;
    check=true;
    int pre[N],post[N],in[N];
    for(int i=0;i<N;i++){
        cin>>pre[i];
    }
    for(int i=0;i<N;i++){
        cin>>post[i];
    }
    for(int i=0;i<N;i++){
        cin>>in[i];
    }
    node *root=build(in,pre,0,N-1);
    fxn(root,post,N);
    if(check)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
return 0;

}
