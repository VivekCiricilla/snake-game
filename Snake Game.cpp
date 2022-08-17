// Snake Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<conio.h>
#include<ctime>

using namespace std;
const int width = 30;
const int height = 20;
int x, y;
int fruitx, fruity;
bool gameover;
int score;
int tailx[100], taily[100];
int tail_length;
enum class dir
{
	stop, left, right, up, down
};
dir direction;
void setup()
{
	gameover = false;
	direction = dir::stop;
	x = width / 2;
	y = height / 2;
	fruitx = rand() % width;
	fruity = rand() % height;
	score = 0;
}
void draw()
{
	system("cls");
	for (int i = 0; i <= width+1; i++)
		cout << "$";
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			if (j == 0)
				cout << "$";
			if (j == width)
				cout << "$";
			if (i == y && j == x)
			{
				cout << "O";
			}
			else if (i == fruity && j == fruitx)
				cout << "*";
			else
			{
				bool b = false;
				for (int k = 0; k < tail_length; k++)
				{
					if (tailx[k] == j && taily[k] == i)
					{
						cout << "0";
						b = true;
					}
				}
				if(!b)
					cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i <= width+1; i++)
		cout << "$";
	cout << endl;
	cout << "Score : " << score;
}
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			direction = dir::left;
			break;
		case 'd':
			direction = dir::right;
			break;
		case 'w':
			direction = dir::up;
			break;
		case 's':
			direction = dir::down;
			break;
		case 'x':
			gameover = true;
			break;
		}
	}
}
void logic()
{
	int prev1 = tailx[0];
	int prev2 = taily[0];
	tailx[0] = x;
	taily[0] = y;
	int prev_1, prev_2;
	for (int k = 1; k < tail_length; k++)
	{
		prev_1 = tailx[k];
		prev_2 = taily[k];
		tailx[k] = prev1;
		taily[k] = prev2;
		prev1 = prev_1;
		prev2 = prev_2;

	}
	switch (direction)
	{
	case dir::left:
		x--;
		break;
	case dir::right:
		x++;
		break;
	case dir::up:
		y--;
		break;
	case dir::down:
		y++;
		break;
	default:
		break;
	}

	if (x > width-1 || x < 0 || y>height-1 || y < 0)
	{
		gameover = true;
	}
	if (x == fruitx && y == fruity)
	{
		score++;
		fruitx = rand() % width;
		fruity = rand() % height;
		tail_length++;
	}
}
int main()
{
	srand(time(NULL));
	setup();
	while (!gameover)
	{
		draw();
		input();
		logic();
	}
	draw();
}