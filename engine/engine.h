
#ifndef ENGINE_H
# define ENGINE_H

# include <stdlib.h>
# include <unistd.h>
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
	t_err				err_code;
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
void	exit_game(t_context *ctx, t_err err_code, const char *detail);

/* setup */
void	map_init(t_map *map);
void	texture_init(t_texture_mapping *tx);
void	input_init(t_context *ctx);
void	action_init(t_context *ctx);
void	load_cub(t_context *ctx, const char *map_path);

/* cleanup */
void	free_map(t_map *map);
void	free_input_sys(t_input_system *input);
void	free_action_sys(t_action_system *action);
void	free_textures_sys(t_texture_mapping *textures);

#endif
