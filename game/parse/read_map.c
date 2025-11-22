
#include "utils_internal_.h"
#include "libft.h"

static i8	**alloc_map_buffer(t_context *ctx, i32 cap)
{
	i8	**buf;

	buf = (i8 **)malloc(sizeof(i8 *) * cap);
	if (!buf)
		exit_game(ctx, ERR_SYS_ALLOC, "[parse_map]: malloc failed");
	return (buf);
}

static void	grow_map_buffer(t_context *ctx, i8 ***buf, i32 *cap, i32 rows)
{
	i8	**new;
	i32	i;

	*cap *= 2;
	new = alloc_map_buffer(ctx, *cap);
	i = 0;
	while (i < rows)
	{
		new[i] = (*buf)[i];
		i++;
	}
	free(*buf);
	*buf = new;
}

static void	store_first_line(t_context *ctx, i8 **buf, i8 *first)
{
	update_map_dims(ctx, first);
	buf[0] = first;
	ctx->world_map.rows = 1;
}

static void	store_remaining_lines(t_context *ctx, i8 ***buf,
				i32 *cap, i32 fd)
{
	i8	*line;

	while ((line = get_next_line(fd)))
	{
		if (ctx->world_map.rows + 1 >= *cap)
			grow_map_buffer(ctx, buf, cap, ctx->world_map.rows);
		update_map_dims(ctx, line);
		(*buf)[ctx->world_map.rows] = line;
		ctx->world_map.rows++;
	}
}

void	read_map_lines(t_context *ctx, i32 fd, i8 *first)
{
	i32	cap;
	i8	**buf;

	cap = 32;
	ctx->world_map.rows = 0;
	ctx->world_map.cols = 0;
	buf = alloc_map_buffer(ctx, cap);
	store_first_line(ctx, buf, first);
	store_remaining_lines(ctx, &buf, &cap, fd);
	buf[ctx->world_map.rows] = NULL;
	ctx->world_map.map = buf;
}
