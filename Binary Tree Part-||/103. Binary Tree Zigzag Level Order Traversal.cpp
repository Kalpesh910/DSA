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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>qu;
        vector<vector<int>>ans;
        qu.push(root);
        if(root==NULL)  return {};
        if(root->left==NULL && root->right==NULL)   return {{root->val}};
        int level = 0;
        while(!qu.empty()){
            vector<int>temp;
            int si=qu.size();
            for(int i=0; i<si; i++){
                TreeNode* te = qu.front();
                qu.pop();
                temp.push_back(te->val);
                if(te->left != NULL){
                    qu.push(te->left);
                }
                if(te->right != NULL){
                    qu.push(te->right);
                }
            }
            if(level%2==1){
                int i=0, j=temp.size()-1;
                while(i<j){
                    swap(temp[i],temp[j]);
                    i++;
                    j--;
                }
            }
            ans.push_back(temp);
            level++;
        }
        return ans;
    }
};
