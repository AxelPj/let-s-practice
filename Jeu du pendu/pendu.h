/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pendu.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:19:55 by axelpeti          #+#    #+#             */
/*   Updated: 2024/12/23 16:13:02 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PENDU_H
# define PENDU_H
# define RESET   "\033[0m"
# define ROUGE   "\033[31m"
# define VERT    "\033[32m"
# define BLEU    "\033[34m"
# define BLANC   "\033[37m"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <sys/ioctl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

int		ft_strlen(char *s);
void	*ft_calloc(int nmemb, int size);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*readline(int fd, char *stach);
char	*recoveraftern(char *stach);
char	*recoverbeforen(char *line);
char	*get_next_line(int fd);
char	*pick_word(int fd);
int		nb_word(int fd);
char	*hide(char *word);
void	print_title(void);
void	rules(void);
void	print_centered(char *str);
void	center_text(char *text);
char	*menu(void);
void	clear_screen();
void	move_cursor(int x, int y);
void	menu_game(int x);
#endif