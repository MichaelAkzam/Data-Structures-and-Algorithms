/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/

#include <queue>
#include <unordered_map>
#include <vector>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> map;
    std::priority_queue<std::pair<int, int>> pq;
    std::vector<int> res;

    for(int i = 0; i < nums.size(); i++){
        map[nums[i]] += 1;
    }

    for(const auto& p : map){
        pq.push(std::make_pair(p.second, p.first));
    }

    while(k > 0){
        int num = pq.top().second;
        res.push_back(num);
        pq.pop();
        k--;
    }
    return res;
}