#ifndef SO_LONG_INIT_MAPH
# define SO_LONG_INIT_MAPH
# include "so_long_utils.h"

t_map			*init_map(void);
t_map_element	*init_map_element(void);
void			init_player_loc(t_map *map, t_coordinate *player_loc);
void			set_map(t_map *map, char **map_str);
void			free_map(t_map *map);

#endif
