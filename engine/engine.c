

void	engine_runtime(t_context ctx)
{
	int	running;

	running = 1;
	while (running)
	{
		engine_update(ctx);
		engine_render(ctx);
	}
}
