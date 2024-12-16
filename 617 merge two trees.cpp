class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // If both nodes are NULL, return NULL
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        
        // If one of the nodes is NULL, return the other node
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }
        
        // If both nodes are non-null, merge them
        TreeNode* mergedNode = new TreeNode(root1->val + root2->val);
        mergedNode->left = mergeTrees(root1->left, root2->left);
        mergedNode->right = mergeTrees(root1->right, root2->right);
        
        return mergedNode;
    }
};
