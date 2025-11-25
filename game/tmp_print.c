#include "tmp_print.h"
#include "libft.h"

static void	print_header_content(const t_texture_mapping *tx)
{
	ft_printf("Header content:\n");
	ft_printf("  NO: %s\n", tx->no_path);
	ft_printf("  SO: %s\n", tx->so_path);
	ft_printf("  WE: %s\n", tx->we_path);
	ft_printf("  EA: %s\n", tx->ea_path);
	ft_printf("  Floor: 0x%06X\n", (u32)tx->floor_color);
	ft_printf("  Ceiling: 0x%06X\n", (u32)tx->ceiling_color);
}

static void	print_map_block(const t_map *map)
{
	i32	row;

	ft_printf("Map (%d rows x %d cols):\n", map->rows, map->cols);
	row = 0;
	while (row < map->rows && map->map && map->map[row])
	{
		ft_printf("%s", map->map[row]);
		row++;
	}
	if (map->rows == 0 || !map->map)
		ft_printf("[empty map]\n");
}

void	tmp_print(t_context *ctx)
{
	if (!ctx)
		return ;
	ft_printf("=== tmp_print ===\n");
	print_header_content(&ctx->textures);
	print_map_block(&ctx->world_map);
	ft_printf("=================\n");
}
