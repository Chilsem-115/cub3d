
#ifndef TYPE_H
#define TYPE_H

# include <stdint.h>

typedef int8_t		i8;
typedef uint8_t		u8;
typedef int16_t		i16;
typedef uint16_t	u16;
typedef int32_t		i32;
typedef uint32_t	u32;
typedef int64_t		i64;
typedef uint64_t	u64;

typedef struct	s_vec2
{
	f32	x;
	f32	y;
}	t_vec2;

typedef struct	s_map
{
	i8		**map;
	i32		rows;
	i32		cols;
	i32		tile_size;

	/* these values will later be pre-comuted in the initializer */
	i32		width_px; /* = cols * tile_size */
	i32		height_px; /* = rows * tile_size */

	/* this represent where player starts the game */
	t_vec2	player_spawn;
}	t_map;

typedef struct	s_input
{
}	t_input;

typedef struct	s_event_system
{
}	t_event_system;

typedef struct	s_audio_system
{
}	t_audio_system;

typedef struct s_texture_mapping
{
	i8	*no_path;
	i8	*so_path;
	i8	*we_path;
	i8	*ea_path;

	i32		floor_color;   /* e.g. 0xRRGGBB */
	i32		ceiling_color;

	/* later when MLX is ready: */
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	i32		tex_w;
	i32		tex_h;
}	t_texture_mapping;

#endif
