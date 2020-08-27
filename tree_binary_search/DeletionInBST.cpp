//Deletion in Binary Search Tree a element with k
int inorderSucc(Node *root){
    Node *current=root;
    while(current->left){
        current=current->left;
    }
    return current->data;
}

Node * deleteNode(Node *root,  int x)
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
/****
 deleting all elements greater than k in BST
*****/

Node* buildTree(Node* root,int key){
	if(root==NULL)
		return NULL;
	if(root->data==key){
		return root->left;
	}
	else if(root->data>key)
		return buildTree(root->left,key);
	else{
		root->right=buildTree(root->right,key);
	}
	return root;
}

Node* deleteNode(Node* root, int key)
{
	root=buildTree(root,key);
	return root;
}
