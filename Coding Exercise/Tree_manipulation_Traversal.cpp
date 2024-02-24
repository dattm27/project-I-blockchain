#include <iostream>
#include <vector>

using namespace std;

// Definition for a tree node
class TreeNode {
public:
    int val;
    vector<TreeNode*> children; 

    TreeNode(int x) : val(x) {}
};

// Function to perform post-order traversal and search for a key
bool search(TreeNode* root, int key) {
    if (!root) return false;

    // Check if the current node contains the key
    if (root->val == key) return true;

    // Recursively search in children
     for (int i = 0; i < root->children.size(); i++) {
        if (search(root->children[i], key)) return true;
    }

    return false;
}
// Function to insert a new child node into the tree

bool insert(TreeNode* root, int parentVal, int val) {
    if (!root) return false;

    if (root->val == parentVal) {
        TreeNode* newNode = new TreeNode(val);
        root->children.push_back(newNode);
        return true;
    }

    for (int i = 0; i < root->children.size(); i++) {
        if (insert(root->children[i], parentVal, val)) {
            return true;
        }
    }

    return false;
}

// Post-Order Traversal
void postOrderTraversal(TreeNode* root) {
    if (!root) return;

    for (int i = 0; i < root->children.size(); i++) {
        postOrderTraversal(root->children[i]);
    }

    cout << root->val << " ";
}

// In-Order Traversal
void inOrderTraversal(TreeNode* root) {
    if (!root) return;

    if (root->children.size() > 0) {
        inOrderTraversal(root->children[0]);
    }

    cout << root->val << " ";

    for (int i = 1; i < root->children.size(); ++i) {
        inOrderTraversal(root->children[i]);
    }
}

// Pre-Order Traversal
void preOrderTraversal(TreeNode* root) {
    if (!root) return;

    cout << root->val << " ";

    for (int i = 0; i < root->children.size(); i++) {
        preOrderTraversal(root->children[i]);
    }

}

int main() {
  
    TreeNode* root;
    string s;
    while (cin>> s){
        if (s=="MakeRoot"){
            int r ;
            cin >> r;
            root = new TreeNode(r);
        }
        else if (s == "Insert"){
            int u; //nút mới có giá trị u 
            int v; //nút đã tồn tại trong cây
            cin >> u >> v;
            if (search(root, v)) insert(root, v, u);
        }
        else if (s == "InOrder") {inOrderTraversal(root); cout<< "\n";}
        else if (s == "PostOrder") {postOrderTraversal(root);cout<< "\n";}
        else if (s == "PreOrder") {preOrderTraversal(root); cout<< "\n";}
        else if (s == "*") break;
    }

    return 0;
}
