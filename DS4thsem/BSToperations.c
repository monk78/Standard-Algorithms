//
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *newnode(int d){
  struct Node *temp=(struct Node*)malloc(sizeof(struct Node*));
  temp->data=d;
  temp->left=NULL;
  temp->right=NULL;
};

void InOrder(struct Node *root){
    if(root==NULL)return;
    InOrder(root->left);
    printf("%d",root->data);
    InOrder(root->right);
}
void preOrder(struct Node *root){
    if(root==NULL)return;
    printf("%d",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(struct Node *root){
    if(root==NULL)return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d",root->data);
}


struct Node *insert(struct Node *root,int key){
  if(root==NULL)return newnode(key);
  if(root->data>key)root->left=insert(root->left,key);
  else if(root->data<key)root->right=insert(root->right,key);
  return root;
}
int inorderSucc(struct Node *root){
    struct Node *current=root;
    while(current->left){
        current=current->left;
    }
    return current->data;
}

struct Node * deleteNode(struct Node *root,  int x)
{
    if(root==NULL) return NULL;
    if(x<root->data)root->left=deleteNode(root->left,x);
    else if(x>root->data)root->right=deleteNode(root->right,x);
    else{
        if(root->left==NULL){
            struct Node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
                struct Node *temp=root->left;
                free(root);
                return temp;

        }
        else{
            int succ=inorderSucc(root->right);
            root->data=succ;
            root->right=deleteNode(root->right,succ);
        }

    }
    return root;
}
int main(){
    int N,num;
    struct Node *root = NULL;
    printf("total N:");
    scanf("%d",&N);
    printf("enter numbers:");
    scanf("%d",&num);
    root = insert(root, num);
    for(int i=1;i<N;i++){
        scanf("%d",&num);
        insert(root,num);
    }
    printf("inorder: ");
    InOrder(root);
    printf("\n");
    printf("preorder: ");
    preOrder(root);
    printf("\n");
    printf("postorder: ");
    postOrder(root);
    printf("\n");
    printf("enter number to be deleted:");
    scanf("%d",&num);
    root=deleteNode(root,num);
    printf("\nafter deletion:-\n");
    printf("inorder: ");
    InOrder(root);
    printf("\n");
    printf("preorder: ");
    preOrder(root);
    printf("\n");
    printf("postorder: ");
    postOrder(root);
    printf("\n");
    return 0;
}
