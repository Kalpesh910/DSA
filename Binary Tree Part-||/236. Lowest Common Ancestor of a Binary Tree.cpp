/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //TC: O(n*n)
    //SC:O(n)+O(n)
//     bool checkLeftChild(TreeNode* node, TreeNode* p, TreeNode* q){
//         if(node==NULL)  return false;
//         if(node == p || node==q)    return true;
//         if(checkLeftChild(node->left, p, q)){
//             return true;
//         }
//         if(checkLeftChild(node->right, p, q)){
//             return true;
//         }
//         return false;
//     }
//     bool checkRightChild(TreeNode* node, TreeNode* p, TreeNode* q){
//         if(node==NULL)  return false;
//         if(node == p || node==q)    return true;
//         if(checkLeftChild(node->left, p, q)){
//             return true;
//         }
//         if(checkLeftChild(node->right, p, q)){
//             return true;
//         }
//         return false;
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
//         queue<TreeNode*>qu;
//         qu.push(root);
//         if(p==root || q==root)  return root;
//         while(!qu.empty()){
//             TreeNode* node = qu.front();
//             qu.pop();
//             if(p==node|| q==node)   return node;
//             bool left = checkLeftChild(node->left, p, q);
//             bool right = checkRightChild(node->right, p, q);
//             if(left && right)
//                 return node;
//             if(left)    qu.push(node->left);
//             if(right)   qu.push(node->right);
//         }
//         return root;
//     }
    
    
    
        // TC: O(n)
        // ASC: O(n)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)    return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left==NULL)  return right;
        if(right==NULL) return left;
        return root;
    }
    
};
