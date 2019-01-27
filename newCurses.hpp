#ifndef NEWCURSES_HPP
# define NEWCURSES_HPP

# include <ncurses.h>
# include <signal.h>
//# include "Game.hpp"
# include <string>
# include <iostream>

class NewCurses
{
    private:
        WINDOW *my_win;
        int width;
        int height;
        int ch;

        int window_width;
        int window_height;
        int start_width;
        int start_height;
    public:
        NewCurses(void);
        ~NewCurses();
        NewCurses(const NewCurses &source);
        NewCurses&operator=(const NewCurses &source);
        WINDOW *get_win(void);
        int get_width(void);
        int get_height(void);
        void clear_window(void);
        //to put text on window:: mvprintw(), mvwprintw(), printw(), vwprintw(), wprintw()
        void put_text(std::string text);
        int command(void);
        int get_command(void);
        void destroy_win(void);      //from original test code
        void create_window(void);   //from original test code
        void end_window(void);
        void start_up(void);
        void start_down(void);
        void start_left(void);
        void start_right(void);
};

#endif