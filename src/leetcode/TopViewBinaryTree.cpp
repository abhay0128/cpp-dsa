#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;   
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int> preorder) {
    idx++;
    if(idx >= preorder.size() || preorder[idx] == -1) {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void topView(Node* root) {
    queue<pair<Node*, int>> q; // (node, horizontal distance)
    map<int, int> topViewMap; // horizontal distance, node value
    q.push({root, 0});

    while(q.size()>0) {
        Node* curr = q.front().first;
        int currHD = q.front().second;
        q.pop();
        if(topViewMap.find(currHD) == topViewMap.end()) {
            topViewMap[currHD] = curr->data; // store the first node at this horizontal distance
        }
        if(curr->left != NULL) {
            q.push({curr->left, currHD - 1});
        }
        if(curr->right != NULL) {
            q.push({curr->right, currHD + 1});
        }
    }
    for(auto it : topViewMap) {
        cout << it.second << " "; // print the top view nodes
    }
    cout << endl;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}; // Example input
    Node* root = buildTree(preorder);
    cout << "Top view of the binary tree: ";
    topView(root);
    cout << endl;
    return 0;
}