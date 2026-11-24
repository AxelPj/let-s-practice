#ifndef PLUS_OU_MOINS_V2_H
# define PLUS_OU_MOINS_V2_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

void	*my_calloc(int nmemb, int size);
int		my_verifnb(char *buf);
void	my_lvl1();
void	my_lvl2();
void	my_lvl3();

#endif
