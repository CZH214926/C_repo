#ifndef _GAME_H_
#define _GAME_H_

#include<stdio.h>
#include<windows.h>
#include<time.h>

#pragma warning(disable:4996)
//3*3������
#define ROW 3
#define COL 3

//��Һ͵��Ե�����
#define PLAYER_CHESS 'X'
#define COMPUTER_CHESS 'O'
#define PLAYING 'P'
#define DRAW 'D'


//����������
void Menu();
void Game();

#endif