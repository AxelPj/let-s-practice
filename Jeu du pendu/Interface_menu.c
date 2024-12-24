/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interface_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:20:59 by axelpeti          #+#    #+#             */
/*   Updated: 2024/12/23 16:14:16 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pendu.h"
#include <string.h>

void	print_title()
{
	int	total_line;
	int	i;
    char *title_lines[] = { VERT
        "  ============================================================================================================================================ ",
        " ║ .----------------.  .----------------.  .-----------------. .----------------.  .----------------.  .----------------.  .-----------------.  ║",
        " ║ | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. | ║",
        " ║ | |  ____  ____  | || |      __      | || | ____  _____  | || |    ______    | || | ____    ____ | || |      __      | || | ____  _____  | | ║",
        " ║ | | |_   ||   _| | || |     /  \\     | || ||_   \\|_   _| | || |  .' ___  |   | || ||_   \\  /   _|| || |     /  \\     | || ||_   \\|_   _| | | ║",
        " ║ | |   | |__| |   | || |    / /\\ \\    | || |  |   \\ | |   | || | / .'   \\_|   | || |  |   \\/   |  | || |    / /\\ \\    | || |  |   \\ | |   | | ║",
        " ║ | |   |  __  |   | || |   / ____ \\   | || |  | |\\ \\| |   | || | | |    ____  | || |  | |\\  /| |  | || |   / ____ \\   | || |  | |\\ \\| |   | | ║",
        " ║ | |  _| |  | |_  | || | _/ /    \\ \\_ | || | _| |_\\   |_  | || | \\ `.___]  _| | || | _| |_\\/_| |_ | || | _/ /    \\ \\_ | || | _| |_\\   |_  | | ║",
        " ║ | | |____||____| | || ||____|  |____|| || ||_____|\\____| | || |  `._____.'   | || ||_____||_____|| || ||____|  |____|| || ||_____|\\____| | | ║",
        " ║ | |              | || |              | || |              | || |              | || |              | || |              | || |              | | ║",
        " ║ | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' | ║",
        " ║  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  ║",
        "============================================================================================================================================   "
    };

	total_line = sizeof(title_lines) / sizeof(title_lines[0]);
	i = 0;
	while (i < total_line)
	{
		center_text(title_lines[i]);
		i++;
	}
}


void move_cursor(int x, int y) 
{
    printf("\033[%d;%dH", y, x);  // Séquence ANSI pour déplacer le curseur
}

char    *menu(void)
{
    int total_lines;
    int i;
    char *choice;
    char *menu_lines[] = 
    {RESET
        "         __  __ __  _  _ _   _          ",
        "     |  \\/  | __| \\| | | | |         ",
        "     | |\\/| | _|| .` | |_| |         ",
        "     |_|  |_|___|_|\\_|\\___/          ",
        "===========================================    ",
        "║ 1.                                        ║",
        "║  ___ _____ _   ___ _____                  ║",
        "║ / __|_   _/_\\ | _ \\_   _|                 ║",
        "║ \\__ \\ | |/ _ \\|   / | |                   ║",
        "║ |___/ |_/_/ \\_\\_|_\\ |_|                   ║",
        "║                                           ║",
        "║ 2.                                        ║",
        "║   ___ ___ _____ _____ ___ _  _  ___ ___   ║",
        "║  / __| __|_   _|_   _|_ _| \\| |/ __/ __|  ║",
        "║  \\__ \\ _|  | |   | |  | || .` | (_ \\__ \\  ║",
        "║  |___/___| |_|   |_| |___|_|\\_|\\___|___/  ║",
        "║                                           ║",
        "║ 3.                                        ║",
        "║    _____  _____ _____                     ║",
        "║   | __\\ \\/ /_ _|_   _|                    ║",
        "║   | _| >  < | |  | |                      ║",
        "║   |___/_/\\_\\___| |_|                      ║",
        "║                                           ║ ",
        " ║===========================================║  ",
        "║                                           ║ ",
        "===========================================    ",
    };
    choice = malloc(BUFFER_SIZE + 1);
    total_lines = sizeof(menu_lines) / sizeof(menu_lines[0]);
	i = 0;
	while (i < total_lines)
	{
		center_text(menu_lines[i]);
		i++;
	}
    move_cursor(134, total_lines + 12); // position x (134) pour centrer
    printf("Entrez votre choix : ");
    fgets(choice, BUFFER_SIZE, stdin);
    return(choice);
}

/* void rules(void)
{
   print_centered(BLEU "\nBienvenue dans le Jeu du Pendu !\n" RESET);
    print_centered(BLEU "================================\n" RESET);
    print_centered("\n" RESET "Règles du jeu :\n");
    print_centered("1. Le but du jeu est de deviner un mot caché.\n");
    print_centered("2. À chaque tour, vous devez proposer une lettre.\n");
    print_centered("3. Si la lettre est dans le mot, elle sera révélée à ses positions.\n");
    print_centered("4. Si la lettre n'est pas dans le mot, une partie du dessin du pendu sera ajouté.\n");
    print_centered("5. Vous avez un nombre limité d'erreurs avant d'être complètement pendu.\n");
    print_centered("6. Si vous devinez toutes les lettres du mot avant d'atteindre le nombre maximal d'erreurs, vous gagnez !\n");
    print_centered("Le mot à deviner a un certain nombre de lettres. Bon jeu !\n");
} */


