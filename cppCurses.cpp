#include "newCurses.hpp"
#include <ncurses.h>

int main()
{
    NewCurses game_curses;

    game_curses.put_text("Press F1 to exit");
    game_curses.create_window();
    while (game_curses.command())
    {
        game_curses.get_command();
        
        if (game_curses.get_command() == KEY_F(1))
            break;
        else if (game_curses.get_command() == KEY_LEFT)
            game_curses.start_left();
		else if (game_curses.get_command() == KEY_RIGHT)
            game_curses.start_right();
	    else if (game_curses.get_command() == KEY_UP)
            game_curses.start_up();
	    else if (game_curses.get_command() == KEY_DOWN)
			game_curses.start_down();
        game_curses.destroy_win();
        game_curses.create_window();

    }
    game_curses.end_window();
    return 0;
}