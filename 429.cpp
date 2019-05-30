/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(!root) return res;
        queue<Node*>q;
        q.push(root);
        auto last=root,l=last;
        vector<int>curlevel;
        while(q.size()){
            auto cur=q.front();
            curlevel.push_back(cur->val);
            q.pop();
            for(auto it:cur->children){
                q.push(it);
                l=it;
            }
            if(last==cur){
                last=l;
                res.push_back(curlevel);
                curlevel.clear();
            }
        }
        return res;
    }
};
