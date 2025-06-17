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
    TreeNode* findMin(TreeNode* root){
        TreeNode* temp = root;
        while(temp->left != nullptr){
            temp = temp->left;
        }
        return temp;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if (root == nullptr) return root;
        else{
            // phase 1 search the key
            if (key < root->val){
                root->left = deleteNode(root->left,key);
            }else if (key > root->val){
                root->right = deleteNode(root->right,key);
            }else{
                // phase 2 delete the key
                // delete the leaf node or node with 1 child
                if (root->left == nullptr) return root->right;
                else if (root->right == nullptr) return root->left;
                // delete the node with 2 child
                else{
                    root->val = findMin(root->right)->val;
                    root->right = deleteNode(root->right,root->val);
                }
            }
        }
        return root;

    }
};