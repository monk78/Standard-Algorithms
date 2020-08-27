#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f
#define min -9999999
#define max1 1<<16
#define max2 max1<<2

struct Node{
    int pre;
    int suff;
    int total;
    int maxsub;
    Node(){
    pre=suff=total=maxsub=-inf;
    }
};
Node mergee(Node left,Node right){
    Node parent;
    parent.pre=max(left.pre,left.total+right.pre);
    parent.suff=max(right.suff,right.total+left.total);
    parent.total=left.total+right.total;
    parent.maxsub=max({left.maxsub,right.maxsub,left.suff+right.pre});
    return parent;
}
void constructTreeUtil(Node* tree, int arr[], int start,
int end, int index)
{

    /* Leaf Node */
    if (start == end) {

        // single element is covered under this range
        tree[index].total = arr[start];
        tree[index].suff = arr[start];
        tree[index].pre = arr[start];
        tree[index].maxsub = arr[start];
        return;
    }

    // Recursively Build left and right children
    int mid = (start + end) / 2;
    constructTreeUtil(tree, arr, start, mid, 2 * index);
    constructTreeUtil(tree, arr, mid + 1, end, 2 * index + 1);

    // Merge left and right child into the Parent Node
    tree[index] = mergee(tree[2 * index], tree[2 * index + 1]);
}
Node* constructTree(int arr[], int n)
{
    // Allocate memory for segment tree
    int x = (int)(ceil(log2(n))); // Height of the tree

    // Maximum size of segment tree
    int max_size = 2 * (int)pow(2, x) - 1;
    Node* tree = new Node[max_size];

    // Fill the allocated memory tree
    constructTreeUtil(tree, arr, 0, n - 1, 1);

    // Return the constructed segment tree
    return tree;
} Node queryUtil(Node* tree, int ss, int se, int qs,
                               int qe, int index)
{
    // No overlap
    if (ss > qe || se < qs) {

        // returns a Node for out of bounds condition
        Node nullNode;
        return nullNode;
    }

    // Complete overlap
    if (ss >= qs && se <= qe) {
        return tree[index];
    }

    // Partial Overlap Merge results of Left
    // and Right subtrees
    int mid = (ss + se) / 2;
    Node left = queryUtil(tree, ss, mid, qs, qe,
                                     2 * index);
    Node right = queryUtil(tree, mid + 1, se, qs,
                              qe, 2 * index + 1);

    // merge left and right subtree query results
    Node res = mergee(left, right);
    return res;
}

/* Returns the Maximum Subarray Sum between start and end
   It mainly uses queryUtil(). */
int query(Node* tree, int start, int end, int n)
{
    Node res = queryUtil(tree, 0, n - 1, start, end, 1);
    return res.maxsub;
}


int main(){
int N,M;
cin>>N;
int arr[N];
for(int i=0;i<N;i++){
    cin>>arr[i];
}
Node *Tree=constructTree(arr,N);
cin>>M;
while(M--){
    int x,y;
    cin>>x>>y;
    cout<<query(Tree,x,y,N)<<endl;
}
return 0;
}
