#include "newCurses.hpp"
#include <ncurses.h>

//const int NewCurses::width = 50;
//const int NewCurses::height = 50;


NewCurses::NewCurses(void)
{
    my_win = initscr();

    this->window_height = 20;
    this->window_width = 20;
    this->width = 150;
    this->height = 50;
    this->start_width = 20;
    this->start_height = 20;
    cbreak();   /* Line buffering disabled, Pass on  * everty thing to me 		*/
   	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
    std::cout << "\e[8;" << this->height <<";" << this->width << "t";   //window resize
}

NewCurses::~NewCurses() {}

NewCurses::NewCurses(const NewCurses &source)
{
    *this = source;
}

NewCurses&NewCurses::operator=(const NewCurses &source)
{
    if (this != &source)
    {
        this->my_win = source.my_win;
    }
    return (*this);
}

WINDOW  *NewCurses::get_win(void)
{
    return (this->my_win);
}

int NewCurses::get_height(void)
{
    return (this->height);
}

int NewCurses::get_width(void)
{
    return (this->width);
}

void NewCurses::clear_window(void)
{
    refresh();
}

void NewCurses::put_text(std::string text)
{
    printw(text.c_str());
}

int NewCurses::command(void)
{
    this->ch = getch();
    return (this->ch);
}

int NewCurses::get_command(void)
{
    return (this->ch);
}

void NewCurses::destroy_win(void)
{
    /* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
    wborder(this->my_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    /* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
    wrefresh(this->my_win);
	delwin(this->my_win);
}

void NewCurses::create_window(void)
{
    //WINDOW *local_win;

	this->my_win = newwin(this->height, this->width, this->start_height, this->start_height);
	box(this->my_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(this->my_win);		/* Show that box 		*/
	//return local_win;
}

void NewCurses::end_window(void)
{
    endwin();
}


void NewCurses::start_up(void)
{
    this->start_height -= 1;
}


void NewCurses::start_down(void)
{
    this->start_height += 1;
}

void NewCurses::start_left(void)
{
    this->start_width += 1;
}

void NewCurses::start_right(void)
{
    this->start_width -= 1;
}
