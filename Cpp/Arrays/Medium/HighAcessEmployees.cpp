/*
Intuition
    store each employee in map with a vector of access times.
    Sort those access times for each employee, or just have a priority queue
    then go over each employee, and have a sliding window approach over
    the sorted vector comparing idx with idx + 2, and if the difference is less
    than 60, we store that employee within a result vector.

    Solution above should be solved in O(nlogn) time.
    We could use a set as its ordered (lowest to largest time) and can
    be iterated through.
    Unfortunately, a set wouldnt work as we cannot randomly access/index the set
    so we would need to find a different way to work it out.

Approach


Complexity
- Time complexity: O(NlogN), as sorting and iterating through would be O(K) * O(MlogM).
                   where K is the number of employees, and M the size of each vector.
                   
- Space complexity: O(N)

where N is the total length of the given access_times variable

*/

#include <string>
#include <vector>
#include <unordered_map>

int timeToMinutes(const std::string& timeStr) {
    // Extract the hour part (first two digits)
    int hours = std::stoi(timeStr.substr(0, 2));
    // Extract the minute part (last two digits)
    int minutes = std::stoi(timeStr.substr(2, 2));
    
    return (hours * 60) + minutes;
}

std::vector<std::string> findHighAccessEmployees(std::vector<std::vector<std::string>>& access_times) {
    std::unordered_map<std::string, std::vector<int>> m;

    for(const auto& log : access_times){
        m[log[0]].push_back(std::stoi(log[1]));
    }

    std::vector<std::string> res;
    for(auto& pair : m){
        if(pair.second.size() < 3)
            continue;
        std::sort(pair.second.begin(), pair.second.end());
        for(int i = 2; i < pair.second.size(); i++){
            if(pair.second[i] - pair.second[i-2] < 100){
                res.push_back(pair.first);
                break;
            }
        }
    }
    return res;
}
