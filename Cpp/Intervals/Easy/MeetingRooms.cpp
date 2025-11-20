/*
Intuition
    We are trying to see if a given schedule could be attended by 1 person
    without any conflicts happening.
    A conflict is defined as 2 meetings that occur at the same time.
    Ex: (0, 10) and (5, 15) have an overlap, so => conflict.
        (0, 10) and (10, 20) have no overlap.
    If we are able to sort the intervals vector based off the starting
    time, then we can use the first 2 elements as reference for the next
    set of intervals

Approach
    As stated above, we sort through the intervals based on starting time,
    then compare end time of the current interval to the start time of the
    next interval. If any misalignments, we return false.

Complexity
- Time complexity: O(NlogN) for sorting

- Space complexity: O(1) (with sorting being in place)

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

bool canAttendMeetings(std::vector<Interval>& intervals) {
    if(intervals.size() < 2) return true;

    std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });

    int end = intervals[0].end;
    for(int i = 1; i < intervals.size(); i++){
        if(end > intervals[i].start)
            return false;
        end = intervals[i].end;
    }
    return true;
}