
#include "engine.h"
#include "libft.h"

static void	context_init(t_context *ctx, i8 *map_path)
{
	ft_bzero(ctx, sizeof(t_context));
	ctx->game_state = MENU;
	if (!map_path)
		exit_game(NULL, ERR_USAGE, "[context_init]: invalid map path/filename");
	/* Stage 1: load everything from .cub file into ctx */
	load_cub(ctx, map_path);

	/* Stage 2: initialize subsystems using loaded data*/
	map_init(ctx);
	input_init(ctx);
	event_init(ctx);
	texture_init(ctx);
}

int	main(i32 argc, i8 *argv[])
{
	t_context	ctx;

	if (argc != 2)
		exit_game(NULL, ERR_USAGE, "expected: ./run <map_file>");
	context_init(&ctx, argv[1]);
	engine_runtime(&ctx);
	context_destroy(&ctx);
	return (0);
}
