#include "lemin.h"

int			check_weight_is_define(t_listrooms *current)
{
	t_listrooms		*tmp;

	tmp = current;
	ft_putstr("TMP\n");
	// ft_putstr(tmp->room.name);
	while (tmp)
	{
		if (tmp->room->start == 0)
		{
			if (tmp->room->weight == 0)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void		set_weight(t_lemin *l, t_listrooms *currentlink, int asign_weight)
{
	while (currentlink)
	{
		if (currentlink->room->start == 1 || currentlink->room->weight != 0)
		{
			currentlink = currentlink->next;
			continue ;
		}
		currentlink->room->weight = asign_weight ;
		set_weight(l, currentlink->room->linkrooms, currentlink->room->weight - 1);
		currentlink = currentlink->next;
	}
}


void		define_rooms_weight(t_lemin *l)
{
	t_rooms		*end;
	t_listrooms	*tmp;

	end = get_room_end(l);
	end->weight = listrooms_size(l->listrooms);
	tmp = end->linkrooms;
	set_weight(l, tmp, end->weight - 1);
}