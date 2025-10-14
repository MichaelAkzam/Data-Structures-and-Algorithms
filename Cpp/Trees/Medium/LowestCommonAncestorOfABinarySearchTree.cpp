/*
Intuition
    First thing that came to mind was storing all elements of the BST in a hashmap where the value would be
    the child and the key its parent, creating this ancestor relation for an easy pull-up.
    But, I am also thinking that we already have a BST, it should be possible to just manipulate it to find
    the common ancestor.
    I coded the hashmap solution in O(N) time complexity and O(N) space complexity, but it fails to take 
    into consideration that the node itself could be the ancestor, failing test cases on leetcode.

Approach
    As we are given a BST, at any split that might happen between our root node and p and q, we know that
    this node is going to be the lowest common ancestor. So, starting at the given root, if p and q are
    both larger than the root, we move our root to the next node in the right subtree, and if they are both
    smaller, we move our root to the next node in the left subtree. if none of these conditions are true, 
    which means that we got to a point where p and q are both part of now 2 different subtrees, than we 
    have found our root to be the LCA.

Complexity
- Time complexity: O(h) 

- Space complexity: O(h) for the recursive call stack

  where h is the height of the tree
*/

#include <queue>
#include <unordered_map>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 // UNOPTIMAL SOLUTION (DOES NOT PASS LEETCODE AS NEVER TAKES NODE ITSELF AS AN ANCESTOR)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    std::queue<TreeNode*> qu;
    std::unordered_map<TreeNode*, TreeNode*> m;

    qu.push(root);
    while(!qu.empty()){
        TreeNode* curr = qu.front(); qu.pop();

        if(curr->left){
            qu.push(curr->left);
            m[curr->left] = curr;
        }
        if(curr->right) {
            qu.push(curr->right);
            m[curr->right] = curr;
        }
    }

    TreeNode* node1 = p;
    TreeNode* node2 = q;

    while(node1 != node2){
        if(m[node1]) node1 = m[node1];
        if(m[node2]) node2 = m[node2];
    }
    return node1;
}

// RECURSIVE SOLUTION
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || !p || !q) return nullptr;

    if(std::min(p->val, q->val) <= root->val && std::max(p->val, q->val) >= root->val){
        return root;
    }
    if(std::min(p->val, q->val) <= root->val && std::max(p->val, q->val) <= root->val){
        return lowestCommonAncestor(root->left, p, q);
    }
    else if(std::min(p->val, q->val) >= root->val && std::max(p->val, q->val) >= root->val){
        return lowestCommonAncestor(root->right, p, q);
    }
    return nullptr;
}

// OPTIMAL RECURSIVE SOLUTION
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || !p || !q) return nullptr;

    if(std::max(p->val, q->val) < root->val){
        return lowestCommonAncestor(root->left, p, q);
    }
    else if(std::min(p->val, q->val) > root->val){
        return lowestCommonAncestor(root->right, p, q);
    }
    else
        return root;
}