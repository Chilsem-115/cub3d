
#include "engine.h"
#include "utils.h"

void	map_init(t_context *ctx, i8 *map_path, int fd)
{
}

void	input_init(t_context *ctx)
{
}

void	event_init(t_context *ctx)
{
}

void	texture_init(t_context *ctx)
{
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
