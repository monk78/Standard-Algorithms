/*************
  Author : Monk_      ||     Topic : Diameter of Tree
Explanation : We will apply bottom up approach to find the diameter of tree:
                                                 ***************/
#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
        data=d;
        left=NULL;
        right=NULL;
        }
};
Node *buildTree(){
    int d;
    cin>>d;
    if(d==-1)
        return NULL;
    Node *root=new Node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
}
//with class pair:
class Pair{
 public:
        int height;int diam;
};
Pair diam(Node *root){
  Pair p;
    if(root==NULL){
        p.height=0;
        p.diam=0;
        return p;}
    Pair left=diam(root->left);
    Pair right=diam(root->right);
    p.height=max(left.height,right.height)+1;
    p.diam=max(left.height+right.height,max(left.diam,right.diam));
    return p;
}
////using pair utility function:
pair<int,int>fast(Node *root){
    pair<int,int>p;
    if(root==NULL)
    {
        p.first=0;p.second=0;
        return p;
    }
    pair<int,int>left=fast(root->left);
    pair<int,int>right=fast(root->right);
    p.first=max(left.first,right.first)+1;
    p.second=max(left.first+right.first,max(left.second,right.second));
    return p;

}
int height(Node *root){
    if(root==NULL)
            return 0;
    return 1+max(height(root->left),height(root->right));
}
int main(){
     Node *root=buildTree();
     Pair v=diam(root);
     pair<int,int>pp=fast(root);
     cout<<"with class pair:";
     cout<<"height is:"<<v.height;
     cout<<"\n";
     cout<<"diameter is:"<<v.diam;
     cout<<endl<<"with pair utility:";
     cout<<pp.first<<" "<<pp.second<<endl;
 return 0;
}
