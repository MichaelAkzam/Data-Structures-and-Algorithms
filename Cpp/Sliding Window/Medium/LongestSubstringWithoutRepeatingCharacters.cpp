/*
Intuition
    The first question I ask myself is can the following be solved in 1 traversal of the array.
    After some thought, a clear way to solve this problem using a sliding window approach is to start
    at index 0 and index 0+1, and to check for each new element if it is in the current substring.
    If it is not, go back to index 0+1 and index 0+1+1.
    The tricky part in this approach is how to factor in the search for the element in the current substring.
    I could build a hashmap of each substring found..? So for example s = "abcabcbb", my hashmap would look
    like the following: "a", "ab", "abc", etc., but that wouldnt help to check for elements in substring..

    Based off the hint given to generate all substrings and validate each while keeping track of maxSubstring,
    one way to do so is the following:
        for(int i = 0; i < maxLen; i++)
            for(int j = i + 1, j < maxLen; j++)
                validate substring
                    if correct -> check for length
        
        return maxLength
    An O(n^2) solution seems to be the only solution here, and if correct, we can go from there.
    Issue is we cannot validate substring in O(1). 

    Another way to keep it O(n^2) is: 
        for(int i = 0; i < maxLen; i++)
            for(int j = i + 1, j < maxLen; j++)
                add substring to hashmap (or other DS)
        
        for all substrings
            validate substring
                if valid, compare length to correct maxSubstringLength

        return maxLength

    This would have an O(n^2 + n^2) = O(n^2) solution if validation can be done in O(n) time complexity.

    Validation basically checks for duplicates.
    A simple way to solve this would be the following check:
    if(length of substring > length of unordered_set(substring)), then we have duplicates.

    Turns out substr method is of O(n), as a new string object gets created of n elements.
    So technically our approach would be of O(n^3), which is less than ideal. 

Approach
    The current optimal approach follows a sliding window pattern where we keep on adding to it and shrinking it based off duplicate elements.
    In just one traversal, we are able to start adding elements to the set, and whenever a duplicate tries to be added to it, we basically delete
    from the start of the window up until we hit the already existing character. This allows us to keep track of the max substring while still
    checking for duplicates in constant time (.find method on an unordered set is of O(1)).
    The tricky part is to understand the nuances between how the problem is solved and how it is actually implemented, as the unordered set does
    not technically keep track of any order to the chars added, but rather eliminates elements from what we envision as a string that we are manipulating, 
    and just keeps count of the total elements currently present.
    


Complexity
- Time complexity: O(N) as we go through all elements of string s.

- Space complexity: O(M) as we handle an unordered set of up to M elements where M is the total number of elements of string s.

*/

#include <algorithm>
#include <unordered_set>
// UNOPTIMAL SOLUTION
bool validateSubstring(std::string s) {
    std::unordered_set<char> newS(s.begin(), s.end());
    return (s.size() == newS.size());
}
    
int lengthOfLongestSubstring(std::string s) {
    size_t maxSubstring = 0;
    std::vector<std::string> substrings;
    for(int i = 0; i < s.size(); i++){
        for(int j = i + 1; j < s.size(); j++){
            substrings.push_back(s.substr(i, j-i));
        }
    }

    for(auto &sub : substrings){
        if(validateSubstring(sub))
            maxSubstring = std::max(maxSubstring, sub.size());
    }
    return maxSubstring;
}

// OPTIMAL SOLUTION
int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> duplicates;
    int l = 0;
    int maxLength = 0;

    for(int r = 0; r < s.size(); r++){
        while(duplicates.find(s[r]) != duplicates.end()){
            duplicates.erase(s[l]);
            l++;
        }
        duplicates.insert(s[r]);
        maxLength = std::max(maxLength, int(duplicates.size()));
    }
    return maxLength;
}