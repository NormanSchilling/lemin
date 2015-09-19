#include "lemin.h"

void	display_rooms(t_lemin *l)
{
	t_listrooms		*tmp;

	tmp = l->listrooms;
	while (tmp)
	{
		if (tmp->room->start == 0 && tmp->room->end == 0)
		{
			ft_putstr(tmp->room->name);
			ft_putstr(" ");
			ft_putnbr(tmp->room->x);
			ft_putstr(" ");
			ft_putnbr(tmp->room->y);
			ft_putstr("\n");
		}
		tmp = tmp->next;
	}
}

void	display_tubes(t_lemin *l)
{
	t_listtubes		*tmp;

	tmp = l->listtubes;
	while (tmp)
	{
		ft_putstr(tmp->room->name);
		ft_putstr("-");
		ft_putstr(tmp->room2->name);
		ft_putstr("\n");
		tmp = tmp->next;
	}
}

void	display_start_end(t_lemin *l)
{
	t_rooms		*start;
	t_rooms		*end;

	start = get_room_start(l);
	ft_putstr("##start\n");
	ft_putstr(start->name);
	ft_putstr(" ");
	ft_putnbr(start->x);
	ft_putstr(" ");
	ft_putnbr(start->y);
	ft_putstr("\n");
	end = get_room_end(l);
	ft_putstr("##end\n");
	ft_putstr(end->name);
	ft_putstr(" ");
	ft_putnbr(end->x);
	ft_putstr(" ");
	ft_putnbr(end->y);
	ft_putstr("\n");
}

void	handle_stdout(t_lemin *l)
{
	ft_putnbr(l->number_ant);
	ft_putstr("\n");
	display_start_end(l);
	display_rooms(l);
	display_tubes(l);
	ft_putstr("\n");
}