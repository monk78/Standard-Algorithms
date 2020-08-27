#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    char data;
    node *left,*right;
    node(char d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
int searchh(char arr[],int start,int endd,char value){
    int i;
    for(i=start;i<=endd;i++){
        if(arr[i]==value)return i;
    }
}
node *build(char in[],char pre[],int instrt,int inend){
    static int preind=0;
    if(instrt>inend)return NULL;
    node *tnode=new node(pre[preind++]);
    if(instrt==inend)return tnode;
    int inindex=searchh(in,instrt,inend,tnode->data);
    tnode->left=build(in,pre,instrt,inindex-1);
    tnode->right=build(in,pre,inindex+1,inend);
    return tnode;
}
void printInorder(node *root){
    if(root==NULL)return;
    printInorder(root->left);
    cout<<root->data;
    printInorder(root->right);
}
int main(){
    char in[]={ 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[]={ 'A', 'B', 'D', 'E', 'C', 'F' };
    int len=sizeof(in)/sizeof(in[0]);
    node *root=build(in,pre,0,len-1);
    printInorder(root);
}
