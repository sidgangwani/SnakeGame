#include<iostream>
using namespace std;
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<mmsystem.h>
#include<process.h>
bool gameOver, Finish;
const int width = 70;
const int height = 20;
int x, y, fruitX, fruitY, score1,score2,m,n,k,i,j,s,r,prevX,prevY,prev2X,prev2Y,prevM,prevN,prev2M,prev2N,flag=0,counter=0;;
int tailX[100], tailY[100],tailM[100],tailN[100];
int z;
int lenTail2, lenTail1;
enum directon { STOP = 0, LEFT1, RIGHT1, UP1, DOWN1, LEFT2, RIGHT2, UP2, DOWN2, LEFT, RIGHT, UP, DOWN};
directon dir1,dir2,dir;
void Map1()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	m = width / 3;
	n = height / 3;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score1 = 0;
	score2 = 0;
}

void Snake()
{
	system("cls");
	for (i = 0; i < width+10; i++)
	cout << "#";
	cout << endl;
	for (i = 0;i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (j == 0)
			cout << "#sid";
			if (i == y && j == x)
			cout << "O";
			else if (i == fruitY && j == fruitX)
			cout << "$";
			else
			{
				bool print = false;
				for (k = 0; k < z; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
				cout << " ";
			}
			if (j == width - 1)
			cout << "#sid";
		}
		cout << endl;
	}
	for (i = 0; i < width+10; i++)
	cout << "#";
	cout << endl;
	cout << "Score1:" << score1 << endl;
	cout << "Made By Siddhant Gangwani";
	cout << endl;
	cout << "Use up,left,down,right or w,s,a,d to control the snake";
	cout<<endl;
}
	
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
			case 'a':
			dir = LEFT;
			break;
			case 'w':
			dir = UP;
			break;
			case 's':
			dir = DOWN;
			break;
			case 'd':
			dir = RIGHT;
			break;
			case 'x':
			gameOver = true;
			break;
			case 'p':
			system("pause");
			break;
		}
	}
	if(GetAsyncKeyState(VK_LEFT))
	{
		dir = LEFT;
	}
		if(GetAsyncKeyState(VK_RIGHT))
	{
		dir = RIGHT;
	}
		if(GetAsyncKeyState(VK_UP))
	{
		dir = UP;
	}
		if(GetAsyncKeyState(VK_DOWN))
	{
		dir = DOWN;
	}
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (i = 1; i < z; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
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
	for (i = 0; i < z; i++)
	if (tailX[i] == x && tailY[i] == y)
		gameOver = true;
	if (x == fruitX && y == fruitY)
	{
		score1 += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		z++;
	}
}
void Map()
{
	Finish = false;
	dir1 = STOP;
	x = width / 2;
	y = height / 2;
	m = width / 3;
	n = height / 3;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score1 = 0;
	score2 = 0;
}

