#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
public:
    TreeNode* root;

    BST() {
        root = NULL;
    }

    // Function to insert a key into the BST
    TreeNode* insert(TreeNode* node, int key) {
        if (node == NULL) {
            TreeNode* newNode = new TreeNode(key);
            return newNode;
        }

        if (key < node->val) {
            node->left = insert(node->left, key);
        } else if (key > node->val) {
            node->right = insert(node->right, key);
        }

        return node;
    }

    // Function to perform pre-order traversal and print the visited nodes
    void preOrderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }

        cout << node->val << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
};

int main() {
    BST bst;

    string command;
    int key;

    while (cin >> command) {
        if (command == "insert") {
            cin >> key;
            bst.root = bst.insert(bst.root, key);
        } else if (command == "#") {
            break;
        }
    }

    // Perform pre-order traversal and print the visited nodes

    bst.preOrderTraversal(bst.root);

    return 0;
}
