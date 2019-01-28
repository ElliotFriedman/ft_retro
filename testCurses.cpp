/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testCurses.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 17:19:10 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/27 17:25:09 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <chrono> 
#include <ctime> 

#include <ncurses.h>
#include <iostream>

#define EMPTY     ' '
#define LEN       400

WINDOW *create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);
	wrefresh(local_win);	
	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}

int moveOk(int y, int x)
{
	int testChar;

	testChar = mvinch(y, x);
	return (testChar == EMPTY);
}

void	seedMap(int storx[LEN], int story[LEN], int yOff)
{
	for (int x = 0; x < LEN * 2; x++)
	{
		int y = std::rand() % 10 + yOff;
		int sx = std::rand() % LEN - 300;

		if (std::rand() % 2)
		{
			mvaddch(y, sx, 'b');
			storx[x % LEN] = sx;
			story[x % LEN] = y;
		}
	}
}

void	winRefresh(int storx[LEN], int story[LEN], int yOff)
{
	for (int x = 0; x < LEN; x++)
	{
		mvaddch(story[x], storx[x], ' ');
		storx[x] += 1;
		mvaddch(story[x], storx[x], 'b');
		if (storx[x] == COLS && x + 5 >= LEN)
			seedMap(storx, story, yOff);
	}
}

int main(int argc, char *argv[])
{
	WINDOW *my_win;
	int startx, starty, width, height;
	int ch;

	srand(std::time(nullptr));
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();

	height = 1;
	width = 1;
	starty = (LINES - height) / 2;
	startx = 30;//(COLS - width) / 2;
	refresh();
	my_win = newwin(height, width, starty, startx);

	int i = 0;
	int storx[LEN];
	int	story[LEN];
	seedMap(storx, story, 0);
	int storx1[LEN];
	int	story1[LEN];
	seedMap(storx1, story1, LINES - 10);

	timeout(20);
	std::chrono::time_point<std::chrono::system_clock> start, end; 

	start = std::chrono::system_clock::now(); 
	end = std::chrono::system_clock::now(); 

	std::chrono::duration<double> elapsed_seconds;


	while ((ch = getch()) != KEY_F(1))
	{
		winRefresh(storx1, story1, LINES -  10);
		winRefresh(storx, story, 0);
		mvaddch(starty, startx, '^');
		move(starty, startx);
		end = std::chrono::system_clock::now();
		start = std::chrono::system_clock::now();
		elapsed_seconds = end - start;
		//this tells us how long till we refresh frames
		while (elapsed_seconds.count() < 0.03f)
		{
			elapsed_seconds = end - start;
			end = std::chrono::system_clock::now();
		}

		switch(ch)
		{
			case KEY_LEFT:
				if (moveOk(starty, startx - 1))
				{
					mvaddch(starty, startx, ' ');
					startx--;
				}
				break;
			case KEY_RIGHT:
				if (startx < 20 &&  moveOk(starty, startx + 1))
				{
					mvaddch(starty, startx, ' ');
					startx++;
				}
				break;
			case KEY_UP:
				if (moveOk(starty - 11, startx))
				{
					mvaddch(starty, startx, ' ');
					starty--;
				}
				break;
			case KEY_DOWN:
				if (moveOk(starty + 11, startx))
				{
					mvaddch(starty, startx, ' ');
					starty++;
				}
				break;	
			default:
				break;
		}
		i++;
	}

	endwin();
	std::cout << "ran loop " + std::to_string(i) + " times\n";
	return 0;
}
