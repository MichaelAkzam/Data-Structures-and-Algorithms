/*
Intuition
    Problem given is straightforward. We are given the board dimensions and the food squares in sequential order.
    We will need to start by initializing those elements, and start our snake from the given square (0,0). This
    position will be updated at every move call. The move() method will make sure our board position is within 
    bounds (and not touching our own body), and if it captured a food square.
    The tricky part is keeping track of the growing body.
    The last move after having eaten the food square will be the body's continuation. So if food is at (1,1), 
    and we came from (1,0), then (1,0) would be our snake's tail now (given that it was at its original length
    of 1).
    This can be done with a visited grid that would keep track of our snake's positioning, adding and removing
    values at each move() call. We would need to keep track of the last k squares visited, where k represents
    the current length of our snake.
    On second note, visited would be hard to keep track of as a grid, as removing elements from it is
    challenging. We could keep it simple and use some sort of FILO data structure where the head would be the
    element seen k squares ago, and the tail would be the latest square just visited. We expand our list
    every time we land on a square with food on it.
    The issue is now we wouldnt have an O(1) check if element has been visited in the last k squares..
    The body of our snake would therefore take the shape of a linked list.

Approach


Complexity
- Time complexity:

- Space complexity:

*/

#include <string>
#include <vector>
#include <deque>
#include <unordered_map>

class SnakeGame {
private:
    // NOTE: Declaration order matters with respect to constructors! Need to follow same order for initialization too!
    int score = 0, length = 0;
    int ROWS = -1, COLS = -1, idx = 0;
    std::vector<std::pair<int, int>> foodLoc;
    std::pair<int, int> curLoc = {0,0};
    
    std::unordered_map<std::string, std::pair<int,int>> map = {
        {"U", {0, -1}}, 
        {"D", {0, 1}},
        {"L", {-1, 0}}, 
        {"R", {1, 0}}
    };
public:
    SnakeGame(int width, int height, std::vector<std::pair<int,int>> food) 
        : ROWS(width),
          COLS(height),
          foodLoc(std::move(food))
    {
    }

    int move(std::string direction) {
        int x = curLoc.first + map[direction].first;
        int y = curLoc.second + map[direction].second;
        // if move is not legal   
        if(x < 0 || x >= ROWS || y < 0 || y >= COLS)
            return -1;
        
        curLoc.first = x; curLoc.second = y;
        if(curLoc == foodLoc[idx]){
            idx++;
            score++;
            length++;
        }
        return score;
    }

};

/*
Input
["SnakeGame", "move", "move", "move", "move", "move", "move"]
[[3, 2, [[1, 2], [0, 1]]], ["R"], ["D"], ["R"], ["U"], ["L"], ["U"]]
Output
[null, 0, 0, 1, 1, 2, -1]

Explanation
SnakeGame snakeGame = new SnakeGame(3, 2, [[1, 2], [0, 1]]);
snakeGame.move("R"); // return 0
snakeGame.move("D"); // return 0
snakeGame.move("R"); // return 1, snake eats the first piece of food. The second piece of food appears at (0, 1).
snakeGame.move("U"); // return 1
snakeGame.move("L"); // return 2, snake eats the second food. No more food appears.
snakeGame.move("U"); // return -1, game over because snake collides with border

*/