/*
Intuition
    First thing that came to mind was just find the length of the linked list and traverse length - n steps until you hit
    the node right before you want to remove and do the needed operation.
    The one forward-pass solution is a bit trickier and involves the addition of an extra dummy node at the start to always
    reliably point to the first element of our original linked list. 

Approach
    For the optimal one forward-pass solution, we create a pointer at the dummy node (that comes before head) and a pointer
    that comes n steps after our head. We then traverse the linked list until our fast pointer hits the end, leaving us with
    the slow pointer pointing to the node before the node to be removed. We reconfigure its next pointer and return dummy->next.
    We return the above instead of head as cases where n equals the length of the whole linked list reconfigures the head.

Complexity
- Time complexity: O(N) where N is the length of the given linked list

- Space complexity: O(1) as we only have 1 extra dummy node and no other operations

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//SINGLE FORWARD-PASS OPTIMAL SOLUTION
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* fast = head;
    ListNode* dummy = new ListNode(-1, head);
    ListNode* slow = dummy;

    for(int i = 0; i < n; i++){
        fast = fast->next;
    }

    while(fast != nullptr){
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return dummy->next;
}

//OPTIMAL SOLUTION
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count = 0;
    ListNode* counter = head;

    while(counter != nullptr){
        counter = counter->next;
        count++;
    }

    int diff = count - n;

    if(diff == 0) return head->next;

    ListNode* curr = head;
    while(diff >= 0){
        diff--;
        if(diff == 0){
            if(curr->next->next == nullptr){
                curr->next = nullptr;
            }
            else{
                ListNode* temp = curr->next->next;
                ListNode* post = curr->next;
                post->next = nullptr;
                curr->next = temp;
            }
            break;
        }
        curr = curr->next;
    }
    return head;
}