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

    Node* bfs (Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*,Node*>mp;
        queue<Node*>q;
        q.push(node);
        mp[node] = new Node(node->val);
        while(!q.empty()){
            Node* oldNode = q.front();
            q.pop();
            for(Node* x : oldNode->neighbors){
                if(!mp.count(x)){
                    Node* temp = new Node(x->val);
                    mp[x]=temp;
                    q.push(x);
                }
                mp[oldNode]->neighbors.push_back(mp[x]);

            }
        }
        return mp[node];
    }




    Node* dfs(Node* node , unordered_map<Node*,Node*> &mp){
        if (node == nullptr) return nullptr;
        if(mp.count(node)){
            return mp[node];
        }

        Node* newNode = new Node(node->val);
        mp[node] = newNode;
        for(Node* x : node->neighbors){
            newNode->neighbors.push_back(dfs(x,mp));
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        return bfs(node);
        return dfs(node,mp);
    }
};
