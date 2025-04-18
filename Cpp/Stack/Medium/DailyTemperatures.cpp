/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/

#include <vector>
// Unoptimal Solution O(n^2)
std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    std::vector<int>res;
    for(int i = 0; i < temperatures.size()-1; i++){
        int j = i+1;
        bool found = false;
        while(j < temperatures.size()){
            if (temperatures[i] < temperatures[j]){
                res.push_back(j-i);
                found = true;
                break;
            }
            j++;
        }
        if(!found){
            res.push_back(0);
        }
    }
    res.push_back(0);
    return res;
}

// Optimal Solution
std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    // Non-strictly decreasing stack
    std::vector<std::pair<int, int>> monoStack;
    std::vector<int> res(temperatures.size(), 0);

    for(int i = 0; i < temperatures.size(); i++){
        while(!monoStack.empty() && monoStack.back().first < temperatures[i]){
            res[monoStack.back().second] = (i - monoStack.back().second);
            monoStack.pop_back();
        }
        monoStack.push_back({temperatures[i], i});
    }
    return res;
}