
#include "libft.h"
#include "parse_internal_.h"
#include "parse.h"

/* internal helper: check if a line is only spaces/tabs/newlines */
static i32	is_line_empty(const i8 *s)
{
	i32	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/* internal helper: verify all required textures / colors are set */
static void	validate_textures(t_context *ctx)
{
	if (!ctx->textures.no_path)
		exit_game(ctx, ERR_MAP_FORMAT, "missing identifier: NO");
	if (!ctx->textures.so_path)
		exit_game(ctx, ERR_MAP_FORMAT, "missing identifier: SO");
	if (!ctx->textures.we_path)
		exit_game(ctx, ERR_MAP_FORMAT, "missing identifier: WE");
	if (!ctx->textures.ea_path)
		exit_game(ctx, ERR_MAP_FORMAT, "missing identifier: EA");
	if (ctx->textures.floor_color == -1)
		exit_game(ctx, ERR_MAP_FORMAT, "missing identifier: F");
	if (ctx->textures.ceiling_color == -1)
		exit_game(ctx, ERR_MAP_FORMAT, "missing identifier: C");
}

/*
** parse_header:
**  - reads lines with get_next_line
**  - skips empty lines
**  - forwards each non-empty line to handle_line(ctx, line, &found)
**  - stops when all 6 identifiers (NO,SO,WE,EA,F,C) are found
**  - throws an error and exits if EOF is reached before finding all 6
*/
void	parse_header(t_context *ctx, i32 fd)
{
	i8	*line;
	i32	found;

	found = 0;
	while (found < 6)
	{
		line = get_next_line(fd);
		if (!line)
			exit_game(ctx, ERR_MAP_FORMAT,
				"[parse_header]: unexpected EOF while reading header");
		if (is_line_empty(line))
		{
			free(line);
			continue ;
		}
		handle_line(ctx, line, &found);
		free(line);
	}
	validate_textures(ctx);
}

/*
** parse_map:
**  - reads lines with get_next_line
**  - skips empty lines
**  - grab the entire map from the file
**	- checks if the map is valid
**	- throws an error is the map is invalid
*/
void	parse_map_block(t_context *ctx, i32 fd)
{
	i8	*line;

	line = NULL;
	while ((line = get_next_line(fd)))
	{
		if (!is_line_empty(line))
			break ;
		free(line);
	}
	if (!line)
		exit_game(ctx, ERR_MAP_FORMAT, "[parse_map]: no map found");
	read_map_lines(ctx, fd, line);
	validate_map(ctx);
}
