qs link ---> https://leetcode.com/problems/clone-graph/description/


class Solution {
public:
    unordered_map<Node*, Node*> cloned;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // If this node is already cloned, return the clone
        if (cloned.find(node) != cloned.end()) {
            return cloned[node];
        }

        // Clone the current node
        Node* copy = new Node(node->val);
        cloned[node] = copy;

        // Clone all the neighbors recursively
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(neighbor));
        }

        return copy;
    }
};
