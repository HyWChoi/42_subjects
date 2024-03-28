#ifndef SO_LONG_VAILD_CHECK_H
# define SO_LONG_VAILD_CHECK_H
#include "so_long_find_path_BFS.h"

t_boolean	check_rectangular_map(t_map *map);
t_boolean	check_wrrapped_by_wall(t_map *map);
t_boolean	check_vaild_elem_in_map(t_map *map);
t_boolean	map_validation_check(t_map *map, char *file_name);
#endif
