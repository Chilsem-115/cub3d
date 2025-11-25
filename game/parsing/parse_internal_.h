
#ifndef PARSE_INTERNAL__H
# define PARSE_INTERNAL__H

# include <unistd.h>
# include <fcntl.h>
# include "engine.h"
# include "libft.h"

/* identifier category */
typedef enum e_identifier
{
	ID_NONE = 0,
	ID_TEXTURE,
	ID_COLOR
}	t_identifier;

/* header handling */
void	handle_header_line(t_context *ctx, i8 *line, i32 *found);
void	validate_textures(t_context *ctx);
void	set_texture_path(i8 **dst, const i8 *src, t_context *ctx);
i32		parse_rgb(const i8 *s, t_context *ctx);


/* map_block handling */
i8		**alloc_map_buffer(t_context *ctx, i32 cap);
void	store_first_line(t_context *ctx, i8 **buf, i8 *first);
void	store_remaining_lines(t_context *ctx, i8 ***buf, i32 *cap, i32 fd);
void	read_map_lines(t_context *ctx, i32 fd, i8 *first);

/* map validation */
void	check_allowed_chars(t_context *ctx);
void	find_player(t_context *ctx);
void	validate_map(t_context *ctx);
i32		is_player(i8 c);

#endif
