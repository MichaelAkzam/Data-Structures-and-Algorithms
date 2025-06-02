/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/

#include <string>
// Non-working solution
int characterReplacement(std::string s, int k) {
    int longest = 0, counter = 1;
    int l = 0, r = 1;
    char prev = s[l];
    const int initialK = k;
    int firstOcc = -1;
    while(r < s.size()){
        char curr = s[r];
        if (curr != prev && k >= 0){
            if(k == initialK)
                firstOcc = curr;
            k--;
        }
        counter++;
        if(k < 0){
            counter = 1;
            l = firstOcc;
            r = l+1;
            prev = s[firstOcc];
        }
        longest = std::max(longest, counter);
        r++;
    }
    return longest;
}

// OPTIMAL SOLUTION
#include <unordered_map>

int characterReplacement(std::string s, int k) {
    int l = 0, maxf = 0;
    int res = 0;
    std::unordered_map<int, int> map;

    for(int r = 0; r < s.size(); r++){
        map[s[r]]++;
        maxf = std::max(maxf, map[s[r]]);

        while((r - l + 1) - maxf > k){
            map[s[l]]--;
            l++;
        }
        res = std::max(res, (r - l + 1));
    }
    return maxf;
}