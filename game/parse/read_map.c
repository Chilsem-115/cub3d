
#include "parse_internal_.h"
#include "libft.h"

static void	grow_buffer(t_context *ctx, i8 ***buf, i32 *cap)
{
	i8	**new_buf;
	i32		i;

	*cap *= 2;
	new_buf = malloc(sizeof(i8 *) * (*cap));
	if (!new_buf)
		exit_game(ctx, ERR_SYS_ALLOC, "[map]: malloc failed");

	i = 0;
	while ((*buf)[i])
	{
		new_buf[i] = (*buf)[i];
		i++;
	}
	new_buf[i] = NULL;

	free(*buf);
	*buf = new_buf;
}
static void	update_map_dims(t_context *ctx, const i8 *line)
{
	i32	len;

	len = (i32)ft_strlen(line);
	if (len > ctx->world_map.cols)
		ctx->world_map.cols = len;
}

void	read_map_lines(t_context *ctx, i32 fd, i8 *first_line)
{
	i8	**buf;
	i8	*line;
	i32		cap;

	cap = 32;
	ctx->world_map.rows = 0;
	ctx->world_map.cols = 0;
	buf = malloc(sizeof(i8 *) * cap);
	if (!buf)
		exit_game(ctx, ERR_SYS_ALLOC, "[map]: malloc failed");
	grow_buffer(ctx, &buf, &cap, ctx->world_map.rows);
	update_map_dims(ctx, first_line);
	buf[ctx->world_map.rows++] = first_line;
	while ((line = get_next_line(fd)))
	{
		grow_buffer(ctx, &buf, &cap, ctx->world_map.rows);
		update_map_dims(ctx, line);
		buf[ctx->world_map.rows++] = line;
	}
	buf[ctx->world_map.rows] = NULL;
	ctx->world_map.map = buf;
}
