//O(n) time and O(1) space
class Solution {
  public:
	vector<int> inorderTraversal(TreeNode* root) {
		TreeNode *curr=root;
		vector<int>nodes;
		while(curr!=nullptr){
			if(curr->left){
				TreeNode *pred=curr->left;
				while(pred->right && pred->right!=curr)pred=pred->right;
				if(pred->right==nullptr){
					pred->right=curr;
					curr=curr->left;
				}
				else{
					pred->right=nullptr;
					nodes.push_back(curr->val);
					curr=curr->right;
                    
				}
			}
			else{
				nodes.push_back(curr->val);
				curr=curr->right;
			}
            
		}
		return nodes;
	}
};
