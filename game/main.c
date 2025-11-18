
#include "engine.h"

static void	context_init(t_context *ctx)
{
	if (ctx->err_code != 0)
		return ;
	void	map_init(t_context *ctx);
	void	input_init(t_context *ctx);
	void	texture_init(t_context *ctx);
	// void	sound_init(t_context *ctx);
}

int	main(i32 argc, i8 **argv)
{
	t_context	ctx;
	if (argc != 2)
		return (err_handle(INVALID_ARG));
	context_init(&ctx, argv[1]);
	engine_runtime(&ctx);
	context_destroy(&ctx);
	handle_error(ctx.err_code);
	return (0);
}
