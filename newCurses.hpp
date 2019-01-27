#ifndef NEWCURSES_HPP
# define NEWCURSES_HPP

# include <ncurses.h>
# include <signal.h>
# include "Game.hpp"

class NewCurses
{
    private:
        WINDOW *my_win;
        int x;
        int y;
    public:
        NewCurses(void);
        ~NewCurses();
        NewCurses(const NewCurses &source);
        NewCurses&operator=(const NewCurses &source);
};

#endif