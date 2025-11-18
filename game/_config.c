
#include "engine.h"

void	map_init(t_context *ctx)
{
	ctx->world_map = parse_map();
	if (ctx->err_code)
		return ;
}

void	input_init(t_context *ctx)
{
}

void	texture_init(t_context *ctx)
{
}

// 
// void	sound_init(t_context *ctx)
// {
// }
// 
