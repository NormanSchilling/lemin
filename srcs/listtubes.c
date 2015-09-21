#include "lemin.h"

int			listtubes_size(t_listtubes *beginlist)
{
	t_listtubes		*node;
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

void		listtubes_pushback(t_listtubes **beginlist,
	t_listtubes *newlist)
{
	t_listtubes	*tmp;

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

t_listtubes		*ft_listtubes_new(t_lemin *l, char *name1, char *name2)
{
	t_listtubes	*node;

	node = NULL;
	node = (t_listtubes *)malloc(sizeof(t_listtubes));
	if (node == NULL)
		return (NULL);
	else
	{
		node->room = get_room_by_name(l, name1);
		node->room2 = get_room_by_name(l, name2);
		node->next = NULL;
	}
	return (node);
}


int				check_name_rooms(t_lemin *l, char *name)
{
	t_listrooms		*tmp;

	tmp = l->listrooms;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->room->name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void			handle_listtubes(t_lemin *l, char *line)
{
	char		**tubes_infos;

	tubes_infos = ft_strsplit(line, '-');

	if (check_name_rooms(l, tubes_infos[0]) == 0
		|| check_name_rooms(l, tubes_infos[1]) == 0)
	{
		ft_putstr("ERROR\n");
		exit(0);

	}

	listtubes_pushback(&(l->listtubes), ft_listtubes_new(
		l, tubes_infos[0], tubes_infos[1]));
}