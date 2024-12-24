/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface_Jeu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:35:04 by axelpeti          #+#    #+#             */
/*   Updated: 2024/12/23 16:30:50 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"
/* 
void	Game(char *the_word)
{
	int		nb_letter;
	char	interface_letter[] = 
	{RESET
		"  ____ "
		" |____|"
	};
	
	nb_letter = ft_strlen(the_word) - 1;
	top_lines();
	
} */

void	menu_game(int x)
{
	int	line;
	int	column;
	int	y;

	y = 10;
	line = 1;
	while (line <= y)
		{
			column = 1;
			while (column <= x)
			{
				if ((line == 1 && column == 1)
					|| (line == y && column == x && x != 1 && y != 1) 
					|| (line == y && column == 1) || (line == 1 && column == x))
					putchar(' ');
				else if (line == 1 || line == y)
					putchar('=');
				else if (column == 1 || column == x)
					putchar ('|');
				else
					putchar(' ');
				column++;
			}
			putchar('\n');
			line++;
		}
}