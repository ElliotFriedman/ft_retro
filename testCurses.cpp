#include <ncurses.h>
#include <iostream>

#define EMPTY     ' '

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

int main(int argc, char *argv[])
{
	WINDOW *my_win;
	int startx, starty, width, height;
	int ch;

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

	halfdelay(1);
	int i = 0;
	for (int x = COLS / 2; x < COLS * 3 / 4; x++)
	{
		mvvline(0, x, '^', LINES);
	}
	while((ch = getch()) != KEY_F(1))
	{
		for (int x = COLS / 2; x < COLS * 3 / 4; x++)
		{
			if (std::srand(std::time(nullptr)) % 2)
				mvvline(0, x, '^', LINES);
		}	
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

