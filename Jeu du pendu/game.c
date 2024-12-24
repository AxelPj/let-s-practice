/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:23:19 by axelpeti          #+#    #+#             */
/*   Updated: 2024/12/23 16:30:55 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"

int main(void)
{
	int		fd;
	char	*words_to_find;
	char	*user;

	user = ft_calloc(BUFFER_SIZE, sizeof(char));
	if(!user)
		return(-1);
	while (1)
	{
		clear_screen();
		print_title();
		user = menu();
		if (user[0] == '1' && user[1] == '\n')
		{
			clear_screen();
			fd = open("mots_pendu.txt", O_RDONLY);
			words_to_find = pick_word(fd);
			menu_game(ft_strlen(words_to_find) * 10);
			
		}
		if (user[0] == '2' && user[1] == '\n')
		{
			clear_screen();
			
		}
		if (user[0] == '3' && user[1] == '\n')
		{
			clear_screen();
			return (0);
		}
		
	}
}