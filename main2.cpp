/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:18:30 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/26 23:36:38 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <chrono>
#include <iostream>


void	printmap(char board[10][10])
{
	int i = 0;
	while (i < 10)
	{
		int j = 0;
		while (j < 10)
		{
			std::cout << board[i][j];
			std::cout << " ";
			j++;
		}
		std::cout << "\n";
		i++;
	}
}
void	placemap(char board[10][10], LivingObject& a)
{
	board[a.getY()][a.getX()] = a.getEntity();
}


void	placemap(char board[10][10], EnemyObject& a)
{
	board[a.getY()][a.getX()] = a.getEntity();
}

void	placemap(char board[10][10], BulletObject& a)
{
	board[a.getY()][a.getX()] = a.getEntity();
}


void	clearmap(char board[10][10])
{
	int i = 0;
	while (i < 10)
	{
		int j = 0;
		while (j < 10)
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
}

int main()
{
	char	board[10][10];

	
//	std::cout << std::to_string(fps24);
	std::cout << "\n\n";

	
	BulletObject a(false, 'E', 5, 5, 1, 0);
	
	   std::cout << "X: " + std::to_string(a.getX()) + "\n";
	   std::cout << "Y: " + std::to_string(a.getY()) + "\n";
	   std::cout << "\n\n";
	   a.update();
	   clearmap(board);
	   placemap(board, a);
	   printmap(board);
	/*

	   std::cout << "X: " + std::to_string(a.getX()) + "\n";
	   std::cout << "Y: " + std::to_string(a.getY()) + "\n";
	   std::cout << "\n\n";
	   a.update();
	   clearmap(board);
	   placemap(board, a);
	   printmap(board);

	   std::cout << "X: " + std::to_string(a.getX()) + "\n";
	   std::cout << "Y: " + std::to_string(a.getY()) + "\n";
	   std::cout << "\n\n";
	   a.update();
	   clearmap(board);
	   placemap(board, a);
	   printmap(board);



	   std::cout << "X: " + std::to_string(a.getX()) + "\n";
	   std::cout << "Y: " + std::to_string(a.getY()) + "\n";
	   std::cout << "\n\n";
	   a.update();
	   clearmap(board);
	   placemap(board, a);
	   printmap(board);

	BulletObject b(false, 'B', 0, 0, 5, 0);

	int i = 0;

	while (i < 10)
	{
		b.update();
		a.update();
		clearmap(board);
		placemap(board, a);
		placemap(board, b);
		printmap(board);
		std::cout << "\n\n";
		i++;
	}

	std::cout << "\n\n";
	   EnemyObject c(false, 'E', 5, 5, 1, 0);

	   std::cout << "\n\n";
	   GameObject d(false, 'G', 5, 5, 1, 0);
	   std::cout << "\n\n";
	   */
}
