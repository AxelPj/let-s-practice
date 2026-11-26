#include "pendu.h"

int main(void)
{
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
			jeu();
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