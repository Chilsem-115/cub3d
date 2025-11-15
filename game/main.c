
#include "_config.h"

int	main(void)
{
	t_context	ctx;

	if (context_init(&ctx))
		return (1);
	engine_runtime(&ctx);
	context_destroy(&ctx);
	return (0);
}
