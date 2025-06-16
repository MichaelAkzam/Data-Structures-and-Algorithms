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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(-1);
    ListNode* curr = &dummy;

    while(list1 != nullptr && list2 != nullptr){
        if(list1->val <= list2->val){
            curr->next = list1;
            list1 = list1->next;
        }
        else{
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    if(list1 != nullptr)
        curr->next = list1;
    if(list2 != nullptr)
        curr->next = list2;
    
    return dummy.next;
}
