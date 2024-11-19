/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plus_ou_moins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:31:45 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/19 16:47:30 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <time.h>
# include <stdio.h>
# include <stdlib.h>

int main (void)
{
	int Nombre_trouve;
	int nb_coup;
	int Nombre_Mystere;

	nb_coup = 1;
	Nombre_trouve = 0;
	Nombre_Mystere = (rand() % (100 - 1 + 1)) + 1;
	printf("Bienvenue dans le jeu du Plus ou moins\nJe vais tirer un chiffre au hasard entre 1 et 100 a toi de le deviner\n");
	srand (time(NULL));
	printf("\ndevine le nombre : ");
	scanf("%i", &Nombre_trouve);
	while (Nombre_trouve != Nombre_Mystere)
	{
		if (Nombre_trouve < Nombre_Mystere)
		{
			printf("C'est Plus reesaye\n");
			scanf("%i", &Nombre_trouve);
			nb_coup++;
		}
		else if (Nombre_trouve > Nombre_Mystere)
		{
			printf("C'est Moins reesaye\n");                                     
			scanf("%i", &Nombre_trouve);
			nb_coup++;
		}
	}
	if (nb_coup >= 10)
    	printf("Tu as trouvé en %i coups. Mieux vaut tard que jamais !\n", nb_coup);
	printf("Bravo tu a trouve le nombre en %i coup\n", nb_coup);
	return (0);
}
