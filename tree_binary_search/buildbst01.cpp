
#include<bits/stdc++.h>
using namespace std;
/* A Binary Tree node */
class TNode
{
    public:
    int data;
    TNode* left;
    TNode* right;
    TNode(int d){
    data=d;
    left=NULL;
    right=NULL;
    }
};

//struct TNode* newNode(int data);

/* A function that constructs Balanced Binary Search Tree from a sorted array */
TNode* ATB(int arr[], int start, int end)
{
    /* Base Case */
    if (start > end)
      return NULL;

    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    TNode *root = new TNode(arr[mid]);

    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =ATB(arr, start, mid-1);

    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = ATB(arr, mid+1, end);

    return root;
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */

/* A utility function to print preorder traversal of BST */
void preOrder(TNode* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

/* Driver program to test above functions */
int main()
{
    int n,i;
    scanf("%d",&n);
    int arr[n];

    for(i=0;i<n;i=i++) scanf("%d",&arr[i]);
    /* Convert List to BST */
    TNode *root = ATB(arr, 0, n-1);
    printf("n PreOrder Traversal of constructed BST ");
    preOrder(root);

    return 0;
}

