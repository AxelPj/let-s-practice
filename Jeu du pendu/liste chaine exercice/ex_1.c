/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelpeti <axelpeti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:42:55 by axelpeti          #+#    #+#             */
/*   Updated: 2025/01/15 15:30:53 by axelpeti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct T_node T_node;

struct T_node
{
	int content;
	T_node *next;
};

typedef struct Element Element;

struct Element
{
    T_node *premier;
};

Element *init()
{
	T_node *t_node = malloc(sizeof(*t_node));
	Element *element = malloc(sizeof(*element));
	
	if (t_node == NULL || element == NULL)
    {
        return ;
    }
	t_node->content = 10;
	t_node->next = NULL;
	element->premier = t_node;
	return(element);
}

void	create_node(Element *element, int nv_nb)
{
	T_node *new;
	new = malloc(sizeof(*new));
	if (!new)
	{
		return ;
	}
	new->content = nv_nb;
	new->next = element->premier;
	element->premier = new;
}

void display_list ()
int main ()
{
	
}