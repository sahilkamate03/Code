#include <conio.h>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

bool gameover;

const int width = 20;
const int height = 10;

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];  // snake coordinates
int nTail;

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };  // Controls
eDirecton dir;

int Menu()
{
  system("cls");
  cout << "\n\n\t\t<<=========================>>";
  cout << "\n\t\t\t>>SNAKE GAME<<";
  cout << "\n\t\t<<=========================>>";
  cout << "\n\n\t\t1.Easy\n\t\t2.Medium\n\t\t3.Hard"<< endl;

  cout<< "\n\t\tEnter the choice: ";
  int choice; cin >>choice;

  int speed =0;
  switch (choice) {
  case 1:
    speed = 500;
    break;
  case 2:
    speed =250;
    break;
  case 3:
    speed =100;
    break;
  default:
    cout << "\n\t\tInvalid Input!!";
    return -1;
    break;
  }
  return speed;
}


bool restartMenu()
{
  system("cls");

  cout << "\n\t>>Game Over<<\n";
  cout << "\nEnter Y to play or q to quit: ";
  char c; cin >> c;
  bool gameover =true;
  if ((int) c==89 || (int) c==121)
  {    
    system("cls");
    gameover =false;
    Menu();
  }
  return true;
}

int Setup() {
  gameover = false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruitX = rand() % width;  // display fruit in a random place
  fruitY = rand() % height;
  score = 0;
  return Menu();
}

void Draw(int speed) {
  Sleep(speed);
  system("cls");

  for (int i = 0; i < width + 2; i++)

    cout << "#";

  cout << endl;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (j == 0)
        cout << "#";  // walls

      if (i == y && j == x)
        cout << "S";  // snake tale

      else if (i == fruitY && j == fruitX)
        cout << "F";  // change it to change the fruit

      else {
        bool print = false;
        for (int k = 0; k < nTail; k++) {
          if (tailX[k] == j && tailY[k] == i) {
            cout << "S";
            print = true;
          }
        }
        if (!print)
          cout << " ";
      }

      if (j == width - 1)
        cout << "#";
    }
    cout << endl;
  }

  for (int i = 0; i < width + 2; i++)

    cout << "#";

  cout << endl;

  cout << "Score:" << score << endl;
}

void Input() {
  if (_kbhit()) {
    switch (_getch()) {
      case 'a':
        dir = LEFT;
        break;

      case 'd':
        dir = RIGHT;
        break;

      case 'w':
        dir = UP;
        break;

      case 's':
        dir = DOWN;
        break;

      case 'x':
        gameover = true;
        gameover =restartMenu();
        break;
    }
  }
}

void algorithm() {
  int prevX = tailX[0];
  int prevY = tailY[0];
  int prev2X, prev2Y;

  tailX[0] = x;
  tailY[0] = y;

  for (int i = 1; i < nTail; i++) {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }

  switch (dir) {
    case LEFT:
      x--;
      break;

    case RIGHT:
      x++;
      break;

    case UP:
      y--;
      break;

    case DOWN:
      y++;
      break;

    default:
      break;
  }

  if (x >= width)
    x = 0;
  else if (x < 0)
    x = width - 1;

  if (y >= height)
    y = 0;
  else if (y < 0)
    y = height - 1;

  for (int i = 0; i < nTail; i++)

    if (tailX[i] == x && tailY[i] == y){
      gameover = true;
      gameover =restartMenu();
    }


  if (x == fruitX && y == fruitY) {
    score += 10;

    fruitX = rand() % width;

    fruitY = rand() % height;

    nTail++;
  }
}


int main() {
  int speed =Setup();
  while (!gameover) {
    Draw(speed);
    Input();
    algorithm();
  }

  return 0;
}