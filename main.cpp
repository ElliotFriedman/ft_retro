/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:41:34 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/27 10:42:27 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <Game.hpp>
#include <curses.h>

int		main(void)
{
	Game	game(COLS, LINES);
	WINDOW	*window = NULL;

	game.run(window);
}
