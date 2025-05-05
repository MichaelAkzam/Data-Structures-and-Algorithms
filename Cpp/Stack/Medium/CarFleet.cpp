/*
Intuition


Approach

The best way to approach this problem is to simulate all cars at once. This means that we calculate how
many laps each cars needs to get to the target, and step through the problem from there. Once we get all
the laps of each position and speed, we create a vector of pairs as we will then need to sort this vector
by position. This is done for the sole purpose of finding what cars become fleets along the way. Once sorted,
the logic is simple, if a car at an earlier position takes less laps (or equak) to get to target than the next car
(based off position), then they will form a fleet before or at the target. If not, then they will be seperate fleets.
The problem can be either solved with a stack and popping elements that belong to the same fleet, or by having a
global variable (in my case) for better memory efficiency.

Complexity
- Time complexity:

- Space complexity:

*/

#include <vector>

int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    std::vector<std::pair<int, double>> laps;

    for(int i = 0; i < position.size(); i++){
        laps.push_back(std::make_pair(position[i], double((target - position[i])) / speed[i]));
    }
    // Sorted in descending position order
    std::sort(laps.begin(), laps.end(), std::greater{});
    
    int fleets = 0;
    double time = 0.0;
    for(auto &p : laps){
        if (p.second > time){
            fleets++;
            time = p.second;
        }
    }
    return fleets;
}