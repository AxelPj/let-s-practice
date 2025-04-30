/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plus_ou_moins_lvl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:51:30 by axelpeti          #+#    #+#             */
/*   Updated: 2024/12/19 17:07:09 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Plus_ou_moins_v2.h"

void	ft_lvl1()
{
	char 	*buf;
	int		nombre_trouve;
	int		nb_coup;
	int		nombre_mystere;

	nb_coup = 0;
	nombre_trouve = 0;
	srand(time(NULL));
	nombre_mystere = (rand() % (100 - 1 + 1)) + 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	write(1, "\033[0;32m\nBienvenue dans le niveau 1\nessaye de trouver le nombre mystere ! \nchoisie ton nombre : ", 96);
	while (nombre_trouve != nombre_mystere)
	{
		read(0, buf, BUFFER_SIZE);
		nombre_trouve = atoi(buf);
		while (nombre_trouve <= 0 || nombre_trouve >= 100)
		{
			write(1, "\033[0;31mvotre entree est incorrect reessaye : ", 44);
			read(0, buf, BUFFER_SIZE);
			nombre_trouve = atoi(buf);
		}
		if (nombre_trouve < nombre_mystere)
			write(1, "\033[1;31mC'est Plus, réessaye : \n", 31);
		else if (nombre_trouve > nombre_mystere)
			write(1, "\033[1;31mC'est Moins, réessaye : \n", 32);
		nb_coup++;
	}
	free (buf);
	printf("\033[0;32m\nbravo tu a trouver le nombre mystere en %i coup\n", nb_coup);
}

void	ft_lvl2()
{
	char	*buf;
	int		nombre_trouve;
	int		nb_coup;
	int		nombre_mystere;

	nb_coup = 0;
	nombre_trouve = 0;
	srand(time(NULL));
	nombre_mystere = (rand() % (1000 - 1 + 1)) + 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	write(1, "\033[0;32m\nBienvenue dans le niveau 2\nessaye de trouver le nombre mystere ! \nchoisie ton nombre : ", 96);
	while (nombre_trouve != nombre_mystere)
	{
		read(0, buf, BUFFER_SIZE);
		nombre_trouve = atoi(buf);
		while (nombre_trouve <= 0 || nombre_trouve >= 1000)
		{
			write(1, "\033[0;31mvotre entree est incorrect reessaye : ", 44);
			read(0, buf, BUFFER_SIZE);
			nombre_trouve = atoi(buf);
		}
		if (nombre_trouve < nombre_mystere)
			write(1, "\033[1;31mC'est Plus, réessaye : \n", 31);
		else if (nombre_trouve > nombre_mystere)
			write(1, "\033[1;31mC'est Moins, réessaye : \n", 32);
		nb_coup++;
	}
	free (buf);
	printf("\033[0;32m\nbravo tu a trouver le nombre mystere en %i coup\n", nb_coup);
}

void	ft_lvl3()
{
	char	*buf;
	int		nombre_trouve;
	int		nb_coup;
	int		nombre_mystere;

	nb_coup = 0;
	nombre_trouve = 0;
	srand(time(NULL));
	nombre_mystere = (rand() % (10000 - 1 + 1)) + 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	write(1, "\033[0;32m\nBienvenue dans le niveau 3\nessaye de trouver le nombre mystere ! \nchoisie ton nombre : ", 96);
	while (nombre_trouve != nombre_mystere)
	{
		read(0, buf, BUFFER_SIZE);
		nombre_trouve = atoi(buf);
		while (nombre_trouve <= 0 || nombre_trouve >= 10000)
		{
			write(1, "\033[0;31mvotre entree est incorrect reessaye : ", 44);
			read(0, buf, BUFFER_SIZE);
			nombre_trouve = atoi(buf);
		}
		if (nombre_trouve < nombre_mystere)
			write(1, "\033[1;31mC'est Plus, réessaye : \n", 31);
		else if (nombre_trouve > nombre_mystere)
			write(1, "\033[1;31mC'est Moins, réessaye : \n", 32);
		nb_coup++;
	}
	free (buf);
	printf("\033[0;32m\nbravo tu a trouver le nombre mystere en %i coup\n", nb_coup);
}