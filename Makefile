
NAME := cub3D
CC := cc
CFLAGS := -Wall -Wextra -Werror
export CCACHE_DISABLE := 1

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

SRCS := \
	engine/engine.c \
	engine/memory/comp_free.c \
	game/_config.c \
	game/clean_up.c \
	game/main.c \
	game/parsing/parse.c \
	game/parsing/internal/handle_header_line.c \
	game/parsing/internal/parse_utils.c \
	game/parsing/internal/read_map.c \
	game/parsing/internal/read_map_utils.c \
	game/parsing/internal/validate_map.c \
	game/parsing/internal/validate_map_utils.c \
	game/parsing/internal/validate_textures.c

OBJDIR := obj
OBJS := $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

INCLUDES := \
	-Iengine \
	-Igame \
	-Igame/parsing \
	-Igame/parsing/internal \
	-I$(LIBFT_DIR)

MAP ?= maps/backrooms.cub

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME) $(MAP)

.PHONY: all clean fclean re run
