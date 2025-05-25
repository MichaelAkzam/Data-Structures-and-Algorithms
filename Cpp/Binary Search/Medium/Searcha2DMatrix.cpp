/*
Intuition
    Searching through a 2D matrix seems to be the same as searching through a differently formatted 1D matrix.
    The first thing that comes to mind is once we find which row are target should be a part of, we can then
    clearly use binary search to filter it out. And to also match with the correct row, we would need to use binary
    search as we need our solution to be of O(log(m*n)), which just translates to O(log(m) + log(n)).
    The tricky part here is actually knowing how to move your indexes through the 2D matrix, as we cannot just have
    a mid index that is (row + cols) / 2.

Approach
    The first approach tries to check in the first binary search loop if the target that might fall within the row
    specified is actually part of it (being bounded by the middle element and either the first or last element).
    If this is the case, then we set our foundRow bool to true and move on to the next binary search.
    The second approach (which has less checks within the first binary search), does something similar, but just finds
    the appropriate range for the target between the starting and ending element of the specific row.
    Once the row was found in both approaches, we go and perform regular binary search on an array to find if
    the target is in the row.

Complexity
- Time complexity: O(log(m*n)), where m is the number of rows, and n the elements within that row.

- Space complexity: O(1)

*/
#include <vector>
// OPTIMAL SOLUTION
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int first = 0, last = matrix.size()-1;
    bool foundRow = false;
    int row = -1;

    while(first <= last){
        int mid = (first + last) / 2;
        if(matrix[mid][matrix[0].size()/2] == target)
            return true;
        if(matrix[mid][matrix[0].size()/2] < target){
            if(matrix[mid].back() >= target){
                foundRow = true;
                row = mid;
                break;
            }
            else{
                first = mid + 1;
            }
        }
        else if (matrix[mid][matrix[0].size()/2] > target){
            if(matrix[mid][0] <= target){
                foundRow = true;
                row = mid;
                break;
            }
            else{
                last = mid - 1;
            }
        }
    }
    if(!foundRow)
        return false;

    int l = 0, r = matrix[row].size()-1;
    while(l <= r){
        int mid = (l + r) / 2;
        if (matrix[row][mid] == target)
            return true;
        if(matrix[row][mid] < target)
            l = mid + 1;
        else if (matrix[row][mid] > target)
            r = mid - 1;
    }

    return false;
}

// 2nd OPTIMAL SOLUTION
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int top = 0, bot = matrix.size()-1;
    int row = -1;

    while(top <= bot){
        row = (top + bot) / 2;
        if(target < matrix[row][0])
            bot = row - 1;
        else if(target > matrix[row][matrix[0].size()-1])
            top = row + 1;
        else
            break;
    }

    if(!(top <= bot))
        return false;

    int l = 0, r = matrix[row].size()-1;

    while(l <= r){
        int mid = (l + r) / 2;
        if(target == matrix[row][mid])
            return true;
        if(target < matrix[row][mid])
            r = mid - 1;
        else if (target > matrix[row][mid])
            l = mid + 1;
    }
    return false;
}