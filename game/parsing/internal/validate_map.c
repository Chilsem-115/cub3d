
#include "parse_internal_.h"

/* check if walkable cell at (r,c) leaks to void / border */
static i32	cell_open(t_map *map, i32 r, i32 c)
{
	i8	*ln;
	i32	len;

	if (r <= 0 || r >= map->rows - 1)
		return (1);
	ln = map->map[r];
	len = (i32)ft_strlen(ln);
	if (c <= 0 || c >= len - 1)
		return (1);
	ln = map->map[r - 1];
	len = (i32)ft_strlen(ln);
	if (c >= len || ln[c] == ' ')
		return (1);
	ln = map->map[r + 1];
	len = (i32)ft_strlen(ln);
	if (c >= len || ln[c] == ' ')
		return (1);
	ln = map->map[r];
	if (ln[c - 1] == ' ' || ln[c + 1] == ' ')
		return (1);
	return (0);
}

static void	check_enclosure(t_context *ctx)
{
	t_map	*map;
	i32		row;
	i32		col;
	i8		ch;

	map = &ctx->world_map;
	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (map->map[row][col] && map->map[row][col] != '\n')
		{
			ch = map->map[row][col];
			if ((ch == '0' || is_player(ch)) && cell_open(map, row, col))
					exit_game(ctx, ERR_MAP_FORMAT, "[map]: map is not closed");
			col++;
		}
		row++;
	}
}

/* internal helper: map validation */
void	validate_map(t_context *ctx)
{
	check_allowed_chars(ctx);
	find_player(ctx);
	check_enclosure(ctx);
}
