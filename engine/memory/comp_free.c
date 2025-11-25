#include <stdlib.h>
#include "engine.h"

void	free_map(t_map *map)
{
	i32	i;

	if (!map || !map->map)
		return ;
	i = 0;
	while (i < map->rows && map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
	map->rows = 0;
	map->cols = 0;
}

void	free_input_sys(t_input_system *input)
{
	(void)input;
}

void	free_action_sys(t_action_system *action)
{
	(void)action;
}

void	free_textures_sys(t_texture_mapping *textures)
{
	if (!textures)
		return ;
	free(textures->no_path);
	free(textures->so_path);
	free(textures->we_path);
	free(textures->ea_path);
	textures->no_path = NULL;
	textures->so_path = NULL;
	textures->we_path = NULL;
	textures->ea_path = NULL;
}
