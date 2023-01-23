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
  
    //   Time Complexity: O(N)
    //   Space Complexity: O(N)
  
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        TreeNode* temp;
        q.push(root);
        while(!q.empty()){
            int length = q.size();
            vector<int>level;
            for(int i=0; i<length; i++){
                temp = q.front();
                q.pop();
                if(temp){
                    level.push_back(temp->val);
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                }
            }
            if(!level.empty()){
                ans.push_back(level);
            }
        }
        
        return ans;
    }
};
