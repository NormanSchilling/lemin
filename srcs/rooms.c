#include "lemin.h"

t_rooms		get_room_start(t_lemin *l)
{
	t_listrooms		*tmp;
	t_rooms			start;

	tmp = l->listrooms;
	start = tmp->room;
	while (tmp)
	{
		if (tmp->room.start == 1)
			start = tmp->room;
		tmp = tmp->next;
	}
	return (start);
}

t_rooms		get_room_end(t_lemin *l)
{
	t_listrooms		*tmp;
	t_rooms			end;

	tmp = l->listrooms;
	end = tmp->room;
	while (tmp)
	{
		if (tmp->room.end == 1)
			end = tmp->room;
		tmp = tmp->next;
	}
	return (end);
}

t_rooms		get_room_by_name(t_lemin *l, char *name)
{
	t_listrooms		*tmp;
	t_rooms			room;

	tmp = l->listrooms;
	room = tmp->room;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->room.name) == 0)
			room = tmp->room;
		tmp = tmp->next;
	}
	return (room);
}