/*
Intuition

Fairly straightforward and common way to find duplicates in a list/vector,
so it was easy to get a simple solution running.
Might be trickier for someone that has no prior DSA knowledge and is just starting off,
especially if C++ is not their strong suit.


Approach

We traverse the vector and populate our unordered map with keys being the 
numbers in the given list, and the value being anything (in my case just a 1)
to add it to the unordered map. We check beforehand if the key already exists
in our map, and if it does, it means that we have already seen
this number as we traversed the vector, meaning it is a duplicate. We return.


Complexity
- Time complexity:

O(N) as we have to traverse the whole vector in the worst case

- Space complexity:

O(N) as we have to create and populate up to n elemets in our unordered map
*/

#include <vector>
#include <unordered_map>

bool ContainsDuplicates(std::vector<int>& nums){
    std::unordered_map<int, int> map = {};
    for(const auto& num : nums){
        if(map[num] != 0){
            return true;
        }
    }
    return false;
}