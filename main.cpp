/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:41:34 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 23:38:25 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <Game.hpp>
#include <curses.h>
#include <iostream>

int		main(void) {
	Game	game(COLS, LINES);
	WINDOW	*window = NULL;



	game.run(window);
	game.put_text("Press F1 to exit");

}
