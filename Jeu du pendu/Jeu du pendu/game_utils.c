/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:48:15 by axelpeti          #+#    #+#             */
/*   Updated: 2025/01/11 15:08:21 by axelpeti         ###   ########.fr       */
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
	nb_word = (rand() % (count_word(fd) + 1 - 1)) + 1;
	close (fd);
	fd = open("mots_pendu.txt", O_RDONLY);
	count = 0;
	while (count <= nb_word)
	{
		get_next_line(fd);
		count++;
	}
	word = ft_calloc(ft_strlen(get_next_line(fd)), sizeof(char));
	if (!word)
		return ("no word");
	word = get_next_line(fd);
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

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	check(char *hidde_word)
{
	int	i;

	i = 0;
	while(hidde_word[i])
	{
		if (hidde_word[i] == '*')
			return (1);
		i++;
	}
	return (0);
}

int	verif(char *word_to_find,  char c)
{
	int	i;

	i = 0;
	while (word_to_find[i])
	{
		if (word_to_find[i] == c)
			return (0);
		i++;
	}
	return (1);
}
char	*find_letter(char l, char *word_to_find, char *his_word)
{
	int	i;

	i = 0;
	while (word_to_find[i])
	{
		if (word_to_find[i] == l)
			his_word[i] = l;
		i++;
	}
	return (his_word);
}

char	*hidden_word(char *word_to_find)
{
	char	*hide_word;
	int		i;

	i = 0;
	hide_word = ft_calloc(ft_strlen(word_to_find), sizeof(char));
	while (i < ft_strlen(word_to_find) - 1)
	{
		hide_word[i] = '*';
		i++;
	}
	hide_word[i] = '\0';
	return (hide_word);
}