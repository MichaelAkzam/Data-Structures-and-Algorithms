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

