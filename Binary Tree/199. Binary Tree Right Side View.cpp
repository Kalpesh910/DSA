/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)   return{};
        if(!root->left && !root->right)  return {root->val};
        queue<TreeNode* >qu;
        qu.push(root);
        while(!qu.empty()){
            int si=qu.size();
            vector<int>temp;
            for(int i=0; i<si; i++){
                TreeNode* te = qu.front();
                qu.pop();
                temp.push_back(te->val);
                if(te->left)
                    qu.push(te->left);
                if(te->right)
                    qu.push(te->right);
            }
            ans.push_back(temp[si-1]);
        }
        return ans;
    }
};
