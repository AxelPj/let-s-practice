/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plus_ou_moins_v2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:18:26 by axelpeti          #+#    #+#             */
/*   Updated: 2024/12/17 15:16:12 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Plus_ou_moins_v2.h"

int	main(void)
{
	int		lvl;
	char	*buf;

	printf("\033[1;35m");
    printf("         ,---._                                                       ,-.----.                                  \n");
    printf("       .-- -.' \\                             ___                      \\    /  \\                                 \n");
    printf("       |    |   :                          ,--.'|_                    |   :    \\            ,--,                \n");
    printf("       :    ;   |         ,--,             |  | :,'                   |   |  .\\ :  __  ,-.,--.'|                \n");
    printf("       :        |       ,'_ /|   .--.--.   :  : ' :                   .   :  |: |,' ,'/ /||  |,     ,--,  ,--,  \n");
    printf("       |    :   :  .--. |  | :  /  /    '.;__,'  /     ,---.          |   |   \\ :'  | |' |`--'_     |'. \\/ .`|  \n");
    printf("       :         ,'_ /| :  . | |  :  /`./|  |   |     /     \\         |   : .   /|  |   ,',' ,'|    '  \\/  / ;  \n");
    printf("       |    ;   ||  ' | |  . . |  :  ;_  :__,'| :    /    /  |        ;   | |`-' '  :  /  '  | |     \\  \\.' /   \n");
    printf("   ___ l         |  | ' |  | |  \\  \\    `. '  : |__ .    ' / |        |   | ;    |  | '   |  | :      \\  ;  ;   \n");
    printf(" /    /\\    J   ::  | : ;  ; |   `----.   \\|  | '.'|'   ;   /|        :   ' |    ;  : |   '  : |__   / \\  \\  \\  \n");
    printf("/  ../  `..-    ,'  :  `--'   \\ /  /`--'  /;  :    ;'   |  / |        :   : :    |  , ;   |  | '.'|./__;   ;  \\ \n");
    printf("\\    \\         ; :  ,      .-./'--'.     / |  ,   / |   :    |        |   | :     ---'    ;  :    ;|   :/\\  \\ ; \n");
    printf(" \\    \\      ,'   `--`----'      `--'---'   ---`-'   \\   \\  /         `---'.|             |  ,   / `---'  `--`  \n");
    printf("  \"---....--'                                         `----'            `---`              ---`-'               \n");
    printf("\033[0m");
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (1)
	{
		write(1, "\033[0;32m\nChoisis ton niveau de difficulté :\n", 44);
		write(1, "1. Niveau Facile : Trouve un nombre entre 1 et 100\n", 51);
		write(1, "2. Niveau Moyen : Trouve un nombre entre 1 et 1000\n", 52);
		write(1, "3. Niveau Difficile : Trouve un nombre entre 1 et 10000\n", 57);
		write(1, "4. Pour quitter\n", 17);
		write(1, "Entrez le chiffre correspondant au niveau choisi : ", 51);
		read(0, buf, BUFFER_SIZE);
		lvl = atoi(buf);
		if (lvl == 4)
			break ;
		else if (lvl == 1)
			ft_lvl1();
		else if (lvl == 2)
			ft_lvl2();
		else if (lvl == 3)
			ft_lvl3();
		else 
			write(1, "\033[4;31m\nvotre entree est incorrect ", 35);
	}
	free (buf);
}
