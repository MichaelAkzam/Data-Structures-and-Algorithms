/*
Intuition
    The main difference between this problem and the BST version is that the Node's 
    values don't matter, so a different approach will be needed.
    Because of that, I am inclined to use a BFS traversal to get the levels of each node,
    and find the common ancestor through that (in some way). Or, we could balance the tree
    and use the LCA of a BST's solution to do so (comparing left and right values basically).
    Using a BFS approach, we could try to label every node with the node's level as well as
    if its a subset of the main roots' left subtree or right subtree. After doing such,
    we can easily then pick up both p and q's nodes and decide what to return as common
    ancestor.
    After drawing it out, this cannot be achieved as now a level is considered a root, which
    is not what we are looking for.

Approach
    We will go with a DFS approach, traversing the left and right subtrees. We will be looking
    for our first node that is equal to either p or q, and from there we have 2 choices, either 
    the second element will be in the right substree, in which case the common ancestor 
    would be the root provided. Or, the second element is a descendant of the first element 
    found, which in this case we would return the first element found and we would return the
    first element as being the LCA. This works knowing that no duplicate values are allowed,
    and we are guarenteed that both p and q exist in the tree provided.

Complexity
- Time complexity:

- Space complexity:

*/

