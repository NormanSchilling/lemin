#include "lemin.h"

int			listrooms_size(t_listrooms *beginlist)
{
	t_listrooms		*node;
	int				i;

	i = 0;
	node = beginlist;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

void		listrooms_pushback(t_listrooms **beginlist,
	t_listrooms *newlist)
{
	t_listrooms	*tmp;

	tmp = *beginlist;
	if (tmp == NULL)
		*beginlist = newlist;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newlist;
	}
}

t_listrooms		*ft_listrooms_new(t_rooms *r)
{
	t_listrooms	*node;

	node = NULL;
	node = (t_listrooms *)malloc(sizeof(t_listrooms));
	if (node == NULL)
		return (NULL);
	else
	{
		node->room = r;
		node->next = NULL;
	}
	return (node);
}

void			handle_listrooms(t_lemin *l, char *line, char *prev)
{
	t_rooms		*r;
	char		**room_infos;

	r = (t_rooms *)malloc(sizeof(t_rooms));
	room_infos = ft_strsplit(line, ' ');
	r->name = room_infos[0];
	r->x = ft_atoi(room_infos[1]);
	r->y = ft_atoi(room_infos[2]);
	r->start = 0;
	r->end = 0;
	r->ant = 0;
	r->weight = -1;
	r->linkrooms = NULL;
	if (ft_strcmp("##start", prev) == 0)
	{
		r->ant = l->number_ant;
		r->start = 1;
	}
	if (ft_strcmp("##end", prev) == 0)
		r->end = 1;
	listrooms_pushback(&(l->listrooms), ft_listrooms_new(r));
}