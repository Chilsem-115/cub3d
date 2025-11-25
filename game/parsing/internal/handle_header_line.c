
#include "parse_internal_.h"
#include "libft.h"

static t_identifier	get_identifier(const char *s)
{
	if (ft_strncmp(s, "NO ", 3) == 0)
		return (ID_TEXTURE);
	if (ft_strncmp(s, "SO ", 3) == 0)
		return (ID_TEXTURE);
	if (ft_strncmp(s, "WE ", 3) == 0)
		return (ID_TEXTURE);
	if (ft_strncmp(s, "EA ", 3) == 0)
		return (ID_TEXTURE);
	if (ft_strncmp(s, "F ", 2) == 0)
		return (ID_COLOR);
	if (ft_strncmp(s, "C ", 2) == 0)
		return (ID_COLOR);
	return (ID_NONE);
}

static void	strip_newline(char *s)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
}

/* Texture handling */
static void	handle_texture_line(t_context *ctx, i8 *line, i32 *found)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		set_texture_path(&ctx->textures.no_path, line + 3, ctx);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		set_texture_path(&ctx->textures.so_path, line + 3, ctx);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		set_texture_path(&ctx->textures.we_path, line + 3, ctx);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		set_texture_path(&ctx->textures.ea_path, line + 3, ctx);
	else
		exit_game(ctx, ERR_MAP_FORMAT,
			"[parse_header::handle_texture]: bad texture identifier");
	(*found)++;
}

/* Color handling */
static void	handle_color_line(t_context *ctx, i8 *line, i32 *found)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		ctx->textures.floor_color = parse_rgb(line + 2, ctx);
	else if (ft_strncmp(line, "C ", 2) == 0)
		ctx->textures.ceiling_color = parse_rgb(line + 2, ctx);
	else
		exit_game(ctx, ERR_MAP_FORMAT,
			"[parse_header::handle_color]: bad color identifier");
	(*found)++;
}

void	handle_header_line(t_context *ctx, i8 *line, i32 *found)
{
	t_identifier	id;

	strip_newline(line);
	id = get_identifier(line);
	if (id == ID_TEXTURE)
		handle_texture_line(ctx, line, found);
	else if (id == ID_COLOR)
		handle_color_line(ctx, line, found);
	else
	{
		free(line);
		validate_textures(ctx);
		exit_game(ctx, ERR_MAP_FORMAT,
			"[parse_header::handle_line]: invalid identifier line");
	}
}
