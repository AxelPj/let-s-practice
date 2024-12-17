/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plus_ou_moins_v2.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:19:55 by axelpeti          #+#    #+#             */
/*   Updated: 2024/12/17 14:05:50 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLUS_OU_MOINS_V2_H
# define PLUS_OU_MOINS_V2_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void	*ft_calloc(int nmemb, int size);
int		ft_verifnb(char *buf);
void	ft_lvl1();
void	ft_lvl2();
void	ft_lvl3();

#endif