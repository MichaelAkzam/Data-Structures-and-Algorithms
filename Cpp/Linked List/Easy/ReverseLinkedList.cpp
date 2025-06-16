/*
Intuition
    As I had seen this problem before, the intuition was already there so nothing too complex was being processed in my mind.z

Approach


Complexity
- Time complexity:

- Space complexity:

*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr){
        ListNode* after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return prev;
}