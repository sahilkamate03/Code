#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>

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

    Snake snake;
    Food food;

    while (true)
    {
        // Clear the screen
        system("cls");

        // Print the board
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (i == snake.y && j == snake.x)
                {
                    cout << "S";
                }
                else if (i == food.y && j == food.x)
                {
                    cout << "F";
                }
                else
                {
                    cout << ".";
                }
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
                    snake.direction = 'N';
                    break;
                case 's':
                    snake.direction = 'S';
                    break;
                case 'a':
                    snake.direction = 'W';
                    break;
                case 'd':
                    snake.direction = 'E';
                    break;
                case 'q':
                    return 0;
            }
        }

        // Move the snake
        snake.move();

        // Check if the snake has eaten the food
        if (snake.x == food.x && snake.y == food.y)
        {
            food = Food();
        }

        // Wait for 100 ms
        Sleep(100);
    }

    return 0;
}
