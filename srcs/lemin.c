#include "lemin.h"

int			check_weight_is_define(t_listrooms *current)
{
	t_listrooms		*tmp;

	tmp = current;
	ft_putstr("TMP\n");
	// ft_putstr(tmp->room.name);
	while (tmp)
	{
		if (tmp->room.start == 0)
		{
			if (tmp->room.weight == 0)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void		set_weight(t_lemin *l, t_listrooms *currentlink, int prev_weight)
{
	while (currentlink)
	{
		if (currentlink->room.weight != 0 || currentlink->room.start == 1)
			set_weight(l, currentlink->next, prev_weight);
		else
		{
			currentlink->room.weight = prev_weight - 1;
			ft_putstr(currentlink->room.name);
			ft_putstr("-");
			ft_putnbr(currentlink->room.weight);
			ft_putstr("\n");
			if (check_weight_is_define(currentlink->room.linkrooms) == 1)
			{
				ft_putstr("RETURN\n");
				return ;
			}
			else
				set_weight(l, currentlink->room.linkrooms, prev_weight);
		}
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
	set_weight(l, tmp, end->weight);
	ft_putstr("\n\n\n");
}