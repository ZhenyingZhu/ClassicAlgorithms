/*
 * [Source] https://leetcode.com/problems/design-snake-game/
 * [Difficulty]: Medium
 * [Tag]: Design
 * [Tag]: Queue
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// [Solution]: First move away the tail, then check head validation.
// [Corner Case]:
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        foods = food;
        foodIt = foods.begin();
        foodEnd = foods.end();
        board.resize(height, vector<bool>(width, false));
        board[0][0] = true;
        snake.push({0, 0});
        score = 0;
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pair<int, int> &head = snake.back();
        int x = head.first, y = head.second;
        if (direction == "U") {
            --x;
        } else if (direction == "L") {
            --y;
        } else if (direction == "R") {
            ++y;
        } else { // direction == "D"
            ++x;
        }

cout << direction << endl;
for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[0].size(); ++j) {
        if (i == foodIt->first && j == foodIt->second)
            cout << "F";
        else if (board[i][j])
            cout << "S";
        else
            cout << "X";
    }
    cout << endl;
}
cout << endl;

        if (foodIt != foodEnd && foodIt->first == x && foodIt->second == y) {
            ++foodIt;
            ++score;
        } else {
            pair<int, int> &tail = snake.front();
            board[tail.first][tail.second] = false;
            snake.pop();
        }

        // Check validation here so that the tail move first
        if (x < 0 || x >= (int)board.size() || y < 0 || y >= (int)board[0].size() || board[x][y])
            return -1;

        board[x][y] = true;
        snake.push({x, y});
        return score;
    }

    vector<pair<int, int>> foods;
    vector<pair<int, int>>::iterator foodIt;
    vector<pair<int, int>>::iterator foodEnd;
    vector<vector<bool>> board;
    queue<pair<int, int>> snake;
    int score;
};

class Solution {
public:
    void test() {
        SnakeGame snake(3, 3, {{2,0},{0,0},{0,2},{2,2}});
        cout << snake.move("D") << endl;
        cout << snake.move("D") << endl;
        cout << snake.move("R") << endl;
        cout << snake.move("U") << endl;
        cout << snake.move("U") << endl;
        cout << snake.move("L") << endl;
        cout << snake.move("D") << endl;
        cout << snake.move("R") << endl;
        cout << snake.move("R") << endl;
        cout << snake.move("U") << endl;
        cout << snake.move("L") << endl;
        cout << snake.move("D") << endl;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    sol.test();

    return 0;
}
