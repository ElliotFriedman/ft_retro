/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkobb <tkobb@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 11:58:22 by tkobb             #+#    #+#             */
/*   Updated: 2019/01/26 12:02:38 by tkobb            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Game.hpp>
#include <curses.h>

int		main(void) {
	Game	game(COLS, LINES);
	WINDOW	*window;


	game.run(window);
}
