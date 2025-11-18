#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

/*
Create tree with  index as value to manipulate later on
Example:
TreeNode(5) would result in the following
                1
               / \
              2   3
             / \
            4   5
*/
TreeNode* createTree(int totalNodes){
    int index = 1;
    TreeNode *root = new TreeNode(index++);
    std::queue<TreeNode*> q;
    q.push(root);

    while(index <= totalNodes){
        TreeNode *curr = q.front();
        q.pop();

        curr ->left = new TreeNode(index++);
        q.push(curr ->left);
        
        if(index > totalNodes)  break;

        curr->right = new TreeNode(index++);
        q.push(curr->right);
    }
    return root;
}
// Node -> left -> right with print within
void printPreOrder(TreeNode* root){
    std::stack<TreeNode*> s;
    s.push(root);
    std::cout << "[";
    bool first = true;
    while(!s.empty()){
        TreeNode* node = s.top(); s.pop();
        if(!first) std::cout << ", ";
        first = false;
        std::cout << node->val;
        
        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left);
    }
    std::cout << "]" << std::endl;
}

// Node -> Left -> Right
void printPreOrder(TreeNode *root){
    if(!root) return;

    std::vector<int> res;
    std::stack<TreeNode*> s;
    s.push(root);
    
    while(!s.empty()){
        TreeNode *curr = s.top(); s.pop();
        res.push_back(curr->val);
        
        if(curr->right != nullptr) s.push(curr->right);
        if(curr->left != nullptr)  s.push(curr->left);
    }

    std::cout << "[";
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i];
        if (i != res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Left -> Node -> Right
void printInOrder(TreeNode *root){
    if(!root) return;

    std::vector<int> res;
    std::stack<TreeNode*> s;
    TreeNode* curr = root;

    while(curr != nullptr || !s.empty()){
        while(curr != nullptr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        res.push_back(curr->val);
        s.pop();
        curr = curr->right;
    }

    std::cout << "[";
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i];
        if (i != res.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

// Left -> Right -> Node
void printPostOrder(TreeNode *root){
    if(!root) return;

    std::vector<int> res;
    std::stack<TreeNode*> s;
    s.push(root);

    while(!s.empty()){
        TreeNode* curr = s.top(); s.pop();
        res.push_back(curr->val);

        if(curr->left != nullptr) s.push(curr->left);
        if(curr->right != nullptr) s.push(curr->right);
    }

    std::cout << "[";
    for(int i = res.size()-1; i >= 0; i--){
        std::cout << res[i];
        if (i != 0) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    TreeNode* tree = createTree(5);
    std::cout << "Pre Order is: ";  printPreOrder(tree);
    std::cout << "In Order is : ";   printInOrder(tree);
    std::cout << "Post Order is:"; printPostOrder(tree);
}
