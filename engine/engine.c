
#include "engine.h"

t_err	engine_runtime(t_context *ctx)
{
	i32		running;
	f32		delta_time;

	if (ctx->err_code != 0)
		return ;
	running = 1;
	while (running)
	{
		engine_update(ctx, delta_time);
		engine_render(ctx);
		if (running = 0)
			break ;
	}
}
