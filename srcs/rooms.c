#include "lemin.h"

t_rooms		*get_room_start(t_lemin *l)
{
	t_listrooms		*tmp;
	t_rooms			*start;

	tmp = l->listrooms;
	start = &(tmp->room);
	while (tmp)
	{
		if (tmp->room.start == 1)
			start = &(tmp->room);
		tmp = tmp->next;
	}
	return (start);
}

t_rooms		*get_room_end(t_lemin *l)
{
	t_listrooms		*tmp;
	t_rooms			*end;

	tmp = l->listrooms;
	end = &(tmp->room);
	while (tmp)
	{
		if (tmp->room.end == 1)
			end = &(tmp->room);
		tmp = tmp->next;
	}
	return (end);
}

t_rooms		*get_room_by_name(t_lemin *l, char *name)
{
	t_listrooms		*tmp;
	t_rooms			*room;

	tmp = l->listrooms;
	room = &(tmp->room);
	while (tmp)
	{
		if (ft_strcmp(name, tmp->room.name) == 0)
			room = &(tmp->room);
		tmp = tmp->next;
	}
	return (room);
}

void		link_rooms(t_lemin *l)
{
	t_listtubes		*tmp;

	tmp = l->listtubes;
	ft_putstr("LINKAGGGEE BITCH\n");
	while(tmp)
	{
		listrooms_pushback(&(tmp->room->linkrooms), ft_listrooms_new(*(tmp->room2)));
		listrooms_pushback(&(tmp->room2->linkrooms), ft_listrooms_new(*(tmp->room)));
		tmp = tmp->next;
	}
}

void		display_linkrooms(t_lemin *l)
{
	t_listrooms		*tmp;

	tmp = l->listrooms;
	while(tmp)
	{
		ft_putstr("\n-----------\n");
		ft_putstr(tmp->room.name);
		ft_putstr("-");
		ft_putnbr(tmp->room.weight);
		ft_putstr(" => ");
		while(tmp->room.linkrooms)
		{
			ft_putstr(tmp->room.linkrooms->room.name);
			ft_putstr("-");
			ft_putnbr(tmp->room.linkrooms->room.weight);
			ft_putstr(" ");
			tmp->room.linkrooms = tmp->room.linkrooms->next;
		}
		tmp = tmp->next;
	}
}