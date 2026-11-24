#include "Plus_ou_moins_v2.h"

void	my_lvl1()
{
	char	*buf;
	int		nombre_trouve;
	int		nb_coup;
	int		nombre_mystere;
	int		bytes;

	nb_coup = 0;
	nombre_trouve = 0;
	srand(time(NULL));
	nombre_mystere = (rand() % (100 - 1 + 1)) + 1;
	buf = my_calloc(BUFFER_SIZE + 1, sizeof(char));
	write(1, "\033[0;32m\nBienvenue dans le niveau 1\nessaye de trouver le nombre mystere ! \nchoisie ton nombre : ", 95);
	while (nombre_trouve != nombre_mystere)
	{
		bytes = read(0, buf, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(buf);
			return ;
		}
		buf[bytes] = '\0';
		nombre_trouve = atoi(buf);
		while (nombre_trouve <= 0 || nombre_trouve > 100)
		{
			write(1, "\033[0;31mvotre entree est incorrect reessaye : ", 45);
			bytes = read(0, buf, BUFFER_SIZE);
			if (bytes <= 0)
			{
				free(buf);
				return ;
			}
			buf[bytes] = '\0';
			nombre_trouve = atoi(buf);
		}
		if (nombre_trouve < nombre_mystere)
			write(1, "\033[1;31mC'est Plus, réessaye : \n", 32);
		else if (nombre_trouve > nombre_mystere)
			write(1, "\033[1;31mC'est Moins, réessaye : \n", 33);
		nb_coup++;
	}
	free (buf);
	printf("\033[0;32m\nbravo tu a trouver le nombre mystere en %i coup\n", nb_coup);
}

void	my_lvl2()
{
	char	*buf;
	int		nombre_trouve;
	int		nb_coup;
	int		nombre_mystere;
	int		bytes;

	nb_coup = 0;
	nombre_trouve = 0;
	srand(time(NULL));
	nombre_mystere = (rand() % (1000 - 1 + 1)) + 1;
	buf = my_calloc(BUFFER_SIZE + 1, sizeof(char));
	write(1, "\033[0;32m\nBienvenue dans le niveau 2\nessaye de trouver le nombre mystere ! \nchoisie ton nombre : ", 95);
	while (nombre_trouve != nombre_mystere)
	{
		bytes = read(0, buf, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(buf);
			return ;
		}
		buf[bytes] = '\0';
		nombre_trouve = atoi(buf);
		while (nombre_trouve <= 0 || nombre_trouve > 1000)
		{
			write(1, "\033[0;31mvotre entree est incorrect reessaye : ", 45);
			bytes = read(0, buf, BUFFER_SIZE);
			if (bytes <= 0)
			{
				free(buf);
				return ;
			}
			buf[bytes] = '\0';
			nombre_trouve = atoi(buf);
		}
		if (nombre_trouve < nombre_mystere)
			write(1, "\033[1;31mC'est Plus, réessaye : \n", 32);
		else if (nombre_trouve > nombre_mystere)
			write(1, "\033[1;31mC'est Moins, réessaye : \n", 33);
		nb_coup++;
	}
	free (buf);
	printf("\033[0;32m\nbravo tu a trouver le nombre mystere en %i coup\n", nb_coup);
}

void	my_lvl3()
{
	char	*buf;
	int		nombre_trouve;
	int		nb_coup;
	int		nombre_mystere;
	int		bytes;

	nb_coup = 0;
	nombre_trouve = 0;
	srand(time(NULL));
	nombre_mystere = (rand() % (10000 - 1 + 1)) + 1;
	buf = my_calloc(BUFFER_SIZE + 1, sizeof(char));
	write(1, "\033[0;32m\nBienvenue dans le niveau 3\nessaye de trouver le nombre mystere ! \nchoisie ton nombre : ", 95);
	while (nombre_trouve != nombre_mystere)
	{
		bytes = read(0, buf, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(buf);
			return ;
		}
		buf[bytes] = '\0';
		nombre_trouve = atoi(buf);
		while (nombre_trouve <= 0 || nombre_trouve > 10000)
		{
			write(1, "\033[0;31mvotre entree est incorrect reessaye : ", 45);
			bytes = read(0, buf, BUFFER_SIZE);
			if (bytes <= 0)
			{
				free(buf);
				return ;
			}
			buf[bytes] = '\0';
			nombre_trouve = atoi(buf);
		}
		if (nombre_trouve < nombre_mystere)
			write(1, "\033[1;31mC'est Plus, réessaye : \n", 32);
		else if (nombre_trouve > nombre_mystere)
			write(1, "\033[1;31mC'est Moins, réessaye : \n", 33);
		nb_coup++;
	}
	free (buf);
	printf("\033[0;32m\nbravo tu a trouver le nombre mystere en %i coup\n", nb_coup);
}