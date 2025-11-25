
#include "parse_internal_.h"
#include "libft.h"

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
