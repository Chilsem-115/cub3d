
#ifndef PARSE_H
# define PARSE_H

# include "engine.h"

/* public functions */
void	parse_header(t_context *ctx, i32 fd);
void	parse_map_block(t_context *ctx, i32 fd);

#endif
