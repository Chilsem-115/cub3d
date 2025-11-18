
#include "engine.h"

void	context_destroy(t_context *ctx)
{
	free_map(ctx->world_map);
	free_input_sys(ctx->input);
	free_events_sys(ctx->events);
	free_audio_sys(ctx->audio);
	free_textures_sys(ctx->textures);
}

void	handle_error(t_err error)
{
	if ()
	{
		//condition;
	}
	else if()
	{
		//condition;
	}
	else if()
	{
		//condition;
	}
	else if()
	{
		//condition;
	}
	else if()
	{
		//condition;
	}
	else if()
	{
		//condition;
	}
}
