#ifndef _GAME_H_
#define _GAME_H_

#include<stdio.h>
#include<windows.h>
#include<time.h>

#pragma warning(disable:4996)
//3*3的棋盘
#define ROW 3
#define COL 3

//玩家和电脑的棋子
#define PLAYER_CHESS 'X'
#define COMPUTER_CHESS 'O'
#define PLAYING 'P'
#define DRAW 'D'


//函数的声明
void Menu();
void Game();

#endif