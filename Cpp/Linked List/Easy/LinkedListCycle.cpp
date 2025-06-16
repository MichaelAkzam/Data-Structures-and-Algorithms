/*
Intuition
    First thing that comes to mind to solve this problem is to split the linked list in 2 from the halfway point so we do not have to always go to the end of the LL and fetch
    the last element over and over for an O(N*M) complexity.
    We will then need to reverse the second half of the linked list so that traversal is not an issue, and we then pop the head every time until second half is empty, and insert
    each time into the first half. 

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

bool hasCycle(ListNode *head) {
    if(head == nullptr || head->next == nullptr)
        return false;

    ListNode* curr = head;
    ListNode* adv = head;

    while(adv != nullptr && adv->next != nullptr){
        curr = curr->next;
        adv = adv->next->next;

        if (curr == adv){
            return true;
        }
    }
    return false;
}