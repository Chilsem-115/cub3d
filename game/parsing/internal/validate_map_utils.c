
#include "parse_utils_.h"

/* allowed map keys */
static i32	is_map_key(i8 c)
{
	return (c == '0' || c == '1'
		|| c == ' ' || c == 'N'
		|| c == 'S' || c == 'E'
		|| c == 'W');
}

static i32	is_player(i8 c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

/* pass 2: exactly one player, and set spawn */
static i32	count_players_number(t_context *ctx)
{
	t_map	*map;
	i32		r;
	i32		c;
	i32		count;

	map = &ctx->world_map;
	count = 0;
	r = 0;
	while (r < map->rows)
	{
		c = 0;
		while (map->map[r][c] && map->map[r][c] != '\n')
		{
			if (is_player(map->map[r][c]))
			{
				map->player_spawn.x = (float)c + 0.5f;
				map->player_spawn.y = (float)r + 0.5f;
				count++;
			}
			c++;
		}
		r++;
	}
	return (count);
}

void	check_allowed_chars(t_context *ctx)
{
	t_map	*map;
	i32		r;
	i32		c;
	i8		ch;

	map = &ctx->world_map;
	r = 0;
	while (r < map->rows)
	{
		c = 0;
		while (map->map[r][c] && map->map[r][c] != '\n')
		{
			ch = map->map[r][c];
			if (!is_map_key(ch))
				exit_game(ctx, ERR_MAP_FORMAT, "[map]: invalid character");
			c++;
		}
		r++;
	}
}

void	find_player(t_context *ctx)
{
	i32	count;

	count = count_players_number(ctx);
	if (count == 0)
		exit_game(ctx, ERR_MAP_FORMAT, "[map]: no player");
	if (count > 1)
		exit_game(ctx, ERR_MAP_FORMAT, "[map]: multiple players");
}
