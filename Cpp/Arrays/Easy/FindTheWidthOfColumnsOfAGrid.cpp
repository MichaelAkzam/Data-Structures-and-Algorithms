/*
Intuition
    Basic once problem at hand is understood

Approach
    Loop over each element i of each sub vector, and compare with the
    rest. Keep track of largest length.
    return array of such.

Complexity
- Time complexity: O(N*K)

- Space complexity: O(M) 

where N is the size of the grid
where K is the num size
where M is the size of the result vector

*/

#include <vector>

std::vector<int> findColumnWidth(std::vector<std::vector<int>>& grid) {
    std::vector<int> res;
    for(int i = 0; i < grid[0].size(); i++){
        int maxCol = -1;
        for(int j = 0; j < grid.size(); j++){
            // All of this could just be done by converting int to string
            int num = grid[j][i];
            int length = 0, count =0;
            if(num <= 0)
                length++;
            num = abs(num);
            while(num > 0){
                num /= 10;
                length++;
            }
            maxCol = std::max(maxCol, length);
        }
        res.push_back(maxCol);
    }
    return res;
}