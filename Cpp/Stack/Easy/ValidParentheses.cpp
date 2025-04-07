/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/



// Implementation with strings, passes with 0ms runtime
#include <string>

bool isValid(std::string s) {
    std::string stack;

    for(const auto& c : s){
        if (stack.size() != 0 && ((c == '}' && stack.back() == '{') || (c == ']' && stack.back() == '[') || (c == ')' && stack.back() == '('))){
            stack.pop_back();
        }
        else{
            stack.push_back(c);
        }
    }
    return stack.empty();
}

//Implementation with stack class, , passes with 0ms runtime
#include <stack>

bool isValid(std::string s) {
    std::stack<char> stk;

    for(const auto& c : s){
        if (stk.size() != 0 && ((c == '}' && stk.top() == '{') || (c == ']' && stk.top() == '[') || (c == ')' && stk.top() == '('))){
            stk.pop();
        }
        else{
            stk.push(c);
        }
    }
    return stk.empty();
}
