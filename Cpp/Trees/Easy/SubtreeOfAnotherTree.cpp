/*
Intuition
    Once we solve the easy sameTree leetcode problem, finding a subtree within a tree
    is much easier.
    Tricky bit is the commented out code in the isSubtree function.
    It fails a few test cases as the return exists the whole function, so if the values 
    turned out to match but the structure doesn't, we never actually check deeper
    occurences of subRoot anywhere else.
    The second part that also needs to be carefully added are some of the edge cases.
    If the subRoot is NULL, it is still considered a subtree of the original tree, but the
    other way around is not true.

Approach
    we will compare trees to check if they are similar using a helper function. If they are,
    we return true.
    If not, we keep on checking our root's left and right subtrees.

Complexity
- Time complexity: O(N * M)

- Space complexity: O(N + M) due to stack depth

where N is the number of nodes in root and M is the number of nodes in subroot.

*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// OPTIMAL SOLUTION
class Solution {
private:
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return root == subRoot;
        if(root->val != subRoot->val) return false;
        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // similar to same tree problem but on a subtree, start comparaison when both roots identical
        if(!subRoot) return true;
        if(!root) return false;

        // if(root->val == subRoot->val)
        //     return isSameTree(root, subRoot);
        if(isSameTree(root, subRoot)) return true;

        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};