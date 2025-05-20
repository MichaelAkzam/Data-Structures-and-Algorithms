/*
Intuition
    As you can only sell on either the same day or days to come, it made sense to traverse the array using
    a 2 pointer approach to calculate the profit generated on each pair of days. My first thought was to have
    a left and right pointer that pointed to the start and end of given array respectively, but found it to make 
    more sense when they both started at days 0 and 1 (if the array covered more than 1 day).
    From there, we could basically calculate the profit and set our max profit variable, and keep moving through
    the array as long as our left pointer pointed to the smallest possible integer (for maximum profits). We only 
    switched that left pointer if our right pointer pointed to a smaller element. We keep going until we get to
    the last element.


Approach
    We create a left and right pointer that each point to indexes 0 and 1 respectively. We traverse the array and
    calculate the profit if the left pointer value is smaller than the right pointer value, and keep on moving the right
    pointer. We only move our left pointer once we find a smaller element to calculate our profit.
    We do this until our right pointer hits the end of the array and return the max profit found.


Complexity
- Time complexity: O(N) as we traverse the array once

- Space complexity: O(1)

*/
#include <vector>

int maxProfit(std::vector<int>& prices) {
    int left = 0, right = 1;
    int profit = 0, maxProfit = 0;

    while(right < prices.size()){
        if(prices[left] > prices[right]){
            left = right;
            right++;
        }
        else{
            profit = prices[right] - prices[left];
            maxProfit = std::max(profit, maxProfit);
            
            right++;
        }
    }
    return maxProfit;
}