#include "lemin.h"

void		set_weight(t_lemin *l, t_listrooms *currentlink, t_rooms *parent, int asign_weight)
{
	while (currentlink)
	{
		if (currentlink->room == parent)
		{
			currentlink = currentlink->next;
			continue ;
		}
		if (currentlink->room->weight > parent->weight)
		{
			currentlink = currentlink->next;
			continue ;
		}
		currentlink->room->weight = asign_weight ;
		set_weight(l, currentlink->room->linkrooms, currentlink->room,
			currentlink->room->weight - 1);
		currentlink = currentlink->next;
	}
}

void		define_rooms_weight(t_lemin *l)
{
	t_rooms		*end;
	t_rooms		*start;
	t_listrooms	*tmp;

	end = get_room_end(l);
	start = get_room_start(l);
	end->weight = listrooms_size(l->listrooms);
	tmp = end->linkrooms;
	set_weight(l, tmp, end, end->weight - 1);
	if (start->weight == -1)
	{
		ft_putstr("ERROR");
		exit(0);
	}

}

t_rooms		*get_room_path(t_listrooms *current)
{
	t_listrooms		*tmp;
	t_rooms			*room_path;

	room_path = current->room;
	tmp = current->next;
	while (tmp)
	{
		if (tmp->room->weight >= room_path->weight
			&& (tmp->room->ant == 0 || tmp->room->end == 1))
			room_path = tmp->room;
		tmp = tmp->next;
	}
	return (room_path);
}

void		set_ant_path(int number_ant, t_rooms **ant_rooms)
{
	int			i;
	t_rooms		*path;

	i = 0;
	while (i < number_ant)
	{
		if (ant_rooms[i]->end == 0)
		{
			path = get_room_path(ant_rooms[i]->linkrooms);
			if ((path->ant == 0 && path->end == 0) || path->end == 1)
			{
				if (ant_rooms[i]->ant > 0)
					ant_rooms[i]->ant = ant_rooms[i]->ant - 1;
				path->ant = path->ant + 1;
				ant_rooms[i] = path;
				display_ant_path(path, i + 1);
			}
		}
		i++;
	}
}

void		lemin_loop(t_lemin *l)
{
	int			i;
	t_rooms		**ant_rooms;
	t_rooms		*end;

	ant_rooms = (t_rooms **)malloc(sizeof(t_rooms*) * l->number_ant);
	i = 0;
	while (i < l->number_ant)
	{
		ant_rooms[i] = get_room_start(l);
		i++;
	}
	end = get_room_end(l);
	while (end->ant != l->number_ant)
	{
		set_ant_path(l->number_ant, ant_rooms);
		ft_putstr("\n");
		i++;
	}
}