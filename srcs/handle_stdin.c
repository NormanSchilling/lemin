#include "lemin.h"

int		check_rooms(char *line)
{
	char	**room_infos;

	room_infos = ft_strsplit(line, ' ');
	if (room_infos[3])
		return (1);
	if (room_infos[0] && room_infos[1] && room_infos[2])
	{
		if (room_infos[0][0] == 'L' || error_number(room_infos[1])
			|| error_number(room_infos[2]))
			return (1);
	}
	else
		return (1);
	return (0);
}

int		check_tube(char *line)
{
	char	**tube_infos;

	tube_infos = ft_strsplit(line, '-');
	if (tube_infos[2])
		return (1);
	if (tube_infos[0] && tube_infos[1])
		return (0);
	else
		return (1);
	return (0);
}

int		error_number(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	check_stdin(t_lemin *l, char *line, char *prev, int i)
{
	if (i == 0)
	{
		if (error_number(line))
		{
			ft_putstr("ERROR");
			exit(0);
		}
		else
			l->number_ant = ft_atoi(line);
	}
	else if (i > 0)
	{
		if (check_rooms(line) && check_tube(line))
		{
			ft_putstr("ERROR");
			exit(0);
		}
		else
		{
			if (check_rooms(line) == 0)
				handle_listrooms(l, line, prev);
			if (check_tube(line) == 0)
				handle_listtubes(l, line);
		}
	}
}

void	read_stdin(t_lemin *l)
{
	int				i;
	char			*line;
	char			*prev;

	i = 0;
	line = NULL;
	prev = NULL;
	l->listrooms = NULL;
	l->listtubes = NULL;
	while (get_next_line(0, &line))
	{
		if (line[0] != '#')
		{
			check_stdin(l, line, prev, i);
			i++;
		}
		prev = line;
	}
	handle_stdout(l);
	link_rooms(l);
	define_rooms_weight(l);
	display_linkrooms(l);
}
