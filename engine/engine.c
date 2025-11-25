
#include "engine.h"

t_err	engine_runtime(t_context *ctx)
{
	f32	delta_time;

	if (!ctx)
		return (ERR_UNKNOWN);
	if (ctx->err_code != ERR_NONE)
		return (ctx->err_code);
	ctx->game_state = RUNNING;
	delta_time = 0.0f;
	engine_update(ctx, delta_time);
	engine_render(ctx);
	ctx->game_state = EXIT;
	return (ERR_NONE);
}

t_err	engine_update(t_context *ctx, float delta_time)
{
	(void)ctx;
	(void)delta_time;
	return (ERR_NONE);
}

t_err	engine_render(t_context *ctx)
{
	(void)ctx;
	return (ERR_NONE);
}
