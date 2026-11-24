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
        free(t_node);
        free(element);
        return (NULL);
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

void	display_list(Element *element)
{
	T_node	*actuel;

	actuel = element->premier;
	while (actuel != NULL)
	{
		printf("%d -> ", actuel->content);
		actuel = actuel->next;
	}
	printf("NULL\n");
}

int main ()
{
	Element	*element;
	T_node	*tmp;

	element = init();
	if (element == NULL)
		return (1);
	create_node(element, 20);
	create_node(element, 30);
	display_list(element);
	while (element->premier != NULL)
	{
		tmp = element->premier;
		element->premier = tmp->next;
		free(tmp);
	}
	free(element);
	return (0);
}