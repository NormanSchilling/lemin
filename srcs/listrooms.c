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

t_listrooms		*ft_listrooms_new(t_rooms r)
{
	t_listrooms	*node;

	node = NULL;
	node = (t_listrooms *)malloc(sizeof(t_listrooms));
	if (node == NULL)
		return (NULL);
	else
	{
		ft_putstr("DEBUG listrooms_new\n");
		node->room.name = r.name;
		ft_putstr(node->room.name);
		ft_putstr(" => ");
		node->room.x = r.x;
		node->room.y = r.y;
		node->room.start = r.start;
		node->room.end = r.end;
		while (r.linkrooms)
		{
			node->room.linkrooms = r.linkrooms;

			ft_putstr(node->room.linkrooms->room.name);
			ft_putstr(" ");
			r.linkrooms = r.linkrooms->next;
		}
		ft_putstr("\n");
		node->next = NULL;
	}
	return (node);
}

void			handle_listrooms(t_lemin *l, char *line, char *prev)
{
	t_rooms		r;
	char		**room_infos;

	room_infos = ft_strsplit(line, ' ');
	r.name = room_infos[0];
	r.x = ft_atoi(room_infos[1]);
	r.y = ft_atoi(room_infos[2]);
	r.start = 0;
	r.end = 0;
	r.ant = 0;
	r.weight = 0;
	r.linkrooms = NULL;
	if (ft_strcmp("##start", prev) == 0)
	{
		r.ant = l->number_ant;
		r.start = 1;
	}
	if (ft_strcmp("##end", prev) == 0)
		r.end = 1;
	listrooms_pushback(&(l->listrooms), ft_listrooms_new(r));
}