void Tron()
{
	system("cls");
	for (i = 0; i < width+10; i++)
	cout << "#";
	cout << endl;
	for (i = 0;i < height; i++)
	{
	for (j = 0; j < width; j++)
	{
	if (j == 0)
	cout << "#sid";
	if (i == n && j == m)
	cout << "O";
	if (i == y && j == x)
	cout << "D";
	else if (i == fruitY && j == fruitX)
	cout << "$";
	else
	{
	bool print1 = false;
	for (k = 0, r = 0; k < lenTail1, r < lenTail2; k++, r++)
	{
	if (tailX[k] == j && tailY[k] == i)
	{
	cout << "D";
	print1 = true;
	}
	else if (tailM[r] == j && tailN[r] == i )
	{
	cout<< "O";
	print1 = true;
	}
	}
	if (!print1)
	cout << " ";
	}
	if (j == width - 1)
	cout << "#sid";
	}
	cout << endl;
	}
	for (i = 0; i < width+10; i++)
	cout << "#";
	cout << endl;
	cout << "Score1:" << score1 << endl;
	cout << "Score2:" << score2 << endl;
	cout << "Made By Siddhant Gangwani";
	cout << endl;
	cout << counter;
	cout<<endl;
}
void Keys()
{
	if(GetAsyncKeyState(VK_LEFT))
	{
		dir2 = LEFT2;
	}

	if(GetAsyncKeyState(VK_RIGHT))
	{
		dir2 = RIGHT2;
	}

	if(GetAsyncKeyState(VK_UP))
	{
		dir2 = UP2;
	}

	if(GetAsyncKeyState(VK_DOWN))
	{
		dir2 = DOWN2;
	}
	if (_kbhit())
	{
		switch (_getch())
		{
			case 'a':
				dir1 = LEFT1;
			break;
			case 'd':
				dir1 = RIGHT1;
			break;
			case 'w':
				dir1 = UP1;
			break;
			case 's':
				dir1 = DOWN1;
			break;
			case 'p':
				system("pause");
			break;
		}
	}
}
void Heart()
{
	prevX = tailX[0];
	prevY = tailY[0];
	prevM = tailM[0];
	prevN = tailN[0];
	tailX[0] = x;
	tailY[0] = y;
	tailM[0] = m;
	tailN[0] = n;
	for (i = 1; i < lenTail1; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	for(s = 1; s < lenTail2; s++)
	{
		prev2M = tailM[s];
		prev2N = tailN[s];
		tailM[s] = prevM;
		tailN[s] = prevN;
		prevM = prev2M;
		prevN = prev2N;
	}
	switch (dir1)
	{
		case LEFT1:
		x--;
		break;
		case RIGHT1:
		x++;
		break;
		case UP1:
		y--;
		break;
		case DOWN1:
		y++;
		break;
		default:
		break;
	}
	switch (dir2)
	{
		case LEFT2:
		m--;
		break;
		case RIGHT2:
		m++;
		break;
		case UP2:
		n--;
		break;
		case DOWN2:
		n++;
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
	
	if (m >= width)
		m = 0;
	else if (m < 0)
		m = width - 1;
	
	if (n >= height)
		n = 0;
	else if (n < 0)
		n = height - 1;
	
	for (i = 0; i < lenTail1; i++)
	{
		if (tailX[i] == x && tailY[i] == y || tailX[i] == m && tailY[i] == n || tailX[i] == tailM[i]  && tailY[i] == tailN[i])
			Finish = true;
	}
	for (i = 0; i < lenTail2; i++){
		if (tailM[i] == m && tailN[i] == n || tailM[i] == x && tailN[i] == y || tailM[i] == tailX[i] && tailN[i] == tailY[i])
			Finish = true;
	}
	if (x == fruitX && y == fruitY)
	{
		score2 += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		lenTail1++;
	}
	if (m == fruitX && n == fruitY)
	{
		score1 += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		lenTail2++;
	}
}

void Instructions()
{
	system("color A4");
	cout<<endl;
	cout<<"Welcome to the Tron Game"<<endl;
	cout<<endl;
	cout<<"Before starting with the game let us read some intructions about the game"<<endl;
	cout<<endl;
	cout<<"1) Use UP,LEFT,DOWN,RIGHT Arrow Keys to control the snake1";
	cout<<endl;
	cout <<"2) Use W,A,S,D to control the snake2"<<endl;
	cout<<"3) The motive of this game is to eat as many fruits as possible and";
	cout<<endl<<"increase your score each time you eat a fruit";
	cout<<endl;
	cout<<"4) If you eat your body or eat the other snake's body the game will get over ";
	cout<<endl<<"whoever has the highest score wins"<<endl;
	cout<<"All the Best"<<endl;
	cout<<endl;
	cout<<"LOADING............";
	PlaySound(TEXT("Start.wav"), NULL, SND_SYNC);
}

int main()
	{
	system("color C7");
	char q;
	cout<<endl;
	cout<<"Enter for Single Player S and for Double T"<<endl;
	cin>>q;
	if(q == 'S' || q == 's')
	{
		Map1();
		PlaySound(TEXT("MI.wav"), NULL, SND_FILENAME | SND_ASYNC);
		system("color B4");
		while (!gameOver)
		{
			Snake();
			Input();
			Logic();
			Sleep(20);
		}
	}
	else if(q == 'T' || q == 't')
	{
		system("cls");
		Instructions();
		PlaySound(TEXT("MI.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Map();
		system("color B4");
		while (!Finish)
		{
			Tron();
			Keys();
			Heart();
			Sleep(20);
			counter++;
		}
		if(Finish == true)
		{
			system("cls");
			system("color C7");
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
			cout<<"                                        GAME  OVER"<<endl;
			cout<<endl;
			if(score1 > score2)
			cout<<"                           Player 1 wins by "<<score1 - score2<<" and survived for "<<counter<<" s";
			else
			cout<<"                           Player 2 wins by "<<score2 - score1<<" and survived for "<<counter<<" s";
			PlaySound(TEXT("gameover.wav"), NULL, SND_SYNC);
		}
	}
	if(gameOver==true)
	{
		system("cls");
		system("color C7");
		cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                                        GAME  OVER"<<endl;
		cout<<"                                        SCORE: "<<score1;
		PlaySound(TEXT("gameover.wav"), NULL, SND_SYNC);
	}
	return 0;
}
