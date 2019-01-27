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
	for (int x = 0; x < LEN; x++)
	{
		int y = std::rand() % 10 + yOff;
		int sx = std::rand() % LEN - 300;

		if (std::rand() % 2)
		{
			mvaddch(y, sx, 'b');
			storx[x] = sx;
			story[x] = y;
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
	startx = (COLS - width) / 2;
	printw("Press F1 to exit, lines: %d, cols: %d\n", LINES, COLS);
	refresh();
	my_win = newwin(height, width, starty, startx);

	mvaddch(starty, startx, '^');

	//	nodelay(my_win, false);
	halfdelay(1);
	int i = 0;
	//	for (int x = COLS / 2; x < COLS * 3 / 4; x++)
	//	{
	//		mvvline(0, x, '^', LINES);
	//	}
	int storx[LEN];
	int	story[LEN];
	/*	for (int x = 0; x < LEN; x++)
		{
		int y = std::rand() % 10;
		int sx = std::rand() % LEN;

		if (std::rand() % 2)
		{
		mvaddch(y, sx, 'b');
		storx[x] = sx;
		story[x] = y;
		}
		}
		*/
	timeout(1);
	wtimeout(my_win, 1);
	seedMap(storx, story, 0);
	int storx1[LEN];
	int	story1[LEN];
	seedMap(storx1, story1, 50);
	
	while((ch = getch()) != KEY_F(1))
	{
		winRefresh(storx1, story1, 50);
		winRefresh(storx, story, 0);
		mvaddch(starty, startx, '^');
		move(starty, startx);
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
				if (moveOk(starty, startx + 1))
				{
					mvaddch(starty, startx, ' ');
					startx++;
				}
				break;
			case KEY_UP:
				if (moveOk(starty - 1, startx))
				{
					mvaddch(starty, startx, ' ');
					starty--;
				}
				break;
			case KEY_DOWN:
				if (moveOk(starty + 1, startx))
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
