
#include "libft.h"
#include "parse_internal_.h"
#include "parse.h"

static i8	*check_missing_texture(t_context *ctx)
{
	static i8	msg[128];
	i32		missing;

	ft_bzero(msg, sizeof(msg));
	ft_strlcpy(msg, "[parse_header]: missing identifier(s):", sizeof(msg));
	missing = 0;
	if (!ctx->textures.no_path && ++missing)
		ft_strlcat(msg, " [NO]", sizeof(msg));
	if (!ctx->textures.so_path && ++missing)
		ft_strlcat(msg, " [SO]", sizeof(msg));
	if (!ctx->textures.we_path && ++missing)
		ft_strlcat(msg, " [WE]", sizeof(msg));
	if (!ctx->textures.ea_path && ++missing)
		ft_strlcat(msg, " [EA]", sizeof(msg));
	if (ctx->textures.floor_color == -1 && ++missing)
		ft_strlcat(msg, " [F]", sizeof(msg));
	if (ctx->textures.ceiling_color == -1 && ++missing)
		ft_strlcat(msg, " [C]", sizeof(msg));
	if (!missing)
		return (NULL);
	return (msg);
}

/* internal helper: texture/color validation */
void	validate_textures(t_context *ctx)
{
	i8	*err;

	err = check_missing_texture(ctx);
	if (err)
		exit_game(ctx, ERR_MAP_FORMAT, err);
}
