/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        mp[node]=new Node(node->val,vector<Node*>());
        for(int i=0;i<node->neighbors.size();i++){
            if(!mp[node->neighbors[i]]){
                mp[node]->neighbors.push_back(nullptr);
                mp[node]->neighbors[mp[node]->neighbors.size()-1]=cloneGraph(node->neighbors[i]);
            }
            else mp[node]->neighbors.push_back(mp[node->neighbors[i]]);
        }
        return mp[node];
    }
};
