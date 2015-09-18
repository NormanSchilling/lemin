# include "../libft/libft.h"
# include "get_next_line.h"

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct				s_rooms t_rooms;
typedef struct				s_listrooms t_listrooms;

struct						s_rooms
{
	char					*name;
	int						x;
	int						y;
	int						start;
	int						end;
	int						weight;
	int						ant;
	t_listrooms				*linkrooms;
};

struct						s_listrooms
{
	t_rooms					room;
	t_listrooms				*next;
};

typedef struct				s_listtubes
{
	t_rooms					*room;
	t_rooms					*room2;
	struct s_listtubes		*next;
}							t_listtubes;

typedef struct				s_lemin
{
	int						number_ant;
	char					*line;
	char					*prev;
	t_listrooms				*listrooms;
	t_listtubes				*listtubes;
}							t_lemin;

int				check_rooms(char *line);
int				error_number(char *line);
void			check_stdin(t_lemin *l, char *line, char *prev, int i);
void			read_stdin(t_lemin *l);

int				listrooms_size(t_listrooms *beginlist);
void			listrooms_pushback(t_listrooms **beginlist,
	t_listrooms *newlist);
t_listrooms		*ft_listrooms_new(t_rooms r);
void			handle_listrooms(t_lemin *l, char *line, char *prev);

int				listtubes_size(t_listtubes *beginlist);
void		listtubes_pushback(t_listtubes **beginlist,
	t_listtubes *newlist);
t_listtubes		*ft_listtubes_new(t_lemin *l, char *name1, char *name2);
void			handle_listtubes(t_lemin *l, char *line);

void			display_rooms(t_lemin *l);
void			display_tubes(t_lemin *l);
void			display_start_end(t_lemin *l);
void			handle_stdout(t_lemin *l);

t_rooms			*get_room_start(t_lemin *l);
t_rooms			*get_room_end(t_lemin *l);
t_rooms			*get_room_by_name(t_lemin *l, char *name);
void			link_rooms(t_lemin *l);
void			display_linkrooms(t_lemin *l);

int				check_weight_is_define(t_listrooms *current);
void			set_weight(t_lemin *l, t_listrooms *currentlink, int prev_weight);
void			define_rooms_weight(t_lemin *l);