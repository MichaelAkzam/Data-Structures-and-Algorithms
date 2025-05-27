/*
Intuition
    As this was a binary search problem, I first thought of where i could apply binary search to help me solve
    for anthing that would get me closer to an answer. Having k as the changing var (in the binary search case
    being the mid point) was how I wanted to approach the issue. The lower bound would be 1 as this could be the
    min time everytime - based on the value of h of course, and the upperbound would be the current max found, as
    any bigger number would be redundant. The rest seems self-explanatory, but everytime we find a new value for
    k, we would go ahead and and re-compute the traversal of the array with the k value to see what would be the 
    resulting speed, until we hit the smallest possible k.

Approach
    We perform binary search on all possible elements of k from 1 to the max element of given piles. After each
    new k computation, we perform a total of the hours taken to eat all the piles given k, and based off of this
    result, we fix our left and right bounds of the binary search. Everytime we find a k that is smaller than h, 
    we store that number in a variable that gets returned at the end of the program.


Complexity
- Time complexity: O(N * log(M)) where N is the size of the array being traversed and M the max number of bananas in a pile

- Space complexity: O(1)

*/
#include <vector>
#include <algorithm>

long long traversals(std::vector<int>& piles, int k) {
    long long count = 0;
    for(int i = 0; i < piles.size(); i++){
        count += std::ceil(static_cast<double>(piles[i]) / k);
    }
    return count;
}
int minEatingSpeed(std::vector<int>& piles, int h) {
    int l = 1, r = *std::max_element(piles.begin(), piles.end());
    int res = r;
    while (l <= r){
        int k = (l + r) / 2;
        long long trav = traversals(piles, k);
        if(trav <= h){
            res = k;
            r = k - 1;
        }
        else if(trav > h)
            l = k + 1;
    }
    return res;
}