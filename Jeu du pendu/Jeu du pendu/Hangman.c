/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hangman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:35:04 by axelpeti          #+#    #+#             */
/*   Updated: 2025/01/13 13:58:34 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"
#include "menu_game.h"

void	jeu()
{
	char	*attempt;
	char	*hide_word;
	char	*words_to_find;
	int		fd;
	char	(*rendu)[1000];
	char	(*drawing)[27];
	int hanged;
	int p;
	hanged = 0;
	if (! rendu)
		return;
	fd = open("mots_pendu.txt", O_RDONLY);
	words_to_find = pick_word(fd); // cherche le futur mots a trouver pseudo aleatoirement
	attempt = ft_calloc(BUFFER_SIZE, sizeof(char)); // calloc de ce que l'utilisateur va ecrire
	rendu = ft_calloc(9, ft_strlen(words_to_find) * 12);
	drawing = ft_calloc(9, 28); // calloc de mon futur tableaux ascii
	words_to_find = pick_word(fd);
	hide_word = hidden_word(words_to_find);
	while (check(hide_word) || hanged <= 10)
	{
		p = 0;
		clear_screen();
		print_title();
		menu_letter(hide_word, rendu);
		while (p < 3)
		{
			center_text(test[p]);
			p++;
		}
		center_text(pendu[hanged]);
		printf("\n\nmots a trouver : %s\n", hide_word);
		move_cursor(141, 26);
		fgets(attempt, BUFFER_SIZE, stdin);
		if (ft_isalpha(attempt[0]) && attempt[1] == '\n')
		{
			if (verif(words_to_find, attempt[0]) == 0)
				hide_word = find_letter(attempt[0], words_to_find, hide_word);
			else
			{
				hanged++;
				printf("faux, recommence");
			}
		}
		else
			write (1, "entree incorect\n", 17);
	}
}


void menu_letter(char *hide_word, char (*rendu)[1000])
{
    int				i;
	int				l;
	int				c; 
	int				j;
	unsigned int	index;
	int				line;
	int				y;
    c = 0;
    i = 0;
	l = 0;
    j = 0;
	line = 9;
	index = 26;
	while (lettres_ascii[index][j] != '\0')
	{
		rendu[l][c] = lettres_ascii[index][j];
		c++;
        j++;
		if (lettres_ascii[index][j] == '\n')
            {
                j++;
                l++;
    			c = 0;
            }
	}
    while (hide_word[i])
    {
        l = 0;
        j = 0;
        if (hide_word[i] == '*')
            index = 28;
        else
            index = hide_word[i] - 'a';
		c = ((i + 1) * 12);
        while (lettres_ascii[index][j] != '\0')
        {
            rendu[l][c] = lettres_ascii[index][j];
            c++;
            j++;
            if (lettres_ascii[index][j] == '\n')
            {
                j++;
                l++;
    			c = ((i + 1) * 12);
            }
        }
        i++;
    }
	index = 27;
	l = 0;
    j = 0;
	while (lettres_ascii[index][j] != '\0')
    {
        rendu[l][c] = lettres_ascii[index][j];
        c++;
        j++;
        if (lettres_ascii[index][j] == '\n')
        {
			rendu[l][c] = '\0';
            j++;
            l++;
    		c = ((i + 1) * 12);
        }
    }
	i = 0;
    while (i <= line)
    {
        center_text(rendu[i]);
		i++;
	}
}

