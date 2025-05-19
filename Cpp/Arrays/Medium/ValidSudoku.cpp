/*
Intuition


Approach


Complexity
- Time complexity:

- Space complexity:

*/

#include <unordered_set>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
    const int n = board[0].size();
    std::vector<std::unordered_set<char>> rows(n), cols(n);
    std::vector<std::vector<std::unordered_set<char>>> boxes(3, std::vector<std::unordered_set<char>>(3));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == '.')
                continue;

            if(rows[i].count(board[i][j]) || 
                cols[j].count(board[i][j]) || 
                boxes[i/3][j/3].count(board[i][j]))
                return false;

            rows[i].insert(board[i][j]);
            cols[j].insert(board[i][j]);
            boxes[i/3][j/3].insert(board[i][j]);
        }
    }
    return true;
}