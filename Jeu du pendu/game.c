#include "pendu.h"

int main(void)
{
	int		fd;
	char	*words_to_find;
	char	*user;

	while (1)
	{
		clear_screen();
		print_title();
		user = menu();
		if (!user)
			return (-1);
		if (user[0] == '1' && user[1] == '\n')
		{
			clear_screen();
			fd = open("mots_pendu.txt", O_RDONLY);
			words_to_find = pick_word(fd);
			menu_game(my_strlen(words_to_find) * 10);
			free(words_to_find);
			
		}
		if (user[0] == '2' && user[1] == '\n')
		{
			clear_screen();
			
		}
		if (user[0] == '3' && user[1] == '\n')
		{
			free(user);
			clear_screen();
			return (0);
		}
		free(user);
	}
}