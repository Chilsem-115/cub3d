#include <stdlib.h>
#include "parse_internal_.h"
#include "libft.h"

static void	free_split(i8 **parts)
{
	i32	i;

	if (!parts)
		return ;
	i = 0;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
}

void	set_texture_path(i8 **dst, const i8 *src, t_context *ctx)
{
	i8	*trimmed;

	if (*dst)
		exit_game(ctx, ERR_MAP_FORMAT,
			"[parse_header]: duplicate texture identifier");
	trimmed = ft_strtrim(src, " \t\n");
	if (!trimmed)
		exit_game(ctx, ERR_SYS_ALLOC, "[parse_header]: malloc failed");
	*dst = trimmed;
}

static i32	parse_component(const i8 *s, t_context *ctx)
{
	i32	value;

	if (!s || *s == '\0')
		exit_game(ctx, ERR_MAP_FORMAT, "[parse_header]: empty color value");
	value = ft_atoi((char *)s);
	if (value < 0 || value > 255)
		exit_game(ctx, ERR_MAP_FORMAT, "[parse_header]: color out of range");
	return (value);
}

i32	parse_rgb(const i8 *s, t_context *ctx)
{
	i8	**parts;
	i32	rgb;
	i32	r;
	i32	g;
	i32	b;

	parts = ft_split(s, ',');
	if (!parts)
		exit_game(ctx, ERR_SYS_ALLOC, "[parse_header]: malloc failed");
	if (!parts[0] || !parts[1] || !parts[2] || parts[3])
	{
		free_split(parts);
		exit_game(ctx, ERR_MAP_FORMAT, "[parse_header]: invalid color format");
	}
	r = parse_component(parts[0], ctx);
	g = parse_component(parts[1], ctx);
	b = parse_component(parts[2], ctx);
	free_split(parts);
	rgb = (r << 16) | (g << 8) | b;
	return (rgb);
}
