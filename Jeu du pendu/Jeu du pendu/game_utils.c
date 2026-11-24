#include "pendu.h"

int	count_word (int fd)
{
	int		count_word;
	char	*line;

	count_word = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count_word++;
		free(line);
		line = get_next_line(fd);
	}
	return (count_word);
}

char	*pick_word(int fd)
{
	int		count;
	int		nb_word;
	char	*word;
	char	*line;

	srand(time(NULL));
	nb_word = count_word(fd);
	close (fd);
	if (nb_word == 0)
		return (NULL);
	nb_word = rand() % nb_word;
	fd = open("mots_pendu.txt", O_RDONLY);
	if (fd < 0)
		return (NULL);
	count = 0;
	word = NULL;
	line = get_next_line(fd); // on lit tout le fichier pour vider le stash de get_next_line
	while (line != NULL)
	{
		if (count == nb_word)
			word = line;
		else
			free(line);
		count++;
		line = get_next_line(fd);
	}
	close (fd);
	if (word && word[my_strlen(word) - 1] == '\n')
		word[my_strlen(word) - 1] = '\0';
	return (word);
}

void center_text(char *text)
{
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1)  // Obtenir la taille du terminal
		ws.ws_col = 0;
    int term_width;  // Largeur du terminal
    int text_length; // Longueur du texte
    int spaces;  // Calculer le nombre d'espaces à ajouter avant le texte
	int	i;

	i = 0;
	term_width = ws.ws_col;
	text_length = my_strlen(text);
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

int	my_isalpha(int c)
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
	hide_word = my_calloc(my_strlen(word_to_find) + 1, sizeof(char));
	if (!hide_word)
		return (NULL);
	while (i < my_strlen(word_to_find))
	{
		hide_word[i] = '*';
		i++;
	}
	hide_word[i] = '\0';
	return (hide_word);
}