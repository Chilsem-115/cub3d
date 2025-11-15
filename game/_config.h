
#ifndef _CONFIG_H
#define _CONFIG_H

# include "engine.h"

typedef struct	s_context
{
	t_map				world_map;
	t_input_system		input;
	t_event_system		events;
	t_audio_system		audio;
	t_texture_mapping	textures;
}	t_context;

#endif
