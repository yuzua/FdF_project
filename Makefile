NAME		=	fdf

# Sources
SRCS		=	main.c \
				draw.c \
				read_file.c \
				matrix.c \
				transform.c \
				utils.c
OBJS		=	$(SRCS:.c=.o)

# Compiler / Flags
CC			=	cc
CFLAGS		+=	-Wall -Wextra -Werror -I libft -I $(MLX_DIR)

# Libraries
MLX_DIR		?=	minilibx-linux
MLX_LIB		=	$(MLX_DIR)/libmlx_Linux.a
LIBX_FLAGS	=	-L$(MLX_DIR) -lmlx_Linux -lXext -lX11
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBS		=	-L$(LIBFT_DIR) -lft $(LIBX_FLAGS) -lm

# Rules
all:		$(LIBFT) $(MLX_LIB) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
			$(MAKE) -C $(MLX_DIR)

clean:
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean
			$(MAKE) -C $(MLX_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
