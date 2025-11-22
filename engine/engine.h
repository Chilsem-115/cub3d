
#ifndef ENGINE_H
#define	ENGINE_H

# include "type.h"

typedef enum e_err
{
	ERR_NONE = 0,

	/* high level / user */
	ERR_USAGE,

	/* system level */
	ERR_SYS_ALLOC,
	ERR_SYS_IO,

	/* engine / content */
	ERR_MLX,
	ERR_MAP_FORMAT,
	ERR_INPUT_SETUP,
	ERR_ASSET_MISSING,
	ERR_UNKNOWN
}	t_err;

/* tells us if the game is running, paused, existed or didn't even start yet*/
typedef enum e_gstate
{
	NONE = 0,
	MENU,
	RUNNING,
	PAUSED,
	EXIT,
}	t_gstate;

/* a Singletone containing all game data/info */
typedef struct	s_context
{
	t_gstate			game_state;
	t_map				world_map;
	t_input_system		input;
	t_action_system		action;
	t_texture_mapping	textures;
}	t_context;

/* Functions */
t_err	engine_runtime(t_context *ctx);
t_err	engine_update(t_context *ctx, float delta_time);
t_err	engine_render(t_context *ctx);

/* error handling */
void	context_destroy(t_context *ctx);

#endif
