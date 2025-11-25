
#include <errno.h>
#include <string.h>
#include "engine.h"
#include "libft.h"

static const char	*err_tag(t_err err)
{
	if (err == ERR_USAGE)
		return ("USAGE");
	if (err == ERR_SYS_ALLOC)
		return ("ALLOC");
	if (err == ERR_SYS_IO)
		return ("IO");
	if (err == ERR_MLX)
		return ("MLX");
	if (err == ERR_MAP_FORMAT)
		return ("MAP");
	if (err == ERR_INPUT_SETUP)
		return ("INPUT");
	if (err == ERR_ASSET_MISSING)
		return ("ASSET");
	if (err == ERR_UNKNOWN)
		return ("UNKNOWN");
	return ("NONE");
}

static void	log_err(t_err err, const char *detail)
{
	const char	*tag;

	tag = err_tag(err);
	if (!tag)
		tag = "NONE";
	if (detail && *detail)
		ft_dprintf(2, "Error [%s] (code %d): %s\n", tag, (int)err, detail);
	else
		ft_dprintf(2, "Error [%s] (code %d): %s\n", tag, (int)err,
			"no additional information");
	if (err == ERR_SYS_IO)
		ft_dprintf(2, "  system: %s\n", strerror(errno));
}

void	context_destroy(t_context *ctx)
{
	if (!ctx)
		return ;
	free_map(&ctx->world_map);
	free_input_sys(&ctx->input);
	free_action_sys(&ctx->action);
	free_textures_sys(&ctx->textures);
}

void	exit_game(t_context *ctx, t_err err_code, const char *detail)
{
	get_next_line_clear();
	if (ctx)
	{
		ctx->err_code = err_code;
		ctx->game_state = EXIT;
		context_destroy(ctx);
	}
	log_err(err_code, detail);
	if (err_code == ERR_NONE)
		exit(0);
	exit(1);
}
