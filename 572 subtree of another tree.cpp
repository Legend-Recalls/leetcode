class Solution {
public:
    //check if two trees are identical
    bool isIdentical(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true; 
        if (!root1 || !root2) return false; 
        if (root1->val != root2->val) return false; 

        return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false; 
        if (!subRoot) return true; 

        queue<TreeNode*> candidates;

        // DFS to collect nodes with the same value as subRoot
        dfsCollect(root, subRoot->val, candidates);

        // Check if any of the candidate nodes matches subRoot
        while (!candidates.empty()) {
            TreeNode* candidate = candidates.front();
            candidates.pop();
            if (isIdentical(candidate, subRoot)) {
                return true;
            }
        }

        return false;
    }
    void dfsCollect(TreeNode* node, int value, queue<TreeNode*>& candidates) {
        if (!node) return;
        if (node->val == value) {
            candidates.push(node);
        }
        dfsCollect(node->left, value, candidates);
        dfsCollect(node->right, value, candidates);
    }
};