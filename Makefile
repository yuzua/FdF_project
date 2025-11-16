NAME		=	fdf

# Sources
SRCS		=	main.c \
				draw.c \
				read_file.c \
				matrix.c \
				transform.c \
				utils.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c
OBJS		=	$(SRCS:.c=.o)

# Compiler / Flags
CC			=	cc
CFLAGS		+=	-Wall -Wextra -Werror -I get_next_line -I libft

# Libraries
LIBX_FLAGS	=	-L. -lmlx_Linux -lXext -lX11
LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBS		=	-L$(LIBFT_DIR) -lft $(LIBX_FLAGS) -lm

# Rules
all:		$(LIBFT) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

clean:
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
