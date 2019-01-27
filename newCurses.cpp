#include "newCurses.hpp"


NewCurses::NewCurses(void)
{
    my_win = initscr();
    cbreak();   /* Line buffering disabled, Pass on  * everty thing to me 		*/
   	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
    
}