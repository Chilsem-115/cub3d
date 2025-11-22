
#include "engine.h"
#include "libft.h"

static void	context_init(t_context *ctx, i8 *map_path)
{
	ft_bzero(ctx, sizeof(t_context));
	ctx->game_state = MENU;
	if (!map_path)
		exit_game(NULL, ERR_USAGE, "[context_init]: invalid map path/filename");
	/* Stage 1: initialize subsystems */
	map_init(&ctx->world_map);
	texture_init(&ctx->textures);

	/*
	 * Stage 1: fill in the data related to map and textures
	 * then verify that the data is correct
	 * if there is missing or invalid data, throw an error and exit
	 * */
	load_cub(ctx, map_path);

	/* Stage 3: set player actions */
	input_init(ctx);
	action_init(ctx);
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
