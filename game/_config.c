
#include "engine.h"
#include "utils.h"

void	input_init(t_context *ctx)
{
}

void	action_init(t_context *ctx)
{
}

void	texture_init(t_texture_mapping *tx)
{
	tx->no_path = NULL;
	tx->so_path = NULL;
	tx->we_path = NULL;
	tx->ea_path = NULL;
	tx->floor_color = -1;
	tx->ceiling_color = -1;
	tx->no_img = NULL;
	tx->so_img = NULL;
	tx->we_img = NULL;
	tx->ea_img = NULL;
	tx->tex_w = 0;
	tx->tex_h = 0;
}

void	map_init(t_map *map)
{
	if (!map)
		return ;
	ft_bzero(map, sizeof(t_map));
	map->tile_size = 64;   /* or whatever default you want */
}

void	load_cub(t_context *ctx, i8 *map_path)
{
	i32	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_game(ctx, ERR_SYS_IO, "[context_init::load_cub]: open() failed");
	parse_header(ctx, fd);
	parse_map_block(ctx, fd);
	close(fd);
}
