// Approach 1 :-
// time complexity O(n),
//space = O(n)

class Solution {
public:
    vector<int>inorder;
    void dfs(TreeNode* root){
        if(root==nullptr)return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* constructtree(int start,int end){
        if(start>end)return nullptr;
        int mid = (start+end)>>1;
        TreeNode* leftsub = constructtree(start,mid-1);
        TreeNode* rightsub = constructtree(mid+1,end);
        return new TreeNode(inorder[mid],leftsub,rightsub);
    }
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        int n = inorder.size();
        return constructtree(0,n-1);
    }
};
