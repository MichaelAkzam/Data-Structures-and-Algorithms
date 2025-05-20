/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/

#include <queue>
#include <vector>
// Unoptimal O(NlogN) solution
int longestConsecutive(std::vector<int>& nums) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int counter = 1;
    if(nums.size() == 0){
        return 0;
    }
    for(const auto& num : nums){
        minHeap.push(num);
    }
    int prev, curr, maxCount = 1;
    if(!minHeap.empty()){
        prev = minHeap.top();
        minHeap.pop();
    }
    while(!minHeap.empty()){
        curr = minHeap.top();
        minHeap.pop();
        // skip duplicates
        if(prev == curr){
            continue;
        }
        if(prev + 1 == curr){
            counter++;
        }
        else{
            counter = 1;
        }
        maxCount = std::max(maxCount, counter);
        prev = curr;
    }
    return maxCount;
}

#include <unordered_set>
// Optimal Solution
int longestConsecutive(std::vector<int>& nums) {
    if(nums.size() == 0){
        return 0;
    }
    int counter = 1, longest = 1;
    std::unordered_set<int> numSet(nums.begin(), nums.end());

    for(auto& num : numSet){
        // If this is the smallest integer of a possible consecutive sequence (i.e, there is no smaller element found in set)
        if(numSet.find(num-1) == numSet.end()){
            int curr = num;
            while(numSet.count(curr+1)){
                counter++;
                curr++;  
            }
            longest = std::max(longest, counter);
        }
        counter = 1;
    }
    return longest;
}

#include <unordered_map>
// Optimal Solution with hash map
int longestConsecutive(std::vector<int>& nums) {

    if (nums.size() == 0)
        return 0;

    std::unordered_map<int, int> map;
    int longest = 1;

    for(int i = 0; i < nums.size(); i++){
        map[nums[i]] = 1;
    }
    
    for(auto& num : map){
        int key = num.first, counter = 1;
        if(map.count(key-1))
            continue;
        else{
            while(map.count(key+1)){
                counter++;
                longest = std::max(counter, longest);
                key++;
            }
        }
    }
    return longest;
}