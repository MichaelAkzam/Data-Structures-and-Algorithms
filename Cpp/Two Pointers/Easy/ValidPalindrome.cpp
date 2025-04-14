/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/
#include <string>

bool isPalindrome(std::string s) {
    int left = 0;
    int right = s.size() - 1;

    while(left < right){
        while(!isalnum(s[left]) && left < right){
            left++;
        }
        while(!isalnum(s[right]) && left < right){
            right--;
        }

        if(tolower(s[left]) != tolower(s[right])){
            return false;
        }
        left++;
        right--;
    }
    return true;
}