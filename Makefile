
CC = cc
CFLAGS = -Wall -Wextra -Werror

ENGINE_SRCS = engine/engine.c \

GAME_SRCS = game/main.c \


SRCS = $(ENGINE_SRCS) $(GAME_SRCS)

ENGINE_OBJS =


GAME_OBJS = 


# -------------------------------------------- #

all: $(NAME)
	$(MAKE) -C $(LIBFT_DIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LDFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run
