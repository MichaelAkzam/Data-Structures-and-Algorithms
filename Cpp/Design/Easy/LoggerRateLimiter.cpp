/*
Intuition
    Very basic and introductory design problem with a straightforward description.

Approach
    Keep the mapping of message and timestamp stored in a hashmap. For each
    message that comes in, either compare it has already been seen at a different
    timestamp that we analyze for the 10 second limit, or its a new message and
    we add it to the hashmap. We return true if the message is new or has not been
    for at least 10 seconds after it popped up. We return false otherwise.

Complexity
- Time complexity: O(1)
    As each insertion/access/count method take constant time on average.

- Space complexity: O(K)
    where K is the number of unique messages being encountered in the logs.

*/
#include <string>
#include <unordered_map>

class LoggerRateLimiter
{
private:
    std::unordered_map<std::string, int> map;
public:
    LoggerRateLimiter(/* args */);

    bool shouldPrintMessage(int timestamp, std::string message) {
        // if the message already seen, update time
        if(map.count(message)){
            if(timestamp - map[message] > 10){
                map[message] = timestamp;
                return true;
            }
            return false;
        }
        map[message] = timestamp;
        return true;
    }
};

