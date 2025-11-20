/*
Intuition
    In meeting rooms 1, we were just checking if all meetings can be done sequentially.
    In the variation, we are checking the minimum number of days needed to fit all the
    schedules.
    First thing that comes to mind is to go through the array, and for every pair that
    does not match previous schedules, create a new day for.
    Going over [(0,40),(5,10),(15,20)], and having [0,40] as our first pair, we compare 
    the next to it and check if its starting time comes after our current end time. If 
    so, these 2 pairs could fit in the same day, if not we add a day to our counter (
    could be a DS if needed). So, we would have [0,40] on day 1, and [5,10] on day 2.
    We would now take the last element and compare it to both day1 and day2, and see if 
    it fits into any of the above. We can see that it can fit after day 2, so we add it
    there, and return our total days needed.

    For this to work, we would need a way to store those pairs, and have efficient enough
    of a loookup to check them again, at each iteration (maybe..?).
    We could have an ordered map where the key is the day, and the value is a pair of the
    blocked time we have. This results in an O(N*M) time complexity, as we are looping over
    all elements N, and checking at each iteration if it belongs to the dictionary of size 
    M.


Approach
    The correct approach turned out to be different. We start by sorting both starts and 
    end times in 2 separate arrays. We then access each from their respective starting points
    using a 2 pointer approach, iterating until we hit the end of the start times array.
    We increment our count whenever we have a meeting start, and decrement the same counter
    whenever a meeting ends. We keep track of the max amount of days needed, and return 
    this value.

Complexity
- Time complexity: O(NlogN) for sorting

- Space complexity: O(N)

    where N is the size of the intervals vector provided
*/

#include <vector>

// Definition of Interval:
class Interval {
 public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

// OPTIMAL 2 POINTER APPROACH
int minMeetingRooms(std::vector<Interval>& intervals) {
    if(intervals.size() < 2) return intervals.size();
    std::vector<int> start, end;

    for(auto& pair : intervals){
        start.push_back(pair.start);
        end.push_back(pair.end);
    }

    std::sort(start.begin(), start.end());
    std::sort(end.begin(), end.end());

    int s = 0, e = 0;
    int res = -1, counter = 0;
    while(s < start.size()){
        if(start[s] > end[e]){
            e++;
            counter--;
        }
        else {
            s++;
            counter++;
        }
        res = std::max(res, counter);
    }
    return res;
}

#include <queue>
// OPTIMAL PQ APPROACH
int minMeetingRooms(std::vector<Interval>& intervals) {
    if(intervals.size() < 2) return intervals.size();
    std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
        return a.start < b.start;
    });

    std::priority_queue<int, std::greater<int>> pq;
    for(const auto& interval : intervals){
        if(!pq.empty() && interval.start >= pq.top()){
            pq.pop();
        }
        pq.push(interval.end);
    }
    return pq.size();
}