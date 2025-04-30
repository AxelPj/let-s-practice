/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:31:26 by axelpeti          #+#    #+#             */
/*   Updated: 2025/01/09 16:08:45 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"

int main(void)
{
	char	*user;

	while (1)
	{
		clear_screen();
		print_title();
		user = menu();
		if (user[0] == '1' && user[1] == '\n')
		{
			free(user);
			clear_screen();
			jeu();
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