
#include "engine.h"
#include "libft.h"

static void	context_init(t_context *ctx, const char *map_path)
{
	ft_bzero(ctx, sizeof(t_context));
	ctx->game_state = MENU;
	if (!map_path)
		exit_game(NULL, ERR_USAGE, "[context_init]: invalid map path/filename");
	map_init(&ctx->world_map);
	texture_init(&ctx->textures);
	load_cub(ctx, map_path);
	input_init(ctx);
	action_init(ctx);
}

int	main(int argc, char **argv)
{
	t_context	ctx;

	if (argc != 2)
		exit_game(NULL, ERR_USAGE, "expected: ./run <map_file>");
	context_init(&ctx, argv[1]);
	engine_runtime(&ctx);
	context_destroy(&ctx);
	return (0);
}
