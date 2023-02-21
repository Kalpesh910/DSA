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
      // BEST SPACE COMPLEXITY
    void flatten(TreeNode* root){
      TreeNode* node=root;
      while(node){
        if(node->left==NULL && node->right==NULL){
          break;
        }
        else if(node->left == NULL){
          node=node->right;
        }
        else{
          TreeNode* temp = node->right;
          node->right=node->left;
          node->left = NULL;
          TreeNode* node2 = node->right;
          while(node2->right){
            node2 = node2->right;
          }
          node2->right = temp;
          node = node->right;
        }
      }
    }
          // BEST TIME COMPLEXITY
    // void flatten(TreeNode* root) {
    //   stack<TreeNode*>st;
    //   TreeNode* node=root;
    //   while(node){
    //     if(node->left==NULL && node->right==NULL){
    //       if(st.empty())  break;
    //       else{
    //         node->right=st.top();
    //         node=node->right;
    //         st.pop();
    //       }
    //     }
    //     else if(node->left==NULL){
    //       node = node->right;
    //     }
    //     else{
    //       TreeNode* temp = node->right;
    //       node->right=NULL;
    //       node->right=node->left;
    //       node->left=NULL;
    //       if(temp!=NULL)
    //         st.push(temp);
    //       node=node->right;
    //     }
    //   }
    // }
};
