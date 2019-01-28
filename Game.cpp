#include "Game.hpp"
#include "LivingObject.hpp"
#include <chrono> 
#include <ctime> 
#include <ncurses.h>
#include <iostream>

#define EMPTY     ' '
#define LEN       500


Game::Game(int _w, int _h) : w(_w), h(_h)
{
	map = new LivingObject**[h];
	for (int x = 0; x < h; x++)
	{
		map[x] = new LivingObject*[w]();
	}
}

Game::Game(Game &copyFrom): w(copyFrom.w), h(copyFrom.h)
{
	map = copyFrom.map;
}

Game::~Game()
{
	for (int x = 0; x < h; x++)
	{
		delete[] map[x];
	}
	delete[] map;

}

Game	&Game::operator=(Game &rhs) {
	w = rhs.w;
	h = rhs.h;
	map = rhs.map;
	return *this;
}

/*
 ** check is obj is in bounds
 ** delete it if necesary, remove from object list and map
 */
int		Game::checkBounds(LivingObject &obj)
{
	int x = obj.getX();
	int y = obj.getY();

	int nextPOS = obj.getVecX();

	if ((x < 0 || x >= w) || (y < 0 || y >= h) || (nextPOS >= w))
	{
		obj.setDead();
		return (0);
	}
	return (1);
}

int		Game::checkCollision(int x, int y)
{
	int vec_x = map[y][x]->getVecX();

	int i = x;
	while (i < x + vec_x)
	{
		if (map[y][x + i]->getFramecount() > 0)
		{
			map[y][x]->setDead();
			map[y][x + i]->setDead();
			return 0;
		}	 
		i++;
	}
	return 1;
}

int		Game::moveObject(int x, int y)
{
	//	if (w > x ||) 
	int vec_x = map[y][x]->getVecX();
	//	int vec_y  = map[y][x].getVecY();
	map[y][x + vec_x] = map[y][x];
	map[y][x]->setDead();

	mvaddch(y, vec_x + x, ' ');
	//integrate this framecount
	mvaddch(y, vec_x + x, map[y][vec_x + x]->getEntity());

	return 1;
}


/*
 ** Runs through map/array. Checks for border bounds, collision. Then moves
 */
void	Game::updateObjects(void)
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j  < w; j++)
		{
			if (map[i][j]->getFramecount() > 0 && map[i][j]->getFramecount() == frame_count)	//node in 2d map is 'alive' and other items can be assessed
			{
				if (checkBounds(*map[i][j]) && checkCollision(j, i))//if colision occurs, remove the lesser live item. If requal.. remove both
					moveObject(j, i);	//moves object and also updates in framecount
			}
		}
	}
}

// void	Game::dumpMap(void)
// {
// 	for (int y = 0; y < h; y++)
// 	{
// 		for (int x = 0; x < w; x++)
// 		{
// 			std::cout << map[y][x].getEntity();
// 		}
// 		std::cout << "\n";
// 	}
// }

// void	Game::testLitterMap(void)
// {
// 	int total = 0;
// 	for(int y = 0; y < h; y++)
// 	{
// 		for (int x = 0; x < w; x++)
// 		{
// 			if (total % 5 == 0)
// 				map[y][x].setEntity('E');
// 			else if (total % 7 == 0)
// 				map[y][x].setEntity('.');
// 			else
// 				map[y][x].setEntity(' ');
// 			total++;
// 		}
// 	}
// }

void	Game::setBullet(bool enemy, int xp, int yp, int xv, int yv)
{
	yv = 0;
	LivingObject *created = new LivingObject(enemy, BULLET, xp, yp, xv, 0, 1, frame_count);
	map[xp][yp] = created;
}

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



void	Game::run(void)
{
	WINDOW *my_win;

	LivingObject	*p = new LivingObject(false, '>', 20, LINES - 1, 0, 0, 1, frame_count);
	int bulletx = 0;
	int bullety = 0;

	int startx, starty, width, height;
	int ch;
	int i = 0;
	int storx[LEN];
	int	story[LEN];
	int storx1[LEN];
	int	story1[LEN];
	seedMap(storx1, story1, LINES - 10);
	seedMap(storx, story, 0);

	std::chrono::time_point<std::chrono::system_clock> start, end; 
	std::chrono::duration<double> elapsed_seconds;

	srand(std::time(nullptr));
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	refresh();
	timeout(20);
	winRefresh(storx1, story1, LINES -  10);
	winRefresh(storx, story, 0);


	height = 1;
	width = 1;
	starty = (LINES - height) / 2;
	startx = 20;//(COLS - width) / 2;
	my_win = newwin(height, width, starty, startx);

	while ((ch = getch()) != KEY_F(1))
	{
		/*		if (bullety)
				mvaddch(bullety, bulletx, ' ');
				if (bullety)
				{
				bulletx += 5;
				mvaddch(bullety, bulletx, '*');
				}
				*/

		updateObjects();
		winRefresh(storx1, story1, LINES -  10);
		winRefresh(storx, story, 0);
		move(starty, startx);
		mvaddch(starty, startx, '>');
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
			case 32:
				setBullet(false, startx + 1, starty, 5, 0);
				//		std::cout << "Hit space bar\n";
				mvaddch(bullety, bulletx, '*');
				break;
			default:
				break;
		}
		i++;
	}

	endwin();
	delete p;
	std::cout << "ran loop " + std::to_string(i) + " times\n";
}
