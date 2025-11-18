
#include "unistd.h"
#include "_config.h"

static void		verify(t_context *ctx)
{
	if (ctx.error_num != 0)
		return ;
}

t_map	prase_map(t_context *ctx, char *pathname)
{
	t_map	ret;
	i32		fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		ctx->error_num = FILE_OPEN_ERROR;
		return (NULL);
	}
	ret.map = parse_map(fd);
	close(fd);
	return (ret);
}
