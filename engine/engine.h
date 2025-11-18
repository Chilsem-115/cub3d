
#ifndef ENGINE_H
#define	ENGINE_H

# include "type.h"

typedef enum	e_err
{
	NONE = 0,

	/* Invalid argument/allocation */
	INVALID_ARG,
	ALLOC_FAIL,
	MLX_CONNECTION_FAIL,
	WINDOW_CREATION_FAIL,
	BUFFER_CREATION_FAIL,

	/* File not found*/
	FILE_OPEN_ERROR,
	FILE_READ_ERROR,

	/* Invalid setup */
	INVALID_MAP,
	INVALID_INPUT,
	INVALID_TEXTURE,
	INVLAID_SFX,

	UNKNOWN
}	t_err;

typedef struct	s_context
{
	bool				game_state;
	t_map				world_map;
	t_input_system		input;
	t_event_system		events;
	t_audio_system		audio;
	t_texture_mapping	textures;
	t_err				err_code;
}	t_context;

/* Functions */
t_err	engine_runtime(t_context *ctx);
t_err	engine_update(t_context *ctx, float delta_time);
t_err	engine_render(t_context *ctx);

/* error handling */
void	context_destroy(t_context *ctx);

#endif
