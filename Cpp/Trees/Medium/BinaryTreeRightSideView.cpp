/*
Intuition
    At every level of the binary tree, we can print at most one node, which should be the rightmost node
    that isnt bocked from the right side view by any other node.
    So, technically the output vector will always be of size = h, where h is the length of the longest 
    path in the binary tree.


Approach


Complexity
- Time complexity:

- Space complexity:

*/

#include <vector>
#include <queue>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

std::vector<int> rightSideView(TreeNode* root) {
    if(!root) return {};

    std::vector<int> res = {};
    std::queue<std::pair<TreeNode*, int>> q;
    int level = 1;

    q.push(std::make_pair(root, level));

    while(!q.empty()){
        TreeNode* curr = q.front().first; 
        level = q.front().second; q.pop();

        if(res.size() < level)
            res.push_back(curr->val);
        
        if(curr->right) q.push(std::make_pair(curr->right, level+1));
        if(curr->left)   q.push(std::make_pair(curr->left, level+1));
    }
    return res;
}