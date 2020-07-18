//Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

//Basically, the deletion can be divided into two stages:

//Search for a node to remove.
//If the node is found, delete the node.
//Note: Time complexity should be O(height of tree).

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;  // no tree
        if (root->val == key) {     // if key reached, delete key (key is root)
            if (!root->right) {     // if there's no right child, left becomes root, effectively deleting the key node
                TreeNode* left = root->left;    // return pointer = root->left
                delete root;                    // delete key node
                return left;                    // return new root
            }
            else {                  // if there is a right child
                TreeNode* right = root->right;  // pointer to root->right
                while (right->left)             // find successor?
                    right = right->left;
                swap(root->val, right->val);    // 'bubble' up
            }
        }
        root->left = deleteNode(root->left, key);   // recurse
        root->right = deleteNode(root->right, key);
        return root;
    }
};