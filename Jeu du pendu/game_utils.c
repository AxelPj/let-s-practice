/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:48:15 by axelpeti          #+#    #+#             */
/*   Updated: 2024/12/23 15:40:50 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"

int	count_word (int fd)
{
	int count_word;
	
	count_word = 0;
	while (get_next_line(fd) != NULL)
		count_word++;
	return (count_word);
}

char	*pick_word(int fd)
{
	int		count;
	int		nb_word;
	char	*word;

	srand(time(NULL));
	nb_word = (rand() % (count_word(fd) - 2 + 1)) + 1;
	close (fd);
	fd = open("mots_pendu.txt", O_RDONLY);
	count = 0;
	while (count < nb_word)
	{
		get_next_line(fd);
		count++;
		if (count == nb_word)
			word = get_next_line(fd);
	}
	close (fd);
	return (word);
}

void center_text(char *text) 
{
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);  // Obtenir la taille du terminal
    int term_width;  // Largeur du terminal
    int text_length; // Longueur du texte
    int spaces;  // Calculer le nombre d'espaces à ajouter avant le texte
	int	i;

	i = 0;
	term_width = ws.ws_col;
	text_length = ft_strlen(text);
	spaces = (term_width - text_length) / 2;
    while (i < spaces) 
	{
        putchar(' ');
		i++;
    }
    printf("%s\n", text);
}

void clear_screen() 
{
    printf("\033[2J");
    printf("\033[H");
}