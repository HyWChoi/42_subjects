#ifndef SO_LONG_VAILD_CHECK_H
# define SO_LONG_VAILD_CHECK_H
# include "so_long_init_map.h"

t_boolean	check_rectangular_map(t_map *map);
t_boolean	check_wrrapped_by_wall(t_map *map);
t_boolean	check_vaild_elem_in_map(t_map *map);
t_boolean	is_possible_to_go(t_map *map, t_coordinate *loc);

#endif
