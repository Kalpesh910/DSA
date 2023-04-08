/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* curr, unordered_map<int, Node*>&mp, Node* node){
      for(auto it: node->neighbors){
        if(mp[it->val]==0){
          Node* newNode = new Node(it->val);
          mp[it->val]=newNode;
          curr->neighbors.push_back(newNode);
          dfs(newNode , mp, it);
        }
        else{
          curr->neighbors.push_back(mp[it->val]);
        }
      }
    }
    Node* cloneGraph(Node* node) {
      if(node==NULL)
        return node;
      Node* copy = new Node(node->val);
      unordered_map<int, Node*>mp;
      mp[copy->val]=copy;
      for(auto it: node->neighbors){
        if(mp[it->val]==0){
          Node* newNode = new Node(it->val);
          mp[it->val]=newNode;
          copy->neighbors.push_back(newNode);
          dfs(newNode, mp, it);
        }
        else{
          copy->neighbors.push_back(mp[it->val]);
        }
      }
      return copy;
    }
};
