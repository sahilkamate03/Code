#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <conio.h>
#include <windows.h>
#include <deque>

using namespace std;

const int ROWS = 20;
const int COLS = 20;

// Snake class
class Snake
{
public:
    int x;
    int y;
    char direction;

    Snake()
    {
        x = 0;
        y = 0;
        direction = 'N';
    }

    void move()
    {
        switch (direction)
        {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
        }

        if (x < 0) x = COLS - 1;
        if (x == COLS) x = 0;
        if (y < 0) y = ROWS - 1;
        if (y == ROWS) y = 0;
    }
};

// Food class
class Food
{
public:
    int x;
    int y;

    Food()
    {
        x = rand() % COLS;
        y = rand() % ROWS;
    }
};

int main()
{
    srand(time(0));

    // Use a queue to represent the snake's body
    queue<pair<int, int>> snake;
    snake.push(make_pair(0, 0));

    // Use a deque to represent the game board
    deque<deque<char>> board(ROWS, deque<char>(COLS, '.'));
    board[0][0] = 'S';

    Food food;
    board[food.y][food.x] = 'F';

    char direction = 'N';

    while (true)
    {
        // Clear the screen
        system("cls");

        // Print the board
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }

        // Get the user's input
        if (kbhit())
        {
            char ch = getch();
            switch (ch)
            {
                case 'w':
                    direction = 'N';
                    break;
                case 's':
                    direction = 'S';
                    break;
                case 'a':
                    direction = 'W';
                    break;
                case 'd':
                    direction = 'E';
                    break;
                case 'q':
                    return 0;
            }
        }

        // Move the snake
        int x = snake.front().first;
        int y = snake.front().second;
        snake.pop();

        switch (direction)
        {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
               
                x++;
                break;
            case 'W':
                x--;
                break;
        }

        if (x < 0) x = COLS - 1;
        if (x == COLS) x = 0;
        if (y < 0) y = ROWS - 1;
        if (y == ROWS) y = 0;

        snake.push(make_pair(x, y));
        board[y][x] = 'S';

        // Check if the snake ate the food
        if (x == food.x && y == food.y)
        {
            food = Food();
            board[food.y][food.x] = 'F';
        }
        else
        {
            int x = snake.front().first;
            int y = snake.front().second;
            board[y][x] = '.';
        }

        // Check if the snake ran into itself
        for (int i = 0; i < snake.size() - 1; i++)
        {
            if (snake.front() == snake[i])
            {
                cout << "Game over!" << endl;
                return 0;
            }
        }

        // Sleep for a short time before moving again
        Sleep(100);
    }

    return 0;
}
