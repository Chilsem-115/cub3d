
#ifndef UTILS_INTERNAL__H
# define UTILS_INTERNAL__H

# include <unistd.h>
# include <fcntl.h>
# include "engine.h"

/* identifier category */
typedef enum e_identifier
{
	ID_NONE = 0,
	ID_TEXTURE,
	ID_COLOR
}	t_identifier;

/* internal header parsing helper */
void	handle_line(t_context *ctx, i8 *line, t_header_state *st);

/* parse utils: defined in utils.c */
void	parse_header(t_context *ctx, i32 fd);
void	parse_map_block(t_context *ctx, i32 fd);

/* map-reading helper */


#endif
