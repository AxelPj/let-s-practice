/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plus_ou_moins_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:48:25 by axelpeti          #+#    #+#             */
/*   Updated: 2024/12/17 13:40:14 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Plus_ou_moins_v2.h"

int	ft_verifnb(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] < '0' && buf[i] > '9')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	*ft_calloc(int nmemb, int size)
{
	void			*tab;
	size_t			total_size;
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	total_size = (size_t)nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tab = malloc(total_size);
	if (!tab)
		return (NULL);
	ptr = (unsigned char *)tab;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (tab);
}
