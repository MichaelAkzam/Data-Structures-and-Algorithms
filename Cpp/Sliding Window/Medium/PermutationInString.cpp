/*
Intuition
    As the key of a sliding window problem is to never pull back the right pointer, we will need to find a way to fix a window and check if all the characters within
    that window match the characters of the string given.
    We will move both the left and right pointer starting at index 0 until 1 character from string 1 is found in string 2.
    The hard part of the problem is how to actual do those checks in O(1) time especially the different permutations found (given that s1.length could go to 10^4).
    To finalize the problem, once the current window we are at checks the above boxes and has a size equal to the size of s1, we return true, else we continue until
    r hits the end of array, and then we return false.
    As I was building the above with 2 exact hash maps that I copy into one another whenever we change count, I was able to pass 91/108 test cases. One of the failures 
    pointed to a very obvious thing that I missed, which was actually closing the window from the left as I go rather than jumping ahead to the right pointer. This
    is a big mistake from my part which I will try to fix by adding back the count to the last element removed and moving l++ and rechecking continuously until the element
    is not in the string (which is where breaking would work).

Approach


Complexity
- Time complexity: O(26N) ~ O(N)

- Space complexity: O(26) ~ O(1)

*/

#include <string>
#include <unordered_map>
using std::string;
// OPTIMAL SOLUTION
bool checkInclusion(string s1, string s2) {
    int l = 0;
    std::unordered_map<char, int> map;
    std::unordered_map<char, int> copy;

    for(auto c : s1){
        map[c]++;
        copy[c]++;
    }

    for(int r = 0; r < s2.size();){
        while(copy.find(s2[r]) != copy.end()){
            copy[s2[r]]--;
            while(copy[s2[r]] < 0 && l <= r){
                copy[s2[l]]++;
                l++;
            }
            if((r - l + 1) == s1.size())
                return true;
            r++;
        }
        copy = map;
        if(r > l)
            l = r;
        else{
            r++;
            l = r;
        }
    }
    return false;
}