/*
Intuition
    First thing that comes to mind to solve this problem is to split the linked list in 2 from the halfway point so we do not have to always go to the end of the LL and fetch
    the last element over and over for an O(N*M) complexity.
    We will then need to reverse the second half of the linked list so that traversal is not an issue, and we then pop the head every time until second half is empty, and insert
    each time into the first half. 

Approach
    The problem at hand is a combination of some fundamental linked list manipulations such as reverseing, iterating, and merging
    linked lists. As the inution stated, we split our initinal LL into 2 parts after finding the total number of nodes, reversed the
    second half, then popped the head of it into the first half until the second half ran out of nodes.

Complexity
- Time complexity: O(N), where N is the length of head

- Space complexity: O(1)

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//OPTIMAL SOLUTION
void reorderList(ListNode* head) {
    int n = 0;

    ListNode* counter = head;
    while(counter != nullptr){
        counter = counter->next;
        n++;
    }

    ListNode* firstHalf = head;

    //(n-1)/2 so that firstHalf always equal to or greater in size than secondHalf
    for(int i = 0; i < (n-1)/2; i++){
        firstHalf = firstHalf->next;
    }

    ListNode* secondHalf = firstHalf->next;
    firstHalf->next = nullptr;
    // Set firstHalf back to head
    firstHalf = head;

    //Reverse secondHalf
    ListNode* reversePrev = nullptr;

    while(secondHalf != nullptr){
        ListNode* reverseTemp = secondHalf->next;
        secondHalf->next = reversePrev;
        reversePrev = secondHalf;
        secondHalf = reverseTemp;
    }
    secondHalf = reversePrev;

    //Pop head from secondHalf and insert into firstHalf
    while(secondHalf != nullptr){
        ListNode* temp = firstHalf->next;
        ListNode* temp2 = secondHalf->next;

        secondHalf->next = nullptr;
        firstHalf->next = secondHalf;
        firstHalf->next->next = temp;
        
        secondHalf = temp2;
        firstHalf = temp;
    }
}

