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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>>mp;
        queue<pair<TreeNode*, int>>qu;
        qu.push({root, 0});
        mp[0].push_back(root->val);
        while(!qu.empty()){
            int si=qu.size();
            map<int, vector<int>>mp2;
            for(int i=0; i<si; i++){
                auto it= qu.front();
                qu.pop();
                TreeNode* temp = it.first;
                int height = it.second;
                if(temp->left){
                    qu.push({temp->left, height-1});
                    mp2[height-1].push_back(temp->left->val);
                }
                if(temp->right){
                    qu.push({temp->right, height+1});
                    mp2[height+1].push_back(temp->right->val);
                }
            }
            for(auto it: mp2){
                sort(it.second.begin(), it.second.end());
                mp[it.first].insert(mp[it.first].end(), it.second.begin(), it.second.end());
            }
        }
        vector<vector<int>>ans;
        for(auto it: mp){
            vector<int>t=it.second;
            // sort(t.begin(), t.end());
            ans.push_back(t);
        }
        return ans;
    }
};
