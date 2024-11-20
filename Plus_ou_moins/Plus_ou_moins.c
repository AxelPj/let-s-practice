/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plus_ou_moins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:31:45 by axelpeti          #+#    #+#             */
/*   Updated: 2024/11/20 12:04:33 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <time.h>
# include <stdio.h>
# include <stdlib.h>

int main(void) 
{
	int Nombre_trouve;
	int nb_coup;
	int Nombre_Mystere;

	nb_coup = 1;
	Nombre_trouve = 0;
	srand(time(NULL));
	Nombre_Mystere = (rand() % (100 - 1 + 1)) + 1;

	printf("Bienvenue dans le jeu du Plus ou moins\n");
	printf("Je vais tirer un chiffre au hasard entre 1 et 100, à toi de le deviner\n");
	while (1) 
	{
		printf("Devine le nombre : ");
		if (scanf("%d", &Nombre_trouve) != 1) // verifie que l'on donne bien un nombre
		{
			printf("Ce n'est pas un nombre valide. Essaie encore.\n");
			while (getchar() != '\n');  // Vide le buffer
		} 
		else
			break;
	}
	while (Nombre_trouve != Nombre_Mystere) 
	{
		nb_coup++;

		if (Nombre_trouve < Nombre_Mystere)
			printf("C'est Plus, réessaye\n");
		else
			printf("C'est Moins, réessaye\n");
		while (1) 
		{
			printf("Devine le nombre : ");
			if (scanf("%d", &Nombre_trouve) != 1) 
			{
				printf("Ce n'est pas un nombre valide. Essaie encore.\n");
				while (getchar() != '\n');
			} 
			else 
				break;
		}
	}
	printf("Bravo, tu as trouvé le nombre en %d coups\n", nb_coup);
	return 0;
}
