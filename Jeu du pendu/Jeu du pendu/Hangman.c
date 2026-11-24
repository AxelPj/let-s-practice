#include "pendu.h"
#include "menu_game.h"

void	jeu()
{
	char	*attempt;
	char	*hide_word;
	char	*words_to_find;
	int		fd;
	char	(*rendu)[1000];
	int		hanged;
	int		p;

	hanged = 0;
	fd = open("mots_pendu.txt", O_RDONLY);
	words_to_find = pick_word(fd); // cherche le futur mots a trouver pseudo aleatoirement
	if (!words_to_find)
		return ;
	attempt = my_calloc(BUFFER_SIZE, sizeof(char)); // calloc de ce que l'utilisateur va ecrire
	rendu = my_calloc(10, sizeof(*rendu)); // 10 lignes de 1000 caracteres pour le mot en ascii
	hide_word = hidden_word(words_to_find);
	if (!attempt || !rendu || !hide_word)
	{
		free(attempt);
		free(rendu);
		free(hide_word);
		free(words_to_find);
		return ;
	}
	while (check(hide_word) && hanged < NUM_ERROR - 1)
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
		if (fgets(attempt, BUFFER_SIZE, stdin) == NULL)
			break ;
		if (my_isalpha(attempt[0]) && attempt[1] == '\n')
		{
			if (attempt[0] >= 'A' && attempt[0] <= 'Z')
				attempt[0] = attempt[0] + 32;
			if (verif(words_to_find, attempt[0]) == 0)
				hide_word = find_letter(attempt[0], words_to_find, hide_word);
			else
			{
				hanged++;
				printf("faux, recommence");
			}
		}
		else
			write (1, "entree incorect\n", 16);
	}
	clear_screen();
	print_title();
	menu_letter(hide_word, rendu);
	center_text(pendu[hanged]);
	if (check(hide_word) == 0)
		printf("\n\nbravo, tu as trouve le mot : %s\n", words_to_find);
	else
		printf("\n\nperdu, le mot etait : %s\n", words_to_find);
	printf("appuie sur entree pour revenir au menu ");
	fgets(attempt, BUFFER_SIZE, stdin);
	free(attempt);
	free(rendu);
	free(hide_word);
	free(words_to_find);
}


void menu_letter(char *hide_word, char (*rendu)[1000])
{
    int				i;
	int				l;
	int				c; 
	int				j;
	unsigned int	index;
	int				line;
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